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
#include <Qube2D/Graphics/Base/ISprite.hpp>
#include <Qube2D/Graphics/Shader/TextureShaders.hpp>
#include <Qube2D/System/Structs/GLColor.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Constant definitions
    //
    ///////////////////////////////////////////////////////////
    #define IMAGE_VERTEX_SIZE       sizeof(float) * 32
    #define IMAGE_SINGLE_VERTEX     sizeof(float) * 8
    #define IMAGE_OFFSET_COORD      (const void *)(sizeof(float) * 2)
    #define IMAGE_OFFSET_BLEND      (const void *)(sizeof(float) * 4)

    ///////////////////////////////////////////////////////////
    // Static class member definitions
    //
    ///////////////////////////////////////////////////////////
    VertexArray ISprite::m_VertexArray;
    VertexBuffer ISprite::m_IndexBuffer;
    ShaderProgram ISprite::m_ShaderProgram;
    Shader ISprite::m_VertexShader;
    Shader ISprite::m_FragShader;
    QInt32 ISprite::m_UniformSampler;
    QInt32 ISprite::m_UniformMatrix;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    ISprite::ISprite() : m_CustomProgram(NULL)
    {
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::create()
    {
        m_CustomProgram = &m_ShaderProgram;
        m_VertexBuffer.create(BufferType::Vertex,
                              BufferUsage::Dynamic);               
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::destroy()
    {
        m_VertexBuffer.destroy();
        m_Texture.destroy();
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      load
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::load(const char *path)
    { 
        m_Texture.createFromFile(path);
        m_Texture.setMinFilter(InterpolationMode::NearestNeighbor);
        m_Texture.setMagFilter(InterpolationMode::NearestNeighbor);
        setSourceRectangle({ 0.f, 0.f, m_Texture.width(), m_Texture.height() });
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      load (overload #1)
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::load(const Texture &texture)
    {
        m_Texture = texture;
        m_Texture.bind();
        m_Texture.setMinFilter(InterpolationMode::NearestNeighbor);
        m_Texture.setMagFilter(InterpolationMode::NearestNeighbor);
        setSourceRectangle({ 0.f, 0.f, m_Texture.width(), m_Texture.height() });
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setSourceRectangle
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::setSourceRectangle(const RectF &rect)
    {
        // Pre-calculates OpenGL vertex positions and UV coords
        float tex_w = rect.width();
        float tex_h = rect.height();
        float rel_x = rect.x() / tex_w;
        float rel_y = rect.y() / tex_h;
        float rel_w = rel_x + (tex_w / m_Texture.width());
        float rel_h = rel_y + (tex_h / m_Texture.height());
        
        // Modifies the XY data
        m_Vertices.v0.xy(0.f,   0.f);
        m_Vertices.v1.xy(tex_w, 0.f);
        m_Vertices.v2.xy(tex_w, tex_h);
        m_Vertices.v3.xy(0.f,   tex_h);
        
        // Modifies the UV data
        m_Vertices.v0.uv(rel_x, rel_y);
        m_Vertices.v1.uv(rel_w, rel_y);
        m_Vertices.v2.uv(rel_w, rel_h);
        m_Vertices.v3.uv(rel_x, rel_h);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setBlendColor
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::setBlendColor(const Color &color)
    {
        GLColor glc = color.toGL();
        
        // Pre-fetches the color components
        float r = glc.r();
        float g = glc.g();
        float b = glc.b();
        float a = glc.a();
        
        // Modifies the RGBA data
        m_Vertices.v0.rgba(r, g, b, a);
        m_Vertices.v1.rgba(r, g, b, a);
        m_Vertices.v2.rgba(r, g, b, a);
        m_Vertices.v3.rgba(r, g, b, a);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setBlendColorEx
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::setBlendColorEx(const Color &topLeft,
                                const Color &topRight,
                                const Color &bottomRight,
                                const Color &bottomLeft)
    {
        GLColor tl = topLeft.toGL();
        GLColor tr = topRight.toGL();
        GLColor br = bottomRight.toGL();
        GLColor bl = bottomLeft.toGL();
        
        // Modifies the RGBA data
        m_Vertices.v0.rgba(tl.r(), tl.g(), tl.b(), tl.a());
        m_Vertices.v1.rgba(tr.r(), tr.g(), tr.b(), tr.a());
        m_Vertices.v2.rgba(br.r(), br.g(), br.b(), br.a());
        m_Vertices.v3.rgba(bl.r(), bl.g(), bl.b(), bl.a());
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setOpacity
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::setOpacity(QFloat opacity)
    {
        if (opacity == 1.f)
            return;
        
        m_Vertices.v0.a = opacity;
        m_Vertices.v1.a = opacity;
        m_Vertices.v2.a = opacity;
        m_Vertices.v3.a = opacity;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setBlendMode
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::setBlendMode(BlendMode mode)
    {
        m_BlendMode = mode;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setCustomShaderProgram
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::setCustomShaderProgram(ShaderProgram *program)
    {
        if (program)
            m_CustomProgram = program;
        else
            m_CustomProgram = &m_ShaderProgram;
        
        m_CustomProgram->bind();
        m_UniformMatrix = m_CustomProgram->getUniformLocation("uni_mvp");
        m_UniformSampler = m_CustomProgram->getUniformLocation("uni_texture");
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      render
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::render()
    {
        // Constructs the MVP matrix
        //glm::mat4 projection = glm::ortho(0.f, m_WinWidth, m_WinHeight, 0.f);
        //glm::mat4 translation = glm::translate(glm::vec3(m_Translation.x(), m_Translation.y()));
        //glm::mat4 identity = glm::mat4(1.f);
        //glm::mat4 mvp = projection * translation * identity;
        
        // Temporary hack before implementing IMovable and IFadable
        glm::mat4 identity = glm::mat4(1.f);
        glm::mat4 projection = glm::ortho(0.f, 600.f, 400.f, 0.f);
        glm::mat4 mvp = projection * identity;
        
        
        // Binds all necessary objects
        m_VertexArray.bind();
        m_IndexBuffer.bind();
        m_VertexBuffer.bind();       
        m_CustomProgram->bind();
        
        
        // Buffers the vertex data
        m_VertexBuffer.fill(&m_Vertices, IMAGE_VERTEX_SIZE);
        
        // Binds the texture to unit 0
        glCheck(glActiveTexture(GL_TEXTURE0));
        m_Texture.bind();
        glCheck(glUniform1i(m_UniformSampler, 0));
        
        // Forwards the MVP matrix to the shader
        glCheck(glUniformMatrix4fv(m_UniformMatrix, 1, GL_FALSE, &mvp[0][0]));
        
        
        // Enables all the used vertex attributes
        m_VertexArray.enableAttrib(0);
        m_VertexArray.enableAttrib(1);
        m_VertexArray.enableAttrib(2);
        
        // Specifies the vertex attributes
        glCheck(glVertexAttribPointer(
                    0,
                    2,
                    GL_FLOAT,
                    GL_FALSE,
                    IMAGE_SINGLE_VERTEX,
                    NULL));   

        glCheck(glVertexAttribPointer(
                    1,
                    2,
                    GL_FLOAT,
                    GL_FALSE,
                    IMAGE_SINGLE_VERTEX,
                    IMAGE_OFFSET_COORD));

        glCheck(glVertexAttribPointer(
                    2,
                    4,
                    GL_FLOAT,
                    GL_FALSE,
                    IMAGE_SINGLE_VERTEX,
                    IMAGE_OFFSET_BLEND));
        
        // Renders the texture
        glCheck(glDrawElements(
                    GL_TRIANGLES,
                    6,
                    GL_UNSIGNED_INT,
                    NULL));
        
        
        // Disables all the used vertex attributes
        m_VertexArray.disableAttrib(2);
        m_VertexArray.disableAttrib(1);
        m_VertexArray.disableAttrib(0);       
        
        // Unbinds the necessary objects
        m_Texture.unbind();
        m_VertexArray.unbind();
        m_IndexBuffer.unbind();
        m_VertexBuffer.unbind();
        m_CustomProgram->unbind();
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      initializeGL
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::initializeGL()
    {
        const QUInt32 indices[6] = { 0u, 1u, 2u, 2u, 3u, 0u };
        
        m_VertexArray.create();
        m_ShaderProgram.create();       
        m_VertexShader.create(ShaderType::Vertex);
        m_FragShader.create(ShaderType::Fragment);
        
        m_VertexShader.compileFromString(Qube2D_TextureVertexShader);
        m_FragShader.compileFromString(Qube2D_TextureFragShader);
        m_ShaderProgram.addShader(m_VertexShader);
        m_ShaderProgram.addShader(m_FragShader);
        m_ShaderProgram.link();
        m_ShaderProgram.bind();
        
        m_UniformMatrix = m_ShaderProgram.getUniformLocation("uni_mvp");
        m_UniformSampler = m_ShaderProgram.getUniformLocation("uni_texture");
        
        m_IndexBuffer.create(BufferType::Index, BufferUsage::Static);
        m_IndexBuffer.bind();
        m_IndexBuffer.fill(indices, sizeof(QUInt32) * 6);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      destroyGL
    ///
    ///////////////////////////////////////////////////////////
    void ISprite::destroyGL()
    {
        m_IndexBuffer.destroy();
        m_VertexShader.destroy();
        m_FragShader.destroy();
        m_ShaderProgram.destroy();
        m_VertexArray.destroy();
    }
}
