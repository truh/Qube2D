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


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Input/Keyboard.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Variables
    //
    ///////////////////////////////////////////////////////////
    bool Qube2D_Keyboard_Dn[348];
    bool Qube2D_Keyboard_Up[348];
    int  Qube2D_Keyboard_Mod = 0;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      isKeyDown
    ///
    ///////////////////////////////////////////////////////////
    bool Keyboard::isKeyDown(int key)
    {
        return Qube2D_Keyboard_Dn[key];
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      isKeyReleased
    ///
    ///////////////////////////////////////////////////////////
    bool Keyboard::isKeyReleased(int key)
    {
        return Qube2D_Keyboard_Up[key];
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      isModDown
    ///
    ///////////////////////////////////////////////////////////
    bool Keyboard::isModDown(int mod)
    {
        return (Qube2D_Keyboard_Mod & mod) != 0;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      isModReleased
    ///
    ///////////////////////////////////////////////////////////
    bool Keyboard::isModReleased(int mod)
    {
        return (Qube2D_Keyboard_Mod & mod) == 0;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      addKey
    ///
    ///////////////////////////////////////////////////////////
    void Keyboard::addKey(int key)
    {
        Qube2D_Keyboard_Dn[key] = true;
        Qube2D_Keyboard_Up[key] = false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      remKey
    ///
    ///////////////////////////////////////////////////////////
    void Keyboard::remKey(int key)
    {
        Qube2D_Keyboard_Up[key] = true;
        Qube2D_Keyboard_Dn[key] = false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      setMod
    ///
    ///////////////////////////////////////////////////////////
    void Keyboard::setMod(int mod)
    {
        Qube2D_Keyboard_Mod = mod;
    }
}
