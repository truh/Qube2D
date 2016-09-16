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
#include <Qube2D/Graphics/Text/FontManager.hpp>
#include <Qube2D/Graphics/Text/TextErrors.hpp>
#include <Qube2D/Assets/Assets.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Static class member definitions
    //
    ///////////////////////////////////////////////////////////
    FT_Library FontManager::m_Library = NULL;
    std::vector<Font *> FontManager::m_Fonts;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \fn      loadFont
    ///
    ///////////////////////////////////////////////////////////
    Font *FontManager::loadFont(const char *path)
    {
        assert(path);
        assert(m_Library);


        // Determines whether the given path is relative or absolute
        // and converts the relative to an absolute eventually.
        std::string filePath = path;
        if (Assets::isRelative(path))
            filePath = Assets::makePath(path);

        // Loads a new font face
        FT_Face face;
        if (FT_New_Face(m_Library, filePath.c_str(), 0, &face))
        {
            Q2DError(Q2D_FONTMGR_ERROR_0, filePath.c_str());
            return NULL;
        }

        // Creates a new Qube2D::Font structure
        Font *font = new Font(face);
        m_Fonts.push_back(font);

        return font;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \fn      unloadFont
    ///
    ///////////////////////////////////////////////////////////
    void FontManager::unloadFont(Font *&font)
    {
        assert(font);


        // Searches for the pointer in the manager and removes it
        std::vector<Font *>::const_iterator i;
        if ((i = std::find(m_Fonts.begin(), m_Fonts.end(), font)) != m_Fonts.end())
            m_Fonts.erase(i);

        delete font;
        font = NULL;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \fn      initializeFT2
    ///
    ///////////////////////////////////////////////////////////
    bool FontManager::initializeFT2()
    {
        // Initializes the FreeType2 library
        if (FT_Init_FreeType(&m_Library))
        {
            Q2DErrorNoArg(Q2D_FONTMGR_ERROR_1);
            return false;
        }
        if (FT_Stroker_New(m_Library, &Font::m_Stroker))
        {
            Q2DErrorNoArg(Q2D_FONTMGR_ERROR_3);
            return false;
        }

        Font::m_LibRef = m_Library;
        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \fn      destroyFT2
    ///
    ///////////////////////////////////////////////////////////
    void FontManager::destroyFT2()
    {
        // Disposes of every font
        for (QUInt32 i = 0; i < m_Fonts.size(); ++i)
        {
            if (m_Fonts.at(i) != NULL)
                delete m_Fonts[i];
        }


        FT_Stroker_Done(Font::m_Stroker);

        // Frees the FreeType2 library
        if (FT_Done_FreeType(m_Library))
            Q2DErrorNoArg(Q2D_FONTMGR_ERROR_2);
    }
}
