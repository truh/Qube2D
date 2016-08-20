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
#include <Qube2D/Debug/GLCheck.hpp>
#include <Qube2D/Assets/Assets.hpp>
#include <Qube2D/System/Storage/File.hpp>
#include <Qube2D/Graphics/OpenGL/Shader.hpp>
#include <Qube2D/Graphics/OpenGL/GLErrors.hpp>
#include <glad/glad.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Shader::Shader()
        : m_ID(0),
          m_Type(0)
    {
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void Shader::create(ShaderType type)
    {
        m_Type = static_cast<QUInt32>(type);
        glCheck(m_ID = glCreateShader(m_Type));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void Shader::destroy()
    {
        glCheck(glDeleteShader(m_ID));
        m_ID = 0;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      id -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 Shader::id() const
    {
        return m_ID;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      compileFromFile
    ///
    ///////////////////////////////////////////////////////////
    void Shader::compileFromFile(const char *path)
    {
        // Determines whether the given path is relative or absolute
        // and converts the relative to an absolute eventually.
        std::string filePath = path;
        if (Assets::isRelative(path))
            filePath = Assets::makePath(path);
        
        
        // Creates a new file handle
        File file;
        if (!file.open(path, FA_Read))
        {
            Q2DError(Q2D_SHADER_ERROR_0, filePath.c_str());
            return;
        }
        
        // Reads its content and compiles it as shader code
        compileFromString(file.readString(file.size()));     
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \fn      compileFromString
    ///
    ///////////////////////////////////////////////////////////
    void Shader::compileFromString(const char *code)
    {
        assert(code);
        
        
        // Specifies the source code and compiles it
        glCheck(glShaderSource(m_ID, 1, &code, NULL));
        glCheck(glCompileShader(m_ID));
        
        
        // Determines whether compilation succeeded
        int success = GL_FALSE;
        glCheck(glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success));
        
        if (success == GL_FALSE)
        {
            // Collects error information
            char log[1024];
            glCheck(glGetShaderInfoLog(m_ID, 1024, &success, log));
            Q2DErrorNoArg(log);
        }
    }
}
