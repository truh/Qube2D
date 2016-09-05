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


#ifndef __Q2D_WINDOWENUMS_HPP__
#define __Q2D_WINDOWENUMS_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    WindowEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \enum    WindowPosition
    /// \brief   Defines several relative window positions.
    ///
    /// In order to define a pixel-perfect position, the value
    /// WindowPosition::Custom is required to be used.
    ///
    ///////////////////////////////////////////////////////////
    enum class WindowPosition
    {
        Custom,
        Center,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };


    ///////////////////////////////////////////////////////////
    /// \file    WindowEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \enum    WindowFlags
    /// \brief   Defines several window style flags.
    ///
    /// Using the OR operator '|', multiple window style flags
    /// can be combined.
    ///
    ///////////////////////////////////////////////////////////
    enum class WindowFlags : int
    {
        None        = 0x0000,
        Resizable   = 0x0001,
        Visible     = 0x0002,
        Decorated   = 0x0004,
        Focused     = 0x0008
    };


    ///////////////////////////////////////////////////////////
    /// \fn      OR operator
    /// \brief   Combines the two flags specified.
    /// \returns a combination of all the flags.
    ///
    ///////////////////////////////////////////////////////////
    inline static WindowFlags operator|(WindowFlags first, WindowFlags second)
    {
        return static_cast<WindowFlags>
        (
            static_cast<int>(first)  |
            static_cast<int>(second)
        );
    }

    ///////////////////////////////////////////////////////////
    /// \fn      OR assignment operator
    /// \brief   Combines the two flags and stores it in 'first'.
    /// \returns a combination of all the flags.
    ///
    ///////////////////////////////////////////////////////////
    inline static WindowFlags &operator|=(WindowFlags &first, WindowFlags appendix)
    {
        first = static_cast<WindowFlags>
        (
            static_cast<int>(first)  |
            static_cast<int>(appendix)
        );

        return first;
    }

    ///////////////////////////////////////////////////////////
    /// \fn      AND operator
    /// \brief   Extracts a bit out of the given value
    /// \returns a combination of all the flags.
    ///
    ///////////////////////////////////////////////////////////
    inline static int operator&(WindowFlags flags, WindowFlags bit)
    {
        return (static_cast<int>(flags) & static_cast<int>(bit));
    }
}


#endif  // __Q2D_WINDOWENUMS_HPP__
