///////////////////////////////////////////////////////////////////////////////////
//
//
//                    ___        _            ____  ____
//                   / _ \ _   _| |__   ___  |___ \|  _ \
//                  | | | | | | | '_ \ / _ \   __) | | | |
//                  | |_| | |_| | |_) |  __/  / __/| |_| |
//                   \__\_\\__,_|_.__/ \___| |_____|____/
//
//
//
//  Easy to use cross-platform 2D game engine written in C++, using the OpenGL API.
//  Copyright (C) 2016 Nicolas Kogler (kogler.cml@hotmail.com)
//
//  This file is part of Qube2D.
//
//  Qube2D is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Qube2D is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with  Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Graphics/Text/TextErrors.hpp>
#include <Qube2D/Graphics/Text/Font.hpp>
#include <Qube2D/Debug/GLCheck.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H
#include FT_BITMAP_H
#include FT_IMAGE_H
#include FT_SIZES_H
#include <fstream>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \fn       Qube2D_Font_Atlas_By_Size -> inline
    /// \brief    Determines the atlas index by range checking.
    /// \returns  the atlas index.
    ///
    ///////////////////////////////////////////////////////////
    inline QUInt32 Qube2D_Font_Atlas_By_Size(QUInt32 size)
    {
        // Determines the atlas index by size
        if (size >= 10 && size <= 16)
            return 0;
        else if (size >= 18 && size <= 32)
            return 1;
        else if (size >= 34 && size <= 64)
            return 2;
        else if (size >= 66 && size <= 128)
            return 3;
        else
            return 4;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      Constructor
    ///
    ///////////////////////////////////////////////////////////
    Font::Font(FT_FaceRec_ *face)
        : Uncopyable(),
          m_Face(face),
          m_Stroker(NULL),
          m_Size(0u)
    {
        // Select encoding
        FT_Select_Charmap(face, FT_ENCODING_UNICODE);
        m_Textures = new Texture[5];
        m_Packer = new Atlas<2048>[5];
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      Destructor
    ///
    ///////////////////////////////////////////////////////////
    Font::~Font()
    {
        FT_Done_Face(m_Face);

        for (QUInt32 i = 0; i < 5; ++i)
            m_Textures[i].destroy();

        delete[] m_Textures;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      extract
    ///
    ///////////////////////////////////////////////////////////
    void Font::extract(QUInt32 size)
    {
        // Attempts to set the pixel size
        if (FT_Set_Pixel_Sizes(m_Face, 0, size))
        {
        #ifdef Q2D_DEBUG
            std::string n = std::to_string(size);
        #endif
            Q2DError(Q2D_FONT_ERROR_0, m_Face->family_name, n.c_str());
            return;
        }


        // Retrieves the bearing for this font size, if not already
        if (m_Bearings.find(size) == m_Bearings.end())
            if (!FT_Load_Char(m_Face, 'T', FT_LOAD_RENDER))
                m_Bearings.insert(std::make_pair(size, m_Face->glyph->bitmap_top));


        m_Size = size;
        m_Page = Qube2D_Font_Atlas_By_Size(size);


        // Determines whether the page for this size was already created
        if (m_Atlas.find(size) != m_Atlas.end())
            return;

        // Adds a new, empty page
        m_Atlas.insert(std::make_pair(size, GlyphAtlas()));


        // Determines whether a texture for this size range already exists
        // and creates one if that is not the case
        if (m_Textures[m_Page].id() == 0)
        {
            Texture &texture = m_Textures[m_Page];
            texture.create(2048, 2048, TextureFormat::FormatRED);
            texture.setHorizontalWrap(WrapMode::ClampToEdge);
            texture.setVerticalWrap(WrapMode::ClampToEdge);
            texture.setMinFilter(InterpolationMode::LinearInterpolation);
            texture.setMagFilter(InterpolationMode::LinearInterpolation);
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      setSize
    ///
    ///////////////////////////////////////////////////////////
    void Font::setSize(QUInt32 size)
    {
        extract(size);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      isCached -> const
    ///
    ///////////////////////////////////////////////////////////
    bool Font::isCached(QUInt32 cp, GlyphStyle type) const
    {
        // Determines whether 'cp' is already cached
        const GlyphAtlas &atlas = m_Atlas.at(m_Size);
        if (type == GlyphStyle::None)
            return (atlas.glyphs.find(cp) != atlas.glyphs.end());
        else if (type == GlyphStyle::Outline)
            return (atlas.glyphOut.find(cp) != atlas.glyphOut.end());
        else
            return (atlas.glyphBrd.find(cp) != atlas.glyphBrd.end());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      lineSpacing -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat Font::lineSpacing() const
    {
        return (m_Face->height/64.f)*(72.f/96.f);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      glyph -> const
    ///
    ///////////////////////////////////////////////////////////
    const Glyph &Font::glyph(QUInt32 cp, GlyphStyle type) const
    {
        const GlyphAtlas &atlas = m_Atlas.at(m_Size);
        if (type == GlyphStyle::None)
            return atlas.glyphs.at(cp);
        else if (type == GlyphStyle::Outline)
            return atlas.glyphOut.at(cp);
        else
            return atlas.glyphBrd.at(cp);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      texture -> const
    ///
    ///////////////////////////////////////////////////////////
    const Texture &Font::texture() const
    {
        return m_Textures[m_Page];
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      cacheGlyph
    ///
    ///////////////////////////////////////////////////////////
    void Font::cacheGlyph(QUInt32 cp, GlyphStyle type)
    {
        // Attempts to load and render a character
        if (FT_Load_Char(m_Face, cp, FT_LOAD_RENDER))
        {
        #ifdef Q2D_DEBUG
            std::string n = std::to_string(cp);
        #endif
            Q2DError(Q2D_FONT_ERROR_1, m_Face->family_name, n.c_str());
            return;
        }


        // Finds suitable space for this glyph
        QUInt8 *pixels = m_Face->glyph->bitmap.buffer;
        Texture &texture = m_Textures[m_Page];
        RectI space = m_Packer[m_Page].find(
                    m_Face->glyph->bitmap.width,
                    m_Face->glyph->bitmap.rows);

        if (!space.isValid() && pixels)
        {
        #ifdef Q2D_DEBUG
            std::string n = std::to_string(cp);
        #endif
            Q2DError(Q2D_FONT_ERROR_2, m_Face->family_name, n.c_str());
            return;
        }

        // Updates the pixel data, if not whitespace
        if (pixels != NULL)
            texture.updatePixels(
                        pixels,
                        space,
                        TextureFormat::FormatRED);

        // Initializes a new glyph structure and fills it
        Glyph glyph;
        glyph.texture_x = space.x() / 2048.f;
        glyph.texture_y = space.y() / 2048.f;
        glyph.texture_w = space.width() / 2048.f;
        glyph.texture_h = space.height() / 2048.f;
        glyph.glyph_w = space.width();
        glyph.glyph_h = space.height();
        glyph.bearing_x = m_Face->glyph->bitmap_left;
        glyph.bearing_y = m_Bearings.at(m_Size) - m_Face->glyph->bitmap_top;
        glyph.advance = m_Face->glyph->advance.x / 64.f;

        // Inserts a new entry (TODO: Stroker etc)
        GlyphAtlas &atlas = m_Atlas.at(m_Size);
        if (type == GlyphStyle::None)
            atlas.glyphs.insert(std::make_pair(cp, glyph));
        else if (type == GlyphStyle::Outline)
            atlas.glyphOut.insert(std::make_pair(cp, glyph));
        else
            atlas.glyphBrd.insert(std::make_pair(cp, glyph));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      cacheSubset
    ///
    ///////////////////////////////////////////////////////////
    void Font::cacheSubset(Subset set, GlyphStyle type)
    {
        QUInt32 min = 0, max = 0;

        if (set == Subset::Ascii) { min = 0x20; max = 0x7F; }
        else if (set == Subset::Latin) { min = 0x80; max = 0x24F; }
        else if (set == Subset::Greek) { min = 0x370; max = 0x3FF; }
        else if (set == Subset::Kryllic) { min = 0x400; max = 0x4FF; }
        else if (set == Subset::Hebrew) { min = 0x590; max = 0x5FF; }
        else if (set == Subset::Arabic) { min = 0x600; max = 0x6FF; }
        else if (set == Subset::Hiragana) { min = 0x3040; max = 0x309F; }
        else if (set == Subset::Katakana) { min = 0x30A0; max = 0x30FF; }
        for (QUInt32 i = min; i < max; ++i) { cacheGlyph(i, type); }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      measureString
    ///
    ///////////////////////////////////////////////////////////
    SizeF Font::measureString(const String &string,
                             GlyphStyle style,
                             QUInt32 size)
    {
        // First sets the size
        extract(size);


        // Then calculate glyph-by-glpyh
        QUInt32 length = string.length();
        QFloat line = lineSpacing();
        QFloat width = 0, height = size*(72.f/96.f), max = 0;


        for (QUInt32 i = 0; i < length; ++i)
        {
            char32_t c = string.at(i);
            if (c == '\n')
            {
                if (width > max)
                    max = width;

                height += line;
                width = 0;
                continue;
            }

            // Caches the glyph, if not already
            if (isCached(c, style))
                cacheGlyph(c, style);

            // Adds to the width
            width += glyph(c, style).advance;
        }

        if (width > max)
            max = width;

        return { max, height };
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      saveFontTexture
    ///
    ///////////////////////////////////////////////////////////
    void Font::saveFontTexture(const char *path)
    {
        // Retrieves the OpenGL texture's pixels
        char *buffer = new char[2048*2048];
        glCheck(glBindTexture(GL_TEXTURE_2D, m_Textures[m_Page].id()));
        glCheck(glGetTexImage(GL_TEXTURE_2D, GL_ZERO, GL_RED, GL_UNSIGNED_BYTE, buffer));

        // Writes buffer to the file
        std::fstream file;
        file.open(path, std::ios_base::out);
        file.write(buffer, 2048*2048);
        file.flush();
        file.close();

        // Frees buffer
        delete buffer;
    }
}
