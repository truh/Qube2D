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


#ifndef __Q2D_VARIANTENUMS_HPP__
#define __Q2D_VARIANTENUMS_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    VariantEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \enum    VariantType
    /// \brief   Holds all supported variant types.
    ///
    ///////////////////////////////////////////////////////////
    enum VariantType
    {
        VT_Invalid = -1,
        VT_Int8,
        VT_Int16,
        VT_Int32,
        VT_Int64,
        VT_Utf8,
        VT_Utf16,
        VT_Utf32,
        VT_PInt8,
        VT_PInt16,
        VT_PInt32,
        VT_PInt64,
        VT_Color,
        VT_GLColor,
        VT_Rect,
        VT_Point,
        VT_Size,
        VT_String,
        VT_Last = VT_String
    };
}


#endif  // __Q2D_VARIANTENUMS_HPP__
