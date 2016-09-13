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


#ifndef __Q2D_LINE_HPP__
#define __Q2D_LINE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Structs/Point.hpp>
#include <Qube2D/Graphics/System/Base/IPrimitive.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Line.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \class   Line
    /// \brief   Defines a line with two vertices.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Line : public IPrimitive
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Line.
        ///
        ///////////////////////////////////////////////////////////
        Line();


        ///////////////////////////////////////////////////////////
        /// \fn     setLine
        /// \brief  Specifies the start and the end of the line.
        /// \param  start Start point of the line
        /// \param  end End point of the line
        ///
        ///////////////////////////////////////////////////////////
        void setLine(const PointF &start, const PointF &end);

        ///////////////////////////////////////////////////////////
        /// \fn     setColor
        /// \brief  Specifies the vertex colors.
        /// \param  first Color of the first vertex
        /// \param  second Color of the second vertex
        ///
        ///////////////////////////////////////////////////////////
        void setColor(const Color &first, const Color &second);

    };
}


#endif  // __Q2D_LINE_HPP__
