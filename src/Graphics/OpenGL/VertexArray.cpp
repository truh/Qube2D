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
#include <Qube2D/Graphics/OpenGL/VertexArray.hpp>
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
    VertexArray::VertexArray()
        : m_ID(0)
    {
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void VertexArray::create()
    {
        glCheck(glGenVertexArrays(1, &m_ID));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void VertexArray::destroy()
    {
        glCheck(glDeleteVertexArrays(1, &m_ID));
        m_ID = 0;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      id -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 VertexArray::id() const
    {
        return m_ID;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      bind
    ///
    ///////////////////////////////////////////////////////////
    void VertexArray::bind()
    {
        glCheck(glBindVertexArray(m_ID));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      unbind
    ///
    ///////////////////////////////////////////////////////////
    void VertexArray::unbind()
    {
        glCheck(glBindVertexArray(0));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      enableAttrib
    ///
    ///////////////////////////////////////////////////////////
    void VertexArray::enableAttrib(QUInt32 location)
    {
        glCheck(glEnableVertexAttribArray(location));
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \fn      disableAttrib
    ///
    ///////////////////////////////////////////////////////////
    void VertexArray::disableAttrib(QUInt32 location)
    {
        glCheck(glDisableVertexAttribArray(location));
    }
}
