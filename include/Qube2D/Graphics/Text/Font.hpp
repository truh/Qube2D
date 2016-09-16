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


#ifndef __Q2D_FONT_HPP__
#define __Q2D_FONT_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Uncopyable.hpp>
#include <Qube2D/System/Storage/Atlas.hpp>
#include <Qube2D/System/Localization/String.hpp>
#include <Qube2D/Graphics/Text/Glyph.hpp>
#include <Qube2D/Graphics/Text/TextEnums.hpp>
#include <Qube2D/Graphics/System/OpenGL/Texture.hpp>


///////////////////////////////////////////////////////////
// Forward declarations
//
///////////////////////////////////////////////////////////
struct FT_FaceRec_;
struct FT_StrokerRec_;
struct FT_LibraryRec_;


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Font.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \class   Font
    /// \brief   Loads, generates and caches glyphs.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Font : Uncopyable
    {

    public:

    // The Font class is largely private
    #ifdef __Q2D_LIBRARY__

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Initializes a new instance of Qube2D::Font.
        ///
        /// Loads the font from the given FreeType2 FontFace.
        ///
        ///////////////////////////////////////////////////////////
        Font(FT_FaceRec_ *face);

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor
        /// \brief  Disposes of the FreeType2 FontFace and more.
        ///
        ///////////////////////////////////////////////////////////
        ~Font();


        ///////////////////////////////////////////////////////////
        /// \fn     extract
        /// \brief  Extracts the glyphs of the specified size.
        /// \param  size Pixel size of the glyphs to extract
        ///
        ///////////////////////////////////////////////////////////
        void extract(QUInt32 size);

        ///////////////////////////////////////////////////////////
        /// \fn     setSize
        /// \brief  Specifies the size to use.
        /// \param  size Pixel size of the glyphs to use
        /// \note   Does not extract or generate anything.
        ///
        ///////////////////////////////////////////////////////////
        void setSize(QUInt32 size);

        ///////////////////////////////////////////////////////////
        /// \fn     setOutlineWidth
        /// \brief  Specifies the width for the outline, if any.
        /// \param  width Width of the outline, in pixels
        ///
        ///////////////////////////////////////////////////////////
        void setOutlineWidth(QFloat width);

        ///////////////////////////////////////////////////////////
        /// \fn       isCached -> const
        /// \brief    Determines whether a glyph is already cached.
        /// \param    cp Codepoint of the character to check for
        /// \param    style Style of the glyph
        /// \returns  TRUE if the character is already cached.
        ///
        ///////////////////////////////////////////////////////////
        bool isCached(QUInt32 cp, TextStyle style) const;

        ///////////////////////////////////////////////////////////
        /// \fn       lineSpacing -> const
        /// \brief    Retrieves the spacing between two lines.
        /// \returns  the spacing in pixels.
        ///
        ///////////////////////////////////////////////////////////
        QFloat lineSpacing() const;

        ///////////////////////////////////////////////////////////
        /// \fn       glyph -> const
        /// \brief    Retrieves the glyph of the given style.
        /// \param    cp Codepoint of the character to fetch
        /// \param    style Style of the glyph
        /// \returns  an outlined, bordered or regular glyph.
        ///
        ///////////////////////////////////////////////////////////
        const Glyph &glyph(QUInt32 cp, TextStyle style) const;

        ///////////////////////////////////////////////////////////
        /// \fn       texture -> const
        /// \brief    Retrieves the texture of the current size.
        /// \returns  the texture in charge of the current size.
        ///
        ///////////////////////////////////////////////////////////
        const Texture &texture() const;

        ///////////////////////////////////////////////////////////
        /// \fn     kerning -> const
        /// \brief  Retrieves the kerning of two characters.
        /// \param  prev Previous character
        /// \param  cur Current character
        ///
        ///////////////////////////////////////////////////////////
        QFloat kerning(QUInt32 prev, QUInt32 cur) const;


        ///////////////////////////////////////////////////////////
        /// \var    m_Stroker
        /// \brief  Is able to outline/inline glyphs.
        ///
        ///////////////////////////////////////////////////////////
        static FT_StrokerRec_ *m_Stroker;
        static FT_LibraryRec_ *m_LibRef;


    #endif

        ///////////////////////////////////////////////////////////
        /// \fn     cacheGlyph
        /// \brief  Caches one glyph of specified type.
        /// \param  cp Codepoint of the character to cache
        /// \param  style Style of the glyph
        ///
        ///////////////////////////////////////////////////////////
        void cacheGlyph(QUInt32 cp, TextStyle style);

        ///////////////////////////////////////////////////////////
        /// \fn     cacheSubset
        /// \brief  Caches a subset of unicode characters.
        /// \param  set Subset to cache
        /// \param  style Style of the glyph
        ///
        ///////////////////////////////////////////////////////////
        void cacheSubset(Subset set, TextStyle style);

        ///////////////////////////////////////////////////////////
        /// \fn       measureString
        /// \brief    Measures the width and height of a string.
        /// \param    string Qube2D::String to measure
        /// \param    style Style of the glyph
        /// \param    size Size of the glyphs in pixels
        /// \returns  the width and height, in pixels.
        ///
        ///////////////////////////////////////////////////////////
        SizeF measureString(const String &string,
                            TextStyle style,
                            QUInt32 size);

        ///////////////////////////////////////////////////////////
        /// \fn     saveFontTexture
        /// \brief  Saves the font texture for debugging purposes.
        /// \param  path File to save raw data to
        ///
        ///////////////////////////////////////////////////////////
        void saveFontTexture(const char *path);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        FT_FaceRec_ *m_Face;       ///< Holds the current font face
        Texture *m_Textures;       ///< OpenGL texture array
        Atlas<2048> *m_Packer;     ///< Packs glyphs into a texture
        QUInt32 m_Size;            ///< Currently active size
        QUInt32 m_Page;            ///< Currently active page
        QFloat m_OutlineWidth;     ///< Width of the outline
        std::map<QUInt32, GlyphAtlas> m_Atlas;
        std::map<QUInt32, QInt32> m_Bearings;

    };
}


#endif  // __Q2D_FONT_HPP__
