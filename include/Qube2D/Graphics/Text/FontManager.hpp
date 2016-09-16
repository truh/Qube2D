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


#ifndef __Q2D_FONTMANAGER_HPP__
#define __Q2D_FONTMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Graphics/Text/Font.hpp>
#include <memory>
#include <vector>


///////////////////////////////////////////////////////////
// Forward declarations
//
///////////////////////////////////////////////////////////
struct FT_LibraryRec_;


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    FontManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \class   FontManager
    /// \brief   Initializes the FT libary and holds all fonts.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API FontManager
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn       loadFont
        /// \brief    Loads the TFF font at the specified path.
        /// \param    path Relative or absolute path to the font
        /// \returns  a pointer to a Qube2D::Font structure.
        /// \returns  NULL if font failed to load.
        ///
        ///////////////////////////////////////////////////////////
        static Font *loadFont(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn     unloadFont
        /// \brief  Unloads the given Qube2D::Font structure.
        /// \param  font Valid Qube2D::Font structure reference
        ///
        ///////////////////////////////////////////////////////////
        static void unloadFont(Font *&font);


    #ifdef __Q2D_LIBRARY__

        static bool initializeFT2();
        static void destroyFT2();

    #endif


    private:

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static FT_LibraryRec_ *m_Library;   ///< FT2 library struct
        static std::vector<Font *> m_Fonts; ///< Holds loaded fonts

    };
}


#endif  // __Q2D_FONTMANAGER_HPP__
