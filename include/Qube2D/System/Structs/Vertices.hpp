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


#ifndef __Q2D_VERTICES_HPP__
#define __Q2D_VERTICES_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  PrimitiveVertex
    /// \brief   Defines a vertex for primitives.
    ///
    /// Primitive vertices consist of a coordinate pair and
    /// RGB color components.
    ///
    ///////////////////////////////////////////////////////////
    struct PrimitiveVertex
    {
        float x;    ///< X-coordinate of the vertex
        float y;    ///< Y-coordinate of the vertex
        float r;    ///< Red color component of the vertex
        float g;    ///< Green color component of the vertex
        float b;    ///< Blue color component of the vertex


        ///////////////////////////////////////////////////////////
        /// \fn     xy -> inline
        /// \brief  Modifies the vertex position in one turn.
        ///
        ///////////////////////////////////////////////////////////
        inline void xy(float _x, float _y)
        {
            x = _x;
            y = _y;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     rgb -> inline
        /// \brief  Modifies the vertex color in one turn.
        ///
        ///////////////////////////////////////////////////////////
        inline void rgb(float _r, float _g, float _b)
        {
            r = _r;
            g = _g;
            b = _b;
        }
    };


    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  TextureVertex
    /// \brief   Defines a vertex for texture objects.
    ///
    /// Texture object vertices consist of a coordinate pair,
    /// a texture coordinate pair and RGB components.
    ///
    ///////////////////////////////////////////////////////////
    struct TextureVertex
    {
        float x;    ///< X-coordinate of the vertex
        float y;    ///< Y-coordinate of the vertex
        float u;    ///< First texture coordinate of the vertex
        float v;    ///< Second texture coordinate of the vertex
        float r;    ///< Red color component of the vertex
        float g;    ///< Green color component of the vertex
        float b;    ///< Blue color component of the vertex


        ///////////////////////////////////////////////////////////
        /// \fn     xy -> inline
        /// \brief  Modifies the vertex position in one turn.
        ///
        ///////////////////////////////////////////////////////////
        inline void xy(float _x, float _y)
        {
            x = _x;
            y = _y;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     uv -> inline
        /// \brief  Modifies the texture coordinates in one turn.
        ///
        ///////////////////////////////////////////////////////////
        inline void uv(float _u, float _v)
        {
            u = _u;
            v = _v;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     rgb -> inline
        /// \brief  Modifies the vertex color in one turn.
        ///
        ///////////////////////////////////////////////////////////
        inline void rgb(float _r, float _g, float _b)
        {
            r = _r;
            g = _g;
            b = _b;
        }
    };


    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  LineVertices
    /// \brief   Defines multiple vertices for a line.
    ///
    ///////////////////////////////////////////////////////////
    struct LineVertices
    {
        PrimitiveVertex v0; ///< Start of line
        PrimitiveVertex v1; ///< End of line
    };

    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  TriangleVertices
    /// \brief   Defines multiple vertices for a triangle.
    ///
    ///////////////////////////////////////////////////////////
    struct TriangleVertices
    {
        PrimitiveVertex v0; ///< First point (A)
        PrimitiveVertex v1; ///< Second point (B)
        PrimitiveVertex v2; ///< Third point (C)
    };

    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  QuadVertices
    /// \brief   Defines multiple vertices for a rectangle.
    ///
    ///////////////////////////////////////////////////////////
    struct QuadVertices
    {
        PrimitiveVertex v0; ///< First point (A)
        PrimitiveVertex v1; ///< Second point (B)
        PrimitiveVertex v2; ///< Third point (C)
        PrimitiveVertex v3; ///< Fourth point (D)
    };

    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  PolygonVertices
    /// \brief   Defines vertices for a n-polygon.
    ///
    ///////////////////////////////////////////////////////////
    struct PolygonVertices
    {
        std::vector<PrimitiveVertex> v;


        ///////////////////////////////////////////////////////////
        /// \fn     add -> inline
        /// \brief  Adds a vertex to the polygon.
        ///
        ///////////////////////////////////////////////////////////
        inline void add(PrimitiveVertex _v)
        {
            v.push_back(_v);
        }
    };

    ///////////////////////////////////////////////////////////
    /// \file    Vertices.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 7th, 2016
    /// \struct  TextureVertices
    /// \brief   Defines multiple vertices for a texture.
    ///
    ///////////////////////////////////////////////////////////
    struct TextureVertices
    {
        TextureVertex v0;   ///< Top-left
        TextureVertex v1;   ///< Top-right
        TextureVertex v2;   ///< Bottom-right
        TextureVertex v3;   ///< Bottom-left
    };
}


#endif  // __Q2D_VERTICES_HPP__
