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


#ifndef __Q2D_IPRIMITIVE_HPP__
#define __Q2D_IPRIMITIVE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Structs/Color.hpp>
#include <Qube2D/System/Structs/Vertices.hpp>
#include <Qube2D/Graphics/GraphicsEnums.hpp>
#include <Qube2D/Graphics/Base/IFadable.hpp>
#include <Qube2D/Graphics/Base/IMovable.hpp>
#include <Qube2D/Graphics/Base/ITransformable.hpp>
#include <Qube2D/Graphics/OpenGL/VertexArray.hpp>
#include <Qube2D/Graphics/OpenGL/VertexBuffer.hpp>
#include <Qube2D/Graphics/OpenGL/ShaderProgram.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    IPrimitive.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \class   IPrimitive
    /// \brief   Base class for all primitive-based rendering.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API IPrimitive : public IMovable,
                               public IFadable,
                               public ITransformable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Primitive.
        ///
        ///////////////////////////////////////////////////////////
        IPrimitive();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Creates all OpenGL-related objects.
        /// \note   Must be called before modifying the data and
        ///         after creating the window.
        ///
        ///////////////////////////////////////////////////////////
        void create();

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Destroys all OpenGL-related objects.
        /// \note   Must be called before destroying the window.
        ///
        ///////////////////////////////////////////////////////////
        void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn     setCustomShaderProgram
        /// \brief  Specifies a shader program for this primitive.
        /// \param  program Program having shaders attached to it
        /// \note   This function causes the rendering to override
        ///         the default shader program. To reset it, pass
        ///         NULL to this function.
        ///
        ///////////////////////////////////////////////////////////
        void setCustomShaderProgram(ShaderProgram *program);


        ///////////////////////////////////////////////////////////
        /// \fn     update
        /// \brief  Updates possible movement and fading.
        ///
        ///////////////////////////////////////////////////////////
        void update(double deltaTime);

        ///////////////////////////////////////////////////////////
        /// \fn     render
        /// \brief  Applies vertex changes and performs rendering.
        ///
        ///////////////////////////////////////////////////////////
        void render();


    #ifdef __Q2D_LIBRARY__

        ///////////////////////////////////////////////////////////
        /// \fn     initializeGL
        /// \brief  Creates all static OpenGL objects.
        ///
        ///////////////////////////////////////////////////////////
        static void initializeGL();

        ///////////////////////////////////////////////////////////
        /// \fn     destroyGL
        /// \brief  Destroys all static OpenGL objects.
        ///
        ///////////////////////////////////////////////////////////
        static void destroyGL();

    #endif


    protected:


        ///////////////////////////////////////////////////////////
        /// \fn     setVertexCount
        /// \brief  Specifies the amount of vertices.
        /// \param  count Amount of vertices to allocate
        /// \note   Must be called before modifying vertices.
        ///
        ///////////////////////////////////////////////////////////
        void setVertexCount(QUInt32 count);

        ///////////////////////////////////////////////////////////
        /// \fn     setVertexColors
        /// \brief  Specifies the color of each vertex.
        /// \param  colors List-size must be equal to vertex-count
        /// \note   If the list contains one element only, the engine
        ///         assumes that all vertices should be that color.
        ///
        ///////////////////////////////////////////////////////////
        void setVertexColors(const std::vector<Color> &colors);


        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        VertexBuffer m_VertexBuffer;    ///< Buffer for vertex data
        PolygonVertices m_Vertices;     ///< Vertex data
        ShaderProgram *m_CustomProgram; ///< Custom shader program
        QUInt32 m_DrawMode;             ///< OpenGL drawing mode


    private:

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static VertexArray m_VertexArray;       ///< Primitive vertex array
        static ShaderProgram m_ShaderProgram;   ///< Primitive shader program
        static Shader m_VertexShader;           ///< Primitive vertex shader
        static Shader m_FragShader;             ///< Primitive frag. shader
        static QInt32 m_UniformMatrix;          ///< MVP variable loc
        static QInt32 m_UniformOpacity;         ///< Opacity variable loc

    };
}


#endif  // __Q2D_IPRIMITIVE_HPP__
