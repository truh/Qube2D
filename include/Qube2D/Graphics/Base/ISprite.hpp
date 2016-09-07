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


#ifndef __Q2D_ISPRITE_HPP__
#define __Q2D_ISPRITE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Structs/Rect.hpp>
#include <Qube2D/System/Structs/Vertices.hpp>
#include <Qube2D/Graphics/GraphicsEnums.hpp>
#include <Qube2D/Graphics/Base/IFadable.hpp>
#include <Qube2D/Graphics/Base/IMovable.hpp>
#include <Qube2D/Graphics/Base/ITransformable.hpp>
#include <Qube2D/Graphics/OpenGL/Texture.hpp>
#include <Qube2D/Graphics/OpenGL/VertexArray.hpp>
#include <Qube2D/Graphics/OpenGL/VertexBuffer.hpp>
#include <Qube2D/Graphics/OpenGL/ShaderProgram.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    ISprite.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 31th, 2016
    /// \class   ISprite
    /// \brief   Base class for all texture-based rendering.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API ISprite : public IMovable,
                            public IFadable,
                            public ITransformable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Image.
        ///
        ///////////////////////////////////////////////////////////
        ISprite();


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
        /// \fn     load
        /// \brief  Loads an image from a relative or absolute path.
        /// \param  path Absolute or relative path to the image
        ///
        ///////////////////////////////////////////////////////////
        void load(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn     load (overload #1)
        /// \brief  Directly loads the texture to display.
        /// \param  texture Texture to render
        ///
        ///////////////////////////////////////////////////////////
        void load(const Texture &texture);


        ///////////////////////////////////////////////////////////
        /// \fn     setSourceRectangle
        /// \brief  Specifies the region of the image to be drawn.
        /// \param  rect Region to draw
        ///
        ///////////////////////////////////////////////////////////
        void setSourceRectangle(const RectF &rect);

        ///////////////////////////////////////////////////////////
        /// \fn     setBlendColor
        /// \brief  Specifies the color to blend each pixel with.
        /// \param  color Color to be added, multiplied, ...
        ///
        ///////////////////////////////////////////////////////////
        void setBlendColor(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     setBlendColorEx
        /// \brief  Specifies the blend color for each vertex.
        /// \param  topLeft Top-left vertex blend color
        /// \param  topRight Top-right vertex blend color
        /// \param  bottomRight Bottom-right vertex blend color
        /// \param  bottomLeft Bottom-left vertex blend color
        ///
        ///////////////////////////////////////////////////////////
        void setBlendColorEx(const Color &topLeft,
                             const Color &topRight,
                             const Color &bottomRight,
                             const Color &bottomLeft);

        ///////////////////////////////////////////////////////////
        /// \fn     setBlendMode
        /// \brief  Specifies the blend mode within the frag shader.
        /// \param  mode One of the Qube2D::BlendMode enum values
        /// \note   The default value is BlendMode::NoBlend.
        ///
        ///////////////////////////////////////////////////////////
        void setBlendMode(BlendMode mode);

        ///////////////////////////////////////////////////////////
        /// \fn     setCustomShaderProgram
        /// \brief  Specifies a shader program for this texture.
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
        /// \brief  Applies vertex changes and renders the texture.
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
        // Class members
        //
        ///////////////////////////////////////////////////////////
        VertexBuffer m_VertexBuffer;    ///< Buffer for vertex data
        TextureVertices m_Vertices;     ///< Vertex data
        Texture m_Texture;              ///< Underlying texture
        BlendMode m_BlendMode;          ///< Fragment shader mode
        ShaderProgram *m_CustomProgram; ///< Custom shader program


    private:

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static VertexArray m_VertexArray;       ///< Texture vertex array
        static VertexBuffer m_IndexBuffer;      ///< Texture index buffer
        static ShaderProgram m_ShaderProgram;   ///< Texture shader program
        static Shader m_VertexShader;           ///< Texture vertex shader
        static Shader m_FragShader;             ///< Texture frag. shader
        static QInt32 m_UniformSampler;         ///< Sampler2D variable loc
        static QInt32 m_UniformMatrix;          ///< MVP variable loc
        static QInt32 m_UniformOpacity;         ///< Opacity variable loc

    };
}


#endif  // __Q2D_ISPRITE_HPP__
