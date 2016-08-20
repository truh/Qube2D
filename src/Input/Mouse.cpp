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
#include <Qube2D/Input/Mouse.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Variables
    //
    ///////////////////////////////////////////////////////////
    bool Qube2D_Mouse_Dn[8];
    bool Qube2D_Mouse_Up[8];
    PointI Qube2D_Mouse_Pos;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      isButtonDown
    ///
    ///////////////////////////////////////////////////////////
    bool Mouse::isButtonDown(int button)
    {
        return Qube2D_Mouse_Dn[button];
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      isButtonReleased
    ///
    ///////////////////////////////////////////////////////////
    bool Mouse::isButtonReleased(int button)
    {
        return Qube2D_Mouse_Up[button];
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      cursorPos
    ///
    ///////////////////////////////////////////////////////////
    const PointI &Mouse::cursorPos()
    {
        return Qube2D_Mouse_Pos;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      addButton
    ///
    ///////////////////////////////////////////////////////////
    void Mouse::addButton(int button)
    {
        Qube2D_Mouse_Dn[button] = true;
        Qube2D_Mouse_Up[button] = false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      remButton
    ///
    ///////////////////////////////////////////////////////////
    void Mouse::remButton(int button)
    {
        Qube2D_Mouse_Up[button] = true;
        Qube2D_Mouse_Dn[button] = false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      setPos
    ///
    ///////////////////////////////////////////////////////////
    void Mouse::setPos(double x, double y)
    {
        // Sets X/Y as integer (and fix rounding values)
        Qube2D_Mouse_Pos.setX(static_cast<int>(x + 0.5));
        Qube2D_Mouse_Pos.setY(static_cast<int>(y + 0.5));
    }
}
