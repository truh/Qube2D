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
#include <Qube2D/Graphics/Shapes/Circle.hpp>
#include <cmath>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Circle::Circle()
        : IPrimitive()
    {
        m_DrawMode = static_cast<QUInt32>(DrawMode::LineLoop);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setRadius
    ///
    ///////////////////////////////////////////////////////////
    void Circle::setRadius(QFloat r)
    {
        // Calculates the segments, depending on the size
        QUInt32 segments = (r*2) * 3.6;
        setVertexCount(segments);

        // Calculates the radians per segment
        QFloat rps = (M_PI*2.f) / segments;

        // Pre-calculates the sine and cosine
        QFloat s = sinf(rps);
        QFloat c = cosf(rps);
        QFloat x = r, y = 0, t;

        // Computes all vertex locations. Speeds up the process by rotating
        // the shape instead of re-calculating the sine and cosine.
        for (QUInt32 i = 0; i < segments; ++i)
        {
            t = x;
            m_Vertices[i].xy(x+r, y+r);
            x = (c*x) - (s*y);
            y = (s*t) + (c*y);
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setColor
    ///
    ///////////////////////////////////////////////////////////
    void Circle::setColor(const Color &color)
    {
        QUInt32 s = m_Vertices.size();
        GLColor c = color.toGL();
        QFloat  r = c.r();
        QFloat  g = c.g();
        QFloat  b = c.b();
        QFloat  a = c.a();

        for (QUInt32 i = 0; i < s; ++i)
            m_Vertices[i].rgba(r, g, b, a);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setFilled
    ///
    ///////////////////////////////////////////////////////////
    void Circle::setFilled(bool fill)
    {
        if (fill)
            m_DrawMode = static_cast<QUInt32>(DrawMode::TriangleFan);
        else
            m_DrawMode = static_cast<QUInt32>(DrawMode::LineLoop);
    }
}
