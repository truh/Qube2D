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


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Structs/Rect.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Structs.cpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     Point<int>, Point<float>, Point<unsigned>
    ///
    /// Instantiates the three most common point types which
    /// are being used by the Qube2D library.
    ///
    ///////////////////////////////////////////////////////////
    Q2D_TPL Point<int>;
    Q2D_TPL Point<float>;
    Q2D_TPL Point<unsigned>;

    ///////////////////////////////////////////////////////////
    /// \file    Structs.cpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \def     Size<int>, Size<float>, Size<unsigned>
    ///
    /// Instantiates the three most common Size types which
    /// are being used by the Qube2D library.
    ///
    ///////////////////////////////////////////////////////////
    Q2D_TPL Size<int>;
    Q2D_TPL Size<float>;
    Q2D_TPL Size<unsigned>;

    ///////////////////////////////////////////////////////////
    /// \file    Structs.cpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     Rect<int>, Rect<float>, Rect<unsigned>
    ///
    /// Instantiates the three most common point types which
    /// are being used by the Qube2D library.
    ///
    ///////////////////////////////////////////////////////////
    Q2D_TPL Rect<int>;
    Q2D_TPL Rect<float>;
    Q2D_TPL Rect<unsigned>;
}
