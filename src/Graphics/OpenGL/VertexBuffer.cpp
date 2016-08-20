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
#include <Qube2D/Graphics/OpenGL/VertexBuffer.hpp>
#include <Qube2D/Debug/GLCheck.hpp>
#include <glad/glad.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    VertexBuffer::VertexBuffer()
        : m_ID(0)
    {
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void VertexBuffer::create(BufferType type, BufferUsage usage)
    {
        glCheck(glGenBuffers(1, &m_ID));
        m_Type  = static_cast<QUInt32>(type);
        m_Usage = static_cast<QUInt32>(usage);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void VertexBuffer::destroy()
    {
        glCheck(glDeleteBuffers(1, &m_ID));
        m_ID = 0;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      id -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 VertexBuffer::id() const
    {
        return m_ID;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      bind
    ///
    ///////////////////////////////////////////////////////////
    void VertexBuffer::bind()
    {
        glCheck(glBindBuffer(m_Type, m_ID));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      unbind
    ///
    ///////////////////////////////////////////////////////////
    void VertexBuffer::unbind()
    {
        glCheck(glBindBuffer(m_Type, 0));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      fill
    ///
    ///////////////////////////////////////////////////////////
    void VertexBuffer::fill(void *data, int size)
    {
        glCheck(glBufferData(m_Type, size, data, m_Usage));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      modify
    ///
    ///////////////////////////////////////////////////////////
    void VertexBuffer::modify(void *data, int src, int dst, int size)
    {
        glCheck(glBufferSubData(m_Type, dst, size, data+src));
    }
}
