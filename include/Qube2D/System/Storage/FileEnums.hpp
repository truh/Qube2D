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


#ifndef __Q2D_FILEENUMS_HPP__
#define __Q2D_FILEENUMS_HPP__


///////////////////////////////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    File.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \enum    FileAccess
    ///
    ///////////////////////////////////////////////////////////
    enum FileAccess
    {
        FA_Invalid      = -1,
        FA_Read         =  1,
        FA_Write        =  2,
        FA_ReadWrite    =  FA_Read|FA_Write
    };

    ///////////////////////////////////////////////////////////
    /// \file    File.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \enum    SeekDirection
    ///
    ///////////////////////////////////////////////////////////
    enum SeekDirection
    {
        SD_Invalid      = -1,
        SD_Begin        =  0,
        SD_End          =  1
    };


    ///////////////////////////////////////////////////////////
    /// \fn     OR operator
    /// \brief  Allows combining two Qube2D::FileAccess flags.
    ///
    ///////////////////////////////////////////////////////////
    inline FileAccess operator |(FileAccess first, FileAccess other)
    {
        return static_cast<FileAccess>
        (
               static_cast<QInt32>(first) |
               static_cast<QInt32>(other)
        );
    }
}


#endif  // __Q2D_FILEENUMS_HPP__
