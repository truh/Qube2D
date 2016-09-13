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
#include <Qube2D/Graphics/Shapes/Rectangle.hpp>
#include <Qube2D/Graphics/System/GraphicsEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Rectangle::Rectangle()
        : IPrimitive()
    {
        setVertexCount(4);
        m_DrawMode = static_cast<QUInt32>(DrawMode::LineLoop);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setRect
    ///
    ///////////////////////////////////////////////////////////
    void Rectangle::setRect(const RectF &rect)
    {
        m_Vertices[0].xy(rect.x(), rect.y());
        m_Vertices[1].xy(rect.x() + rect.width(), rect.y());
        m_Vertices[2].xy(rect.x() + rect.width(), rect.y() + rect.height());
        m_Vertices[3].xy(rect.x(), rect.y() + rect.height());
        setOrigin(rect.width()/2, rect.height()/2);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setColor
    ///
    ///////////////////////////////////////////////////////////
    void Rectangle::setColor(const Color &c1,
                             const Color &c2,
                             const Color &c3,
                             const Color &c4)
    {
        GLColor a = c1.toGL();
        GLColor b = c2.toGL();
        GLColor c = c3.toGL();
        GLColor d = c4.toGL();

        m_Vertices[0].rgba(a.r(), a.g(), a.b(), a.a());
        m_Vertices[1].rgba(b.r(), b.g(), b.b(), b.a());
        m_Vertices[2].rgba(c.r(), c.g(), c.b(), c.a());
        m_Vertices[3].rgba(d.r(), d.g(), d.b(), d.a());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 13th, 2016
    /// \fn      setFilled
    ///
    ///////////////////////////////////////////////////////////
    void Rectangle::setFilled(bool fill)
    {
        if (fill)
            m_DrawMode = static_cast<QUInt32>(DrawMode::TriangleFan);
        else
            m_DrawMode = static_cast<QUInt32>(DrawMode::LineLoop);
    }
}
