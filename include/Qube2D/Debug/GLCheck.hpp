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


#ifndef __Q2D_GLCHECK_HPP__
#define __Q2D_GLCHECK_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    GLCheck.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 18th, 2016
    /// \class   GLCheck
    /// \brief   Manages the function that checks for errors.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API GLCheck
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     check
        /// \brief  Determines whether the latest called OpenGL
        ///         function threw an error and outputs a message.
        ///
        /// \param  file File in which the causing expression is
        /// \param  line Line of the causing expression
        /// \param  expr The expression, as a string
        ///
        ///////////////////////////////////////////////////////////
        static void check(const char *file,
                          const long line,
                          const char *expr);

    };


    ///////////////////////////////////////////////////////////
    /// \file    GLCheck.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 18th, 2016
    /// \def     glCheck
    /// \brief   This macro should be used along with every
    ///          OpenGL function call in order to immediately
    ///          determine whether it threw an error.
    ///
    ///////////////////////////////////////////////////////////
    ///
#   ifndef NDEBUG
#       define glCheck(expr)  do { expr; GLCheck::check(__FILE__, __LINE__, #expr); } while(0)
#   else
#       define glCheck(expr) { expr; }
#   endif
}


#endif  // __Q2D_GLCHECK_HPP__
