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


#ifndef __Q2D_KEYBOARD_HPP__
#define __Q2D_KEYBOARD_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Input/Keys.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Keyboard.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \class   Keyboard
    /// \brief   Handles multi-key input.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Keyboard
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn      isKeyDown
        /// \brief   Determines whether the given key is held.
        /// \param   key One of the QUBE_KEY values
        /// \returns true if the specified key is held.
        ///
        ///////////////////////////////////////////////////////////
        static bool isKeyDown(int key);

        ///////////////////////////////////////////////////////////
        /// \fn      isKeyReleased
        /// \brief   Determines whether the given key is released.
        /// \param   key One of the QUBE_KEY values
        /// \returns true if the specified key is released.
        ///
        ///////////////////////////////////////////////////////////
        static bool isKeyReleased(int key);

        ///////////////////////////////////////////////////////////
        /// \fn      isModDown
        /// \brief   Determines whether the given modifier is held.
        /// \param   mod One of the QUBE_MOD values
        /// \returns true if the specified modifier is held.
        ///
        ///////////////////////////////////////////////////////////
        static bool isModDown(int mod);

        ///////////////////////////////////////////////////////////
        /// \fn      isModReleased
        /// \brief   Determines whether the given modifier is released.
        /// \param   mod One of the QUBE_MOD values
        /// \returns true if the specified modifier is released.
        ///
        ///////////////////////////////////////////////////////////
        static bool isModReleased(int mod);


    #if defined(__Q2D_LIBRARY__)

        static void addKey(int key);
        static void remKey(int key);
        static void setMod(int mod);

    #endif

    };
}


#endif  // __Q2D_KEYBOARD_HPP__
