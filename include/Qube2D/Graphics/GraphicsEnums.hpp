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


#ifndef __Q2D_GRAPHICSENUMS_HPP__
#define __Q2D_GRAPHICSENUMS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    GraphicsEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    ///
    ///////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////
    /// \enum   BlendMode
    /// \brief  Defines various blend modes supported by the
    ///         Qube2D fragment shaders.
    /// 
    ///////////////////////////////////////////////////////////
    enum class BlendMode : unsigned int
    {
        NoBlend     = 0,    ///< Does not perform blending
        Multiply    = 1,    ///< Multiplies pixel with blend color
        Screen      = 2,    ///< The opposite of Multiply
        Overlay     = 3,    ///< Combines Multiply and Screen
        Devide      = 4,    ///< Devides the corresponding color components
        Addition    = 5,    ///< Adds the corresponding color components
        Subtract    = 6,    ///< Subtracts the corresponding color components
        Difference  = 7,    ///< Same as Subtract, with positive values only
        Lighten     = 8,    ///< Chooses the lighter color
        Darken      = 9,    ///< Chooses the darker color
    };
}


#endif  // __Q2D_GRAPHICSENUMS_HPP__
