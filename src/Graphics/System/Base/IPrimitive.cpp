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
#include <Qube2D/Debug/Debug.hpp>
#include <Qube2D/Debug/GLCheck.hpp>
#include <Qube2D/Graphics/System/Base/IPrimitive.hpp>
#include <Qube2D/Graphics/System/Shader/PrimitiveShaders.hpp>
#include <Qube2D/System/Structs/GLColor.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Constant definitions
    //
    ///////////////////////////////////////////////////////////
    #define PRIMITIVE_SINGLE_VERTEX     sizeof(float) * 6
    #define PRIMITIVE_OFFSET_BLEND      (const void *)(sizeof(float) * 2)

    ///////////////////////////////////////////////////////////
    // Static class member definitions
    //
    ///////////////////////////////////////////////////////////
    VertexArray IPrimitive::m_VertexArray;
    ShaderProgram IPrimitive::m_ShaderProgram;
    Shader IPrimitive::m_VertexShader;
    Shader IPrimitive::m_FragShader;
    QInt32 IPrimitive::m_UniformMatrix;
    QInt32 IPrimitive::m_UniformOpacity;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    IPrimitive::IPrimitive() : m_CustomProgram(NULL)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::create()
    {
        m_CustomProgram = &m_ShaderProgram;
        m_VertexBuffer.create(BufferType::Vertex,
                              BufferUsage::Dynamic);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::destroy()
    {
        m_VertexBuffer.destroy();
        m_Vertices.v.clear();
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      setVertexCount
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::setVertexCount(QUInt32 count)
    {
        assert(count != 0);

        for (QUInt32 i = 0; i < count; i++)
            m_Vertices.add(PrimitiveVertex());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      setVertexColors
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::setVertexColors(const std::vector<Color> &colors)
    {
        assert(colors.size() != m_Vertices.size() &&
               colors.size() != 1);

        if (colors.size() == 1)
        {
            GLColor c = colors.at(0).toGL();
            QFloat  r = c.r();
            QFloat  g = c.g();
            QFloat  b = c.b();
            QFloat  a = c.a();

            for (QUInt32 i = 0; i < colors.size(); i++)
                m_Vertices.v[i].rgba(r, g, b, a);
        }
        else
        {
            for (QUInt32 i = 0; i < colors.size(); i++)
            {
                GLColor c = colors.at(i).toGL();
                m_Vertices.v[i].rgba(c.r(), c.g(), c.b(), c.a());
            }
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      setCustomShaderProgram
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::setCustomShaderProgram(ShaderProgram *program)
    {
        if (program)
            m_CustomProgram = program;
        else
            m_CustomProgram = &m_ShaderProgram;

        m_CustomProgram->bind();
        m_UniformMatrix = m_CustomProgram->getUniformLocation("uni_mvp");
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      update
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::update(double deltaTime)
    {
        updateFade(deltaTime);
        updateMovement(deltaTime);
        updateRotation(deltaTime);
        updateScaling(deltaTime);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      render
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::render()
    {
        // Constructs the MVP matrix
        glm::mat4 identity      = glm::mat4(1.f);
        glm::mat4 projection    = glm::ortho(0.f, m_WinW, m_WinH, 0.f);
        glm::mat4 translation   = glm::translate(identity, glm::vec3(m_PosX, m_PosY, 0.f));
        glm::mat4 origin        = glm::translate(identity, glm::vec3(-m_OriginX, -m_OriginY, 0.f));
        glm::mat4 rotation      = glm::rotate(identity, glm::radians(m_Angle), glm::vec3(0.f, 0.f, 1.f));
        glm::mat4 iorigin       = glm::translate(identity, glm::vec3(m_OriginX, m_OriginY, 0.f));
        glm::mat4 scaling       = glm::scale(identity, glm::vec3(m_Scale, m_Scale, 1.f));
        glm::mat4 mvp           = projection * translation * iorigin * rotation * origin * scaling * identity;


        // Binds all necessary objects
        m_VertexArray.bind();
        m_VertexBuffer.bind();
        m_CustomProgram->bind();


        // Buffers the vertex data
        m_VertexBuffer.fill(m_Vertices.ptr(), m_Vertices.size() * PRIMITIVE_SINGLE_VERTEX);

        // Forwards the MVP matrix and the opacity to the shader
        glCheck(glUniformMatrix4fv(m_UniformMatrix, 1, GL_FALSE, &mvp[0][0]));
        glCheck(glUniform1f(m_UniformOpacity, m_Opacity));


        // Enables all the used vertex attributes
        m_VertexArray.enableAttrib(0);
        m_VertexArray.enableAttrib(1);

        // Specifies the vertex attributes
        glCheck(glVertexAttribPointer(
                    0,
                    2,
                    GL_FLOAT,
                    GL_FALSE,
                    PRIMITIVE_SINGLE_VERTEX,
                    NULL));

        glCheck(glVertexAttribPointer(
                    1,
                    4,
                    GL_FLOAT,
                    GL_FALSE,
                    PRIMITIVE_SINGLE_VERTEX,
                    PRIMITIVE_OFFSET_BLEND));

        // Renders the primitive
        glCheck(glDrawArrays(
                    m_DrawMode,
                    GL_ZERO,
                    m_Vertices.size()));


        // Disables all the used vertex attributes
        m_VertexArray.disableAttrib(1);
        m_VertexArray.disableAttrib(0);

        // Unbinds the necessary objects
        m_VertexArray.unbind();
        m_VertexBuffer.unbind();
        m_CustomProgram->unbind();
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      initializeGL
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::initializeGL()
    {
        m_VertexArray.create();
        m_ShaderProgram.create();
        m_VertexShader.create(ShaderType::Vertex);
        m_FragShader.create(ShaderType::Fragment);

        m_VertexShader.compileFromString(Qube2D_PrimitiveVertexShader);
        m_FragShader.compileFromString(Qube2D_PrimitiveFragShader);
        m_ShaderProgram.addShader(m_VertexShader);
        m_ShaderProgram.addShader(m_FragShader);
        m_ShaderProgram.link();
        m_ShaderProgram.bind();

        m_UniformMatrix = m_ShaderProgram.getUniformLocation("uni_mvp");
        m_UniformOpacity = m_ShaderProgram.getUniformLocation("uni_opacity");
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      destroyGL
    ///
    ///////////////////////////////////////////////////////////
    void IPrimitive::destroyGL()
    {
        m_VertexShader.destroy();
        m_FragShader.destroy();
        m_ShaderProgram.destroy();
        m_VertexArray.destroy();
    }
}
