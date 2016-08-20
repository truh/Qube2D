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


#ifndef __Q2D_STRINGENUMS_HPP__
#define __Q2D_STRINGENUMS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <string>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    StringEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \enum    TextEncoding
    /// \note    Big endian encodings not yet supported.
    ///
    ///////////////////////////////////////////////////////////
    enum TextEncoding
    {
        TENC_Invalid,   ///< None of the supported encodings
        TENC_Ascii,     ///< ASCII (0x0-0x7F) encoding
        TENC_Utf8,      ///< Default multibyte char encoding
        TENC_Utf16_BE,  ///< UTF-16 big endian encoding
        TENC_Utf16_LE,  ///< UTF-16 little endian encoding
        TENC_Utf32_BE,  ///< UTF-32 big endian encoding
        TENC_Utf32_LE   ///< UTF-32 little endian encoding
    };

    ///////////////////////////////////////////////////////////
    /// \file    StringEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \enum    ReplaceOptions
    ///
    ///////////////////////////////////////////////////////////
    enum ReplaceOptions
    {
        RO_OneEntry,    ///< Stops replacing after one entry
        RO_AllEntries   ///< Replaces all entries in the string
    };

    ///////////////////////////////////////////////////////////
    /// \file    StringEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \enum    EraseOptions
    ///
    ///////////////////////////////////////////////////////////
    enum EraseOptions
    {
        EO_OneEntry,    ///< Erases one entry only
        EO_AllEntries   ///< Erases all entries in the string
    };

    ///////////////////////////////////////////////////////////
    /// \file    StringEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \enum    SplitOptions
    ///
    ///////////////////////////////////////////////////////////
    enum SplitOptions
    {
        SO_KeepEmptyEntries,    ///< Keeps empty list entries
        SO_EraseEmptyEntries    ///< Erases empty list entries
    };
}


#endif  // __Q2D_STRINGENUMS_HPP__
