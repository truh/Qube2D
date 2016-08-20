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


#ifndef __Q2D_MOUSE_HPP__
#define __Q2D_MOUSE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Input/Buttons.hpp>
#include <Qube2D/System/Structs/Point.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Mouse.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \class   Mouse
    /// \brief   Handles multi-button input.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Mouse
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn      isButtonDown
        /// \brief   Determines whether the given button is held.
        /// \param   button One of the QUBE_BUTTON values
        /// \returns true if the specified button is held.
        ///
        ///////////////////////////////////////////////////////////
        static bool isButtonDown(int button);

        ///////////////////////////////////////////////////////////
        /// \fn      isButtonReleased
        /// \brief   Determines whether the given button is released.
        /// \param   button One of the QUBE_BUTTON values
        /// \returns true if the specified button is released.
        ///
        ///////////////////////////////////////////////////////////
        static bool isButtonReleased(int button);

        ///////////////////////////////////////////////////////////
        /// \fn      cursorPos
        /// \brief   Retrieves the current cursor position.
        /// \returns the current cursor pos.
        ///
        ///////////////////////////////////////////////////////////
        static const PointI &cursorPos();


    #if defined(__Q2D_LIBRARY__)

        static void addButton(int button);
        static void remButton(int button);
        static void setPos(double x, double y);

    #endif

    };
}


#endif  // __Q2D_MOUSE_HPP__
