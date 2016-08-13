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
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


#ifndef __Q2D_ASSETERRORS_HPP__
#define __Q2D_ASSETERRORS_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    AssetErrors.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 28th, 2016
    /// \brief   Defines error messages for class 'Assets'.
    ///
    /// Q2D_ASSETS_ERROR_0
    /// Q2D_ASSETS_ERROR_1
    /// Q2D_ASSETS_ERROR_2
    ///
    ///////////////////////////////////////////////////////////

    #define Q2D_ASSETS_ERROR_0 "The given relative path is invalid. No such asset file exists.\n    Path: %0"
    #define Q2D_ASSETS_ERROR_1 "The file appears to be empty whereas it should not be for this function.\n    Path: %0"
    #define Q2D_ASSETS_ERROR_2 "The text file has an invalid encoding. Please check the BOM header.\n    Path: %0"
}


#endif  // __Q2D_ASSETERRORS_HPP__
