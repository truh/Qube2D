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
#include <Qube2D/Graphics/OpenGL/GLErrors.hpp>
#include <Qube2D/Graphics/OpenGL/ShaderProgram.hpp>
#include <glad/glad.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    ShaderProgram::ShaderProgram()
        : m_ID(0)
    {
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::create()
    {
        glCheck(m_ID = glCreateProgram());
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::destroy()
    {
        glCheck(glDeleteProgram(m_ID));
        m_ID = 0;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      id -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 ShaderProgram::id() const
    {
        return m_ID;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      addShader
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::addShader(const Shader &shader)
    {
        glCheck(glAttachShader(m_ID, shader.id()));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      removeShader
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::removeShader(const Shader &shader)
    {
        glCheck(glDetachShader(m_ID, shader.id()));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::link()
    {
        // Attempts to link the program
        glCheck(glLinkProgram(m_ID));
        
        
        // Determines whether an error occured
        int success = GL_FALSE;
        glCheck(glGetProgramiv(m_ID, GL_LINK_STATUS, &success));
        
        if (success == GL_FALSE)
        {
            // Collects error information
            char log[1024];
            glCheck(glGetProgramInfoLog(m_ID, 1024, &success, log));
            Q2DErrorNoArg(log);
        }
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      use
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::bind()
    {
        glCheck(glUseProgram(m_ID));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      unbind
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::unbind()
    {
        glCheck(glUseProgram(0));
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      bindLocation
    ///
    ///////////////////////////////////////////////////////////
    void ShaderProgram::bindLocation(const char *var, QUInt32 index)
    {
        glCheck(glBindAttribLocation(m_ID, index, var));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      getLocation -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 ShaderProgram::getLocation(const char *var) const
    {
        QInt32 index;
        glCheck(index = glGetAttribLocation(m_ID, var));
        return static_cast<QUInt32>(index);
    }    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      getUniformLocation -> const
    ///
    ///////////////////////////////////////////////////////////
    QInt32 ShaderProgram::getUniformLocation(const char *uni) const
    {
        QInt32 index;
        glCheck(index = glGetUniformLocation(m_ID, uni));
        return index;
    }
}
