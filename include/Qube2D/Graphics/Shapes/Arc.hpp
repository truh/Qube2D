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


#ifndef __Q2D_ARC_HPP__
#define __Q2D_ARC_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Graphics/System/Base/IPrimitive.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Arc.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \class   Arc
    /// \brief   Defines a piece of a circle or an ellipse.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Arc : public IPrimitive
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Arc.
        ///
        ///////////////////////////////////////////////////////////
        Arc();


        ///////////////////////////////////////////////////////////
        /// \fn     setArc
        /// \brief  Specifies the arc.
        /// \param  start Angle from where to start the arc
        /// \param  angle Amount of degrees to draw the arc
        /// \param  radius Radius of the circle or ellipse
        /// \param  (opt) r2 Second radius of the possible ellipse
        ///
        ///////////////////////////////////////////////////////////
        void setArc(QFloat start,  QFloat angle,
                    QFloat radius, QFloat r2 = 0);

        ///////////////////////////////////////////////////////////
        /// \fn     setColor
        /// \brief  Specifies the color of the arc.
        /// \param  color Color of the arc
        ///
        ///////////////////////////////////////////////////////////
        void setColor(const Color &color);

    };
}


#endif  // __Q2D_ARC_HPP__
