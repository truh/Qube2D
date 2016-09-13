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
#include <Qube2D/System/Structs/GLColor.hpp>
#include <Qube2D/Graphics/Shapes/Line.hpp>
#include <Qube2D/Graphics/System/GraphicsEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Line::Line()
        : IPrimitive()
    {
        setVertexCount(2);
        m_DrawMode = static_cast<QUInt32>(DrawMode::Lines);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setLine
    ///
    ///////////////////////////////////////////////////////////
    void Line::setLine(const PointF &start, const PointF &end)
    {
        m_Vertices[0].xy(start.x(), start.y());
        m_Vertices[1].xy(end.x(), end.y());
        setOrigin((end.x()-start.x()) / 2, (end.y()-start.y()) / 2);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setColor
    ///
    ///////////////////////////////////////////////////////////
    void Line::setColor(const Color &first, const Color &second)
    {
        GLColor f = first.toGL();
        GLColor s = second.toGL();

        m_Vertices[0].rgba(f.r(), f.g(), f.b(), f.a());
        m_Vertices[1].rgba(s.r(), s.g(), s.b(), s.a());
    }
}
