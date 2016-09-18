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
#include <Qube2D/Graphics/System/Shader/TextShaders.hpp>
#include <Qube2D/Graphics/Text.hpp>
#include <Qube2D/Debug/GLCheck.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <fstream>
#include <cmath>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Constant definitions
    //
    ///////////////////////////////////////////////////////////
    #define TEXT_SINGLE_VERTEX     sizeof(float) * 4
    #define TEXT_OFFSET_COORD      (const void *)(sizeof(float) * 2)
    inline void Qube2D_Text_Add_Line(std::vector<float> &v, const RectF &bounds);


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
    /// \date    September 17th, 2016
    /// \fn      setLineWidth
    ///
    ///////////////////////////////////////////////////////////
    void Text::setLineWidth(QFloat width)
    {
        m_LineWidth = width;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 17th, 2016
    /// \fn      setShadowOffset
    ///
    ///////////////////////////////////////////////////////////
    void Text::setShadowOffset(QFloat x, QFloat y)
    {
        m_ShadowX = x;
        m_ShadowY = y;
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


        // Prepares all glyphs of given size
        m_Font->extract(m_Size);
        m_OutlineVertexCount = 0;
        m_VertexCount = 0;
        m_Style = style;


        // Removes the outline bit from the field
        TextStyle regular = style & ~TextStyle::Outline;
        std::vector<float> vertices, outlineVertices, shadowVertices;
        char32_t prevChar = 0;

        // Determines strike-through location with character 'x'
        QUInt32 strikeY = m_Font->measureString(U"x", regular, m_Size).height() / 2.f;


        // Pre-computes the advance offset of a whitespace
        if (!m_Font->isCached(U' ', regular))
            m_Font->cacheGlyph(U' ', regular);


        // Retrieves miscellaneous values for the iteration
        QFloat wsAdvance = m_Font->glyph(U' ', regular).advance;
        QUInt32 length = text.length();
        QFloat sp_line = m_Font->lineSpacing();
        QFloat pos_x = 0, pos_y = 0;


        // Generates the "outline" vertices
        for (QUInt32 i = 0; i < length; ++i)
        {
            char32_t c = text.at(i);

            // Changes the vertical position on new-line
            if (c == '\n')
            {
                // Add underline & strikethrough for this line
                if (style & TextStyle::Underline)
                    Qube2D_Text_Add_Line(vertices, { 0, pos_y + sp_line, pos_x, m_LineWidth });
                if (style & TextStyle::Strikethrough)
                    Qube2D_Text_Add_Line(vertices, { 0, pos_y + strikeY, pos_x, m_LineWidth });

                // Increment Y pos
                pos_y += sp_line;
                pos_x = 0;
                continue;
            }

            // Does not generate vertices for whitespace
            if (c == ' ')
            {
                pos_x += wsAdvance;
                continue;
            }

            // Adds four spaces instead of the tab
            if (c == '\t')
            {
                pos_x += (wsAdvance * 4);
                continue;
            }


            // Adds the outline vertices
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


            // Retrieves the regular glyph and its boundaries
            if (!m_Font->isCached(c, regular))
                m_Font->cacheGlyph(c, regular);

            const Glyph &glyph = m_Font->glyph(c, regular);
            QFloat x = pos_x + glyph.bearing_x, w = x + glyph.glyph_w;
            QFloat y = pos_y + glyph.bearing_y, h = y + glyph.glyph_h;
            QFloat u = glyph.texture_x, v = glyph.texture_y;
            QFloat s = u + glyph.texture_w, t = v + glyph.texture_h;

            // Adds the drop shadow vertices
            if (style & TextStyle::DropShadow)
            {
                QFloat dx = x + m_ShadowX, dw = w + m_ShadowX;
                QFloat dy = y + m_ShadowY, dh = h + m_ShadowY;

                shadowVertices.push_back(dx); shadowVertices.push_back(dy);
                shadowVertices.push_back(u);  shadowVertices.push_back(v);
                shadowVertices.push_back(dw); shadowVertices.push_back(dy);
                shadowVertices.push_back(s);  shadowVertices.push_back(v);
                shadowVertices.push_back(dx); shadowVertices.push_back(dh);
                shadowVertices.push_back(u);  shadowVertices.push_back(t);
                shadowVertices.push_back(dx); shadowVertices.push_back(dh);
                shadowVertices.push_back(u);  shadowVertices.push_back(t);
                shadowVertices.push_back(dw); shadowVertices.push_back(dy);
                shadowVertices.push_back(s);  shadowVertices.push_back(v);
                shadowVertices.push_back(dw); shadowVertices.push_back(dh);
                shadowVertices.push_back(s);  shadowVertices.push_back(t);
            }


            // Adds the normal glyph vertices
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

            pos_x += glyph.advance;
            pos_x += m_Font->kerning(prevChar, c);
            prevChar = c;
        }

        if (style & TextStyle::Underline)
            Qube2D_Text_Add_Line(vertices, { 0, pos_y + sp_line, pos_x, m_LineWidth });
        if (style & TextStyle::Strikethrough)
            Qube2D_Text_Add_Line(vertices, { 0, pos_y + strikeY, pos_x, m_LineWidth });


        // Dynamically determines the vertex count
        m_OutlineVertexCount = outlineVertices.size() / 4;
        m_ShadowVertexCount = shadowVertices.size() / 4;
        m_VertexCount = vertices.size() / 4;

        // Combines all the vertices into one buffer
        vertices.insert(vertices.end(), outlineVertices.begin(), outlineVertices.end());
        vertices.insert(vertices.end(), shadowVertices.begin(), shadowVertices.end());

        // Buffers the generated data
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

        // Forwards the MVP matrix to the shader
        glCheck(glUniformMatrix4fv(m_UniformMatrix, 1, GL_FALSE, &mvp[0][0]));


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


        // Renders the drop shadow first
        if (m_Style & TextStyle::DropShadow)
        {
            float alpha = std::max(0.1f, m_Color.a()-0.5f);
            glCheck(glUniform4f(m_UniformColor,
                                m_Color.r(),
                                m_Color.g(),
                                m_Color.b(),
                                m_Color.a()));

            glCheck(glUniform1f(m_UniformOpacity, alpha));
            glCheck(glDrawArrays(
                        GL_TRIANGLES,
                        m_VertexCount+m_OutlineVertexCount,
                        m_ShadowVertexCount));
        }

        // Forwards the opacity to the shader
        glCheck(glUniform1f(m_UniformOpacity, opacity()));

        // Renders the outlines
        if (m_Style & TextStyle::Outline)
        {
            glCheck(glUniform4f(m_UniformColor,
                                m_OutlineColor.r(),
                                m_OutlineColor.g(),
                                m_OutlineColor.b(),
                                m_OutlineColor.a()));

            glCheck(glDrawArrays(
                        GL_TRIANGLES,
                        m_VertexCount,
                        m_OutlineVertexCount));
        }


        // Writes the uniform color values
        glCheck(glUniform4f(m_UniformColor,
                            m_Color.r(),
                            m_Color.g(),
                            m_Color.b(),
                            m_Color.a()));

        // Renders the regular glyphs
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


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 17th, 2016
    /// \fn      Qube2D_Text_Add_Line
    ///
    ///////////////////////////////////////////////////////////
    void Qube2D_Text_Add_Line(std::vector<float> &v, const RectF &bounds)
    {
        QFloat x = bounds.x(),          w = x + bounds.width();
        QFloat y = roundf(bounds.y()),  h = y + bounds.height();

        v.push_back(x); v.push_back(y); v.push_back(1); v.push_back(1);
        v.push_back(w); v.push_back(y); v.push_back(1); v.push_back(1);
        v.push_back(x); v.push_back(h); v.push_back(1); v.push_back(1);
        v.push_back(x); v.push_back(h); v.push_back(1); v.push_back(1);
        v.push_back(w); v.push_back(y); v.push_back(1); v.push_back(1);
        v.push_back(w); v.push_back(h); v.push_back(1); v.push_back(1);
    }
}
