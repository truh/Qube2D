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


#ifndef __Q2D_DEBUG_HPP__
#define __Q2D_DEBUG_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <iostream>
#include <cassert>
#include <tuple>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Debug.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \brief   Includes useful headers for debugging.
    ///
    /// Also adds functions that can output detailed error
    /// messages that contain the file in which the error
    /// occured, in which line and what expression caused it.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Debug
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     printError
        /// \brief  Prints a detailed error message.
        /// \param  msg Contains the cause of the error
        /// \param  file Contains the file in question
        /// \param  func The function that threw the error
        /// \param  line Contains the line in question
        ///
        ///////////////////////////////////////////////////////////
        static void printError
        (
                int n,
                const char *msg,
                const char *file,
                const char *func,
                int line,
                ...
        );

    };


    ///////////////////////////////////////////////////////////
    /// \file    Debug.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \def     Q2DError
    /// \brief   A macro to print an error message.
    ///
    ///////////////////////////////////////////////////////////
    #define Q2DError(msg, ...)                                              \
    {                                                                       \
        Debug::printError                                                   \
        (                                                                   \
            std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value, \
            msg,                                                            \
            __FILE__,                                                       \
            __func__,                                                       \
            __LINE__,                                                       \
            __VA_ARGS__                                                     \
        );                                                                  \
    }
}


#endif  // __Q2D_DEBUG_HPP__
