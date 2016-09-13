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
#include <Qube2D/Graphics/Shapes/Polygon.hpp>
#include <Qube2D/Graphics/System/GraphicsEnums.hpp>
#include <cmath>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Polygon::Polygon()
        : IPrimitive()
    {
        m_DrawMode = static_cast<QUInt32>(DrawMode::LineLoop);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setVertices
    ///
    ///////////////////////////////////////////////////////////
    void Polygon::setVertices(const std::vector<PointF> &v)
    {
        unsigned s = v.size();
        float sx = 0, sy = 0;
        assert(s != 0);


        setVertexCount(s);

        for (QUInt32 i = 0; i < s; ++i)
        {
            QFloat x = v.at(i).x();
            QFloat y = v.at(i).y();

            m_Vertices[i].xy(x, y);
            sx += x;
            sy += y;
        }

        setOrigin(sx / s, sy / s);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setColor
    ///
    ///////////////////////////////////////////////////////////
    void Polygon::setColor(const std::vector<Color> &c)
    {
        setVertexColors(c);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setFilled
    ///
    ///////////////////////////////////////////////////////////
    void Polygon::setFilled(bool fill)
    {
        if (fill)
            m_DrawMode = static_cast<QUInt32>(DrawMode::TriangleFan);
        else
            m_DrawMode = static_cast<QUInt32>(DrawMode::LineLoop);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      generateRegular
    ///
    ///////////////////////////////////////////////////////////
    void Polygon::generateRegular(QFloat size, QUInt32 n)
    {
        QFloat radius = (size / 2);
        QFloat cx = radius;
        QFloat cy = radius;
        std::vector<PointF> v;

        v.push_back({ cx + radius*cosf(0), cy + radius*sinf(0) });

        for (QUInt32 i = 1; i <= n; ++i)
            v.push_back({ cx + radius*cosf((2*i)*(M_PI/n)), cy + radius*sinf((2*i)*(M_PI/n)) });

        setVertices(v);
    }
}
