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


#ifndef __Q2D_TRIANGLE_HPP__
#define __Q2D_TRIANGLE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Structs/Point.hpp>
#include <Qube2D/Graphics/System/Base/IPrimitive.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Triangle.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \class   Triangle
    /// \brief   Defines a triangle with three vertices.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Triangle : public IPrimitive
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Triangle.
        ///
        ///////////////////////////////////////////////////////////
        Triangle();


        ///////////////////////////////////////////////////////////
        /// \fn     setTriangle
        /// \brief  Specifies the triangle by three points.
        /// \param  a First point
        /// \param  b Second point
        /// \param  c Third point
        ///
        ///////////////////////////////////////////////////////////
        void setTriangle(const PointF &a,
                         const PointF &b,
                         const PointF &c);

        ///////////////////////////////////////////////////////////
        /// \fn     setColor
        /// \brief  Specifies the color of each triangle point.
        /// \param  c1 First point color
        /// \param  c2 Second point color
        /// \param  c3 Third point color
        ///
        ///////////////////////////////////////////////////////////
        void setColor(const Color &c1,
                      const Color &c2,
                      const Color &c3);

        ///////////////////////////////////////////////////////////
        /// \fn     setFilled
        /// \brief  Specifies whether the triangle should be filled.
        /// \param  fill TRUE if triangle should be filled
        ///
        ///////////////////////////////////////////////////////////
        void setFilled(bool fill);

    };
}


#endif  // __Q2D_TRIANGLE_HPP__
