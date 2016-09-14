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


#ifndef __Q2D_ELLIPSE_HPP__
#define __Q2D_ELLIPSE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Graphics/System/Base/IPrimitive.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Ellipse.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \class   Ellipse
    /// \brief   Defines an ellipse with two radii.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Ellipse : public IPrimitive
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Ellipse.
        ///
        ///////////////////////////////////////////////////////////
        Ellipse();


        ///////////////////////////////////////////////////////////
        /// \fn     setRadii
        /// \brief  Specifies the radii that define the ellipse.
        /// \param  rh Horizontal radius
        /// \param  rv Vertical radius
        ///
        ///////////////////////////////////////////////////////////
        void setRadii(QFloat rh, QFloat rv);

        ///////////////////////////////////////////////////////////
        /// \fn     setColor
        /// \brief  Specifies the color of the ellipse.
        /// \param  color Color of the ellipse
        ///
        ///////////////////////////////////////////////////////////
        void setColor(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     setFilled
        /// \brief  Specifies whether the ellipse should be filled.
        /// \param  fill TRUE to fill the ellipse
        ///
        ///////////////////////////////////////////////////////////
        void setFilled(bool fill);

    };
}


#endif  // __Q2D_ELLIPSE_HPP__
