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
#include <Qube2D/Graphics/System/Shader/TextShaders.hpp>
#include <Qube2D/System/Structs/GLColor.hpp>
#include <Qube2D/Graphics/Text.hpp>
#include <Qube2D/Debug/GLCheck.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <fstream>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Constant definitions
    //
    ///////////////////////////////////////////////////////////
    #define TEXT_SINGLE_VERTEX     sizeof(float) * 4
    #define TEXT_OFFSET_COORD      (const void *)(sizeof(float) * 2)


    ///////////////////////////////////////////////////////////
    // Static class member definitions
    //
    ///////////////////////////////////////////////////////////
    VertexArray Text::m_VertexArray;
    ShaderProgram Text::m_ShaderProgram;
    Shader Text::m_VertexShader;
    Shader Text::m_FragShader;
    QInt32 Text::m_UniformSampler;
    QInt32 Text::m_UniformMatrix;
    QInt32 Text::m_UniformOpacity;
    QInt32 Text::m_UniformColor;
    QInt32 Text::m_UniformOutColor;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Text::Text()
        : IFadable(),
          IMovable(),
          ITransformable(),
          m_Font(NULL),
          m_VertexCount(0),
          m_OutlineWidth(0.f)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void Text::create()
    {
        m_VertexBuffer.create(BufferType::Vertex,
                              BufferUsage::Dynamic);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void Text::destroy()
    {
        m_VertexBuffer.destroy();
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      setColor
    ///
    ///////////////////////////////////////////////////////////
    void Text::setColor(const Color &color)
    {
        m_Color = color.toGL();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      setOutlineColor
    ///
    ///////////////////////////////////////////////////////////
    void Text::setOutlineColor(const Color &color)
    {
        m_OutlineColor = color.toGL();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 16th, 2016
    /// \fn      setOutlineWidth
    ///
    ///////////////////////////////////////////////////////////
    void Text::setOutlineWidth(QFloat width)
    {
        m_OutlineWidth = width;
        m_Font->setOutlineWidth(width);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      setFont
    ///
    ///////////////////////////////////////////////////////////
    void Text::setFont(Font *font)
    {
        assert(font);
        m_Font = font;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      setTextSize
    ///
    ///////////////////////////////////////////////////////////
    void Text::setTextSize(QUInt32 size)
    {
        m_Size = size;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      setText
    ///
    ///////////////////////////////////////////////////////////
    void Text::setText(const String &text, TextStyle style)
    {
        assert(!text.isEmpty());
        assert(m_Font);


        m_Font->extract(m_Size);
        m_VertexCount = 0;
        m_Style = style;


        const char32_t *string = text.data();
        char32_t prevChar = 0;

        QUInt32 length = text.length();
        QFloat sp_line = m_Font->lineSpacing();
        QFloat pos_x = 0, pos_y = 0;
        std::vector<float> vertices, outlineVertices;

        TextStyle regular = static_cast<TextStyle>(
                            static_cast<QInt32>(style) &
                           ~static_cast<QInt32>(TextStyle::Outline));

        if (!m_Font->isCached(U' ', regular))
            m_Font->cacheGlyph(U' ', regular);

        QFloat wsAdvance = m_Font->glyph(U' ', regular).advance;


        // Generates the "outline" vertices
        for (QUInt32 i = 0; i < length; ++i)
        {
            // Changes the vertical position on new-line
            char32_t c = string[i];
            if (c == '\n')
            {
                pos_y += sp_line;
                pos_x = 0;
                continue;
            }
            if (c == ' ')
            {
                pos_x += wsAdvance;
                continue;
            }
            if (style & TextStyle::Outline)
            {
                // Caches the glyph, if not already
                if (!m_Font->isCached(c, style))
                    m_Font->cacheGlyph(c, style);

                // Generates the vertex data
                const Glyph &glyph = m_Font->glyph(c, style);
                QFloat x = pos_x + glyph.bearing_x - m_OutlineWidth, w = x + glyph.glyph_w;
                QFloat y = pos_y + glyph.bearing_y - m_OutlineWidth, h = y + glyph.glyph_h;
                QFloat u = glyph.texture_x, v = glyph.texture_y;
                QFloat s = u + glyph.texture_w, t = v + glyph.texture_h;

                outlineVertices.push_back(x); outlineVertices.push_back(y);
                outlineVertices.push_back(u); outlineVertices.push_back(v);
                outlineVertices.push_back(w); outlineVertices.push_back(y);
                outlineVertices.push_back(s); outlineVertices.push_back(v);
                outlineVertices.push_back(x); outlineVertices.push_back(h);
                outlineVertices.push_back(u); outlineVertices.push_back(t);
                outlineVertices.push_back(x); outlineVertices.push_back(h);
                outlineVertices.push_back(u); outlineVertices.push_back(t);
                outlineVertices.push_back(w); outlineVertices.push_back(y);
                outlineVertices.push_back(s); outlineVertices.push_back(v);
                outlineVertices.push_back(w); outlineVertices.push_back(h);
                outlineVertices.push_back(s); outlineVertices.push_back(t);
            }

            // Caches the glyph, if not already
            if (!m_Font->isCached(c, regular))
                m_Font->cacheGlyph(c, regular);

            // Generates the vertex data
            const Glyph &glyph = m_Font->glyph(c, regular);
            QFloat x = pos_x + glyph.bearing_x, w = x + glyph.glyph_w;
            QFloat y = pos_y + glyph.bearing_y, h = y + glyph.glyph_h;
            QFloat u = glyph.texture_x, v = glyph.texture_y;
            QFloat s = u + glyph.texture_w, t = v + glyph.texture_h;

            vertices.push_back(x); vertices.push_back(y);
            vertices.push_back(u); vertices.push_back(v);
            vertices.push_back(w); vertices.push_back(y);
            vertices.push_back(s); vertices.push_back(v);
            vertices.push_back(x); vertices.push_back(h);
            vertices.push_back(u); vertices.push_back(t);
            vertices.push_back(x); vertices.push_back(h);
            vertices.push_back(u); vertices.push_back(t);
            vertices.push_back(w); vertices.push_back(y);
            vertices.push_back(s); vertices.push_back(v);
            vertices.push_back(w); vertices.push_back(h);
            vertices.push_back(s); vertices.push_back(t);
            m_VertexCount += 6;

            pos_x += glyph.advance;
            pos_x += m_Font->kerning(prevChar, c);
            prevChar = c;
        }


        // Updates the vertex buffer
        vertices.insert(vertices.end(), outlineVertices.begin(), outlineVertices.end());
        m_VertexBuffer.bind();
        m_VertexBuffer.fill(vertices.data(), vertices.size() * sizeof(float));
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      update
    ///
    ///////////////////////////////////////////////////////////
    void Text::update(double deltaTime)
    {
        updateFade(deltaTime);
        updateMovement(deltaTime);
        updateScaling(deltaTime);
        updateRotation(deltaTime);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      render
    ///
    ///////////////////////////////////////////////////////////
    void Text::render()
    {
        // Constructs the MVP matrix
        glm::mat4 identity      = glm::mat4(1.f);
        glm::mat4 projection    = glm::ortho(0.f, m_WinW, m_WinH, 0.f);
        glm::mat4 translation   = glm::translate(identity, glm::vec3(x(), y(), 0.f));
        glm::mat4 origin        = glm::translate(identity, glm::vec3(-originX(), -originY(), 0.f));
        glm::mat4 rotation      = glm::rotate(identity, glm::radians(angle()), glm::vec3(0.f, 0.f, 1.f));
        glm::mat4 iorigin       = glm::translate(identity, glm::vec3(originX(), originY(), 0.f));
        glm::mat4 scaling       = glm::scale(identity, glm::vec3(scale(), scale(), 1.f));
        glm::mat4 mvp           = projection * translation * iorigin * rotation * origin * scaling * identity;


        // Binds all necessary objects
        m_VertexArray.bind();
        m_VertexBuffer.bind();
        m_ShaderProgram.bind();


        // Binds the font texture
        glCheck(glActiveTexture(GL_TEXTURE0));
        glCheck(glBindTexture(GL_TEXTURE_2D, m_Font->texture().id()));
        glCheck(glUniform1i(m_UniformSampler, 0));

        // Forwards the MVP matrix and the opacity to the shader
        glCheck(glUniformMatrix4fv(m_UniformMatrix, 1, GL_FALSE, &mvp[0][0]));
        glCheck(glUniform1f(m_UniformOpacity, opacity()));


        // Enables all the used vertex attributes
        m_VertexArray.enableAttrib(0);
        m_VertexArray.enableAttrib(1);

        // Specifies the vertex attributes
        glCheck(glVertexAttribPointer(
                    0,
                    2,
                    GL_FLOAT,
                    GL_FALSE,
                    TEXT_SINGLE_VERTEX,
                    NULL));

        glCheck(glVertexAttribPointer(
                    1,
                    2,
                    GL_FLOAT,
                    GL_FALSE,
                    TEXT_SINGLE_VERTEX,
                    TEXT_OFFSET_COORD));


        // Renders the outlines
        if (m_Style == TextStyle::Outline)
        {
            glCheck(glUniform4f(m_UniformColor,
                                m_OutlineColor.r(),
                                m_OutlineColor.g(),
                                m_OutlineColor.b(),
                                m_OutlineColor.a()));

            glCheck(glDrawArrays(
                        GL_TRIANGLES,
                        m_VertexCount,
                        m_VertexCount));
        }

        // Writes the uniform color values
        glCheck(glUniform4f(m_UniformColor,
                            m_Color.r(),
                            m_Color.g(),
                            m_Color.b(),
                            m_Color.a()));

        // Renders the glyphs
        glCheck(glDrawArrays(
                    GL_TRIANGLES,
                    GL_ZERO,
                    m_VertexCount));


        // Disables all the used vertex attributes
        m_VertexArray.disableAttrib(1);
        m_VertexArray.disableAttrib(0);

        // Unbinds the necessary objects
        m_VertexArray.unbind();
        m_VertexBuffer.unbind();
        m_ShaderProgram.unbind();
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      initializeGL
    ///
    ///////////////////////////////////////////////////////////
    void Text::initializeGL()
    {
        m_VertexArray.create();
        m_ShaderProgram.create();
        m_VertexShader.create(ShaderType::Vertex);
        m_FragShader.create(ShaderType::Fragment);

        m_VertexShader.compileFromString(Qube2D_TextVertexShader);
        m_FragShader.compileFromString(Qube2D_TextFragShader);
        m_ShaderProgram.addShader(m_VertexShader);
        m_ShaderProgram.addShader(m_FragShader);
        m_ShaderProgram.link();
        m_ShaderProgram.bind();

        m_UniformMatrix = m_ShaderProgram.getUniformLocation("uni_mvp");
        m_UniformSampler = m_ShaderProgram.getUniformLocation("uni_texture");
        m_UniformOpacity = m_ShaderProgram.getUniformLocation("uni_opacity");
        m_UniformColor = m_ShaderProgram.getUniformLocation("uni_color");
        m_UniformOutColor = m_ShaderProgram.getUniformLocation("uni_outline");
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \fn      destroyGL
    ///
    ///////////////////////////////////////////////////////////
    void Text::destroyGL()
    {
        m_VertexShader.destroy();
        m_FragShader.destroy();
        m_ShaderProgram.destroy();
        m_VertexArray.destroy();
    }
}
