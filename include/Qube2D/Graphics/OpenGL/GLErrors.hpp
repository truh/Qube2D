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


#ifndef __Q2D_GLERRORS_HPP__
#define __Q2D_GLERRORS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    GLErrors.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \brief   Defines error messages for 'OpenGL' classes.
    ///
    /// Q2D_SHADER_ERROR_0
    /// Q2D_TEXTURE_ERROR_0
    /// Q2D_TEXTURE_ERROR_1
    ///
    ///////////////////////////////////////////////////////////

    #define Q2D_SHADER_ERROR_0  "The given path is invalid. No such asset file exists.\n    Path: %0"
    #define Q2D_TEXTURE_ERROR_0 "The given path is invalid. No such asset file exists.\n    Path: %0"
    #define Q2D_TEXTURE_ERROR_1 "The given PNG image is invalid."

}


#endif  // __Q2D_GLERRORS_HPP__
