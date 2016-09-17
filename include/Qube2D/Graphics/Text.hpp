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


#ifndef __Q2D_TEXT_HPP__
#define __Q2D_TEXT_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Structs/Rect.hpp>
#include <Qube2D/System/Structs/Vertices.hpp>
#include <Qube2D/System/Localization/String.hpp>
#include <Qube2D/Graphics/System/GraphicsEnums.hpp>
#include <Qube2D/Graphics/System/Base/IFadable.hpp>
#include <Qube2D/Graphics/System/Base/IMovable.hpp>
#include <Qube2D/Graphics/System/Base/ITransformable.hpp>
#include <Qube2D/Graphics/System/OpenGL/Texture.hpp>
#include <Qube2D/Graphics/System/OpenGL/VertexArray.hpp>
#include <Qube2D/Graphics/System/OpenGL/VertexBuffer.hpp>
#include <Qube2D/Graphics/System/OpenGL/ShaderProgram.hpp>
#include <Qube2D/Graphics/Text/FontManager.hpp>
#include <Qube2D/Graphics/Text/TextErrors.hpp>
#include <Qube2D/Graphics/Text/TextEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Text.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \class   Text
    /// \brief   Renders unicode text with various styles.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Text : public IMovable,
                         public IFadable,
                         public ITransformable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Text.
        ///
        ///////////////////////////////////////////////////////////
        Text();


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
        /// \fn     setColor
        /// \brief  Specifies the color for the actual text.
        /// \param  color Color of the text
        ///
        ///////////////////////////////////////////////////////////
        void setColor(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     setOutlineColor
        /// \brief  Specifies the color for the outline, if any.
        /// \param  color Outline color of the text
        ///
        ///////////////////////////////////////////////////////////
        void setOutlineColor(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     setOutlineWidth
        /// \brief  Specifies the width for the outline, if any.
        /// \param  width Width of the outline, in pixels
        ///
        ///////////////////////////////////////////////////////////
        void setOutlineWidth(QFloat width);

        ///////////////////////////////////////////////////////////
        /// \fn     setLineWidth
        /// \brief  Sets the width of the underline and strikethrough.
        /// \param  width Width of the line, in pixels
        ///
        ///////////////////////////////////////////////////////////
        void setLineWidth(QFloat width);

        ///////////////////////////////////////////////////////////
        /// \fn     setFont
        /// \brief  Specifies the font to render the text with.
        /// \param  font Pointer to valid Qube2D::Font structure
        /// \note   Must be called before 'setText'.
        ///
        ///////////////////////////////////////////////////////////
        void setFont(Font *font);

        ///////////////////////////////////////////////////////////
        /// \fn     setTextSize
        /// \brief  Specifies the text size.
        /// \param  size Pixel size of the text
        /// \note   Must be called before 'setText'.
        ///
        ///////////////////////////////////////////////////////////
        void setTextSize(QUInt32 size);

        ///////////////////////////////////////////////////////////
        /// \fn     setText
        /// \brief  Specifies the text to render.
        /// \param  text UTF-32 text
        /// \param  style Combination of TextStyle flags
        ///
        ///////////////////////////////////////////////////////////
        void setText(const String &text,
                     TextStyle style = TextStyle::Regular);


        ///////////////////////////////////////////////////////////
        /// \fn     render
        /// \brief  Renders the text.
        ///
        ///////////////////////////////////////////////////////////
        void update(double deltaTime);

        ///////////////////////////////////////////////////////////
        /// \fn     render
        /// \brief  Renders the text.
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


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        VertexBuffer m_VertexBuffer;    ///< Buffer for vertex data
        Font *m_Font;                   ///< Font to use
        GLColor m_Color;                ///< Text color
        GLColor m_OutlineColor;         ///< Outline color
        QUInt32 m_VertexCount;          ///< Vertex count
        QUInt32 m_OutlineVertexCount;   ///< Outline vertex count
        QUInt32 m_Size;                 ///< Text size
        TextStyle m_Style;              ///< Text style
        QFloat m_OutlineWidth;          ///< Outline width
        QFloat m_LineWidth;             ///< Underline & Strikethrough width

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static VertexArray m_VertexArray;       ///< Texture vertex array
        static ShaderProgram m_ShaderProgram;   ///< Texture shader program
        static Shader m_VertexShader;           ///< Texture vertex shader
        static Shader m_FragShader;             ///< Texture frag. shader
        static QInt32 m_UniformSampler;         ///< Sampler2D variable loc
        static QInt32 m_UniformMatrix;          ///< MVP variable loc
        static QInt32 m_UniformOpacity;         ///< Opacity variable loc
        static QInt32 m_UniformColor;           ///< Uniform text color
        static QInt32 m_UniformOutColor;        ///< Uniform outline color

    };
}


#endif  // __Q2D_TEXT_HPP__
