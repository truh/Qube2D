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


#ifndef __Q2D_VERTEXBUFFER_HPP__
#define __Q2D_VERTEXBUFFER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Graphics/System/OpenGL/GLEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    VertexBuffer.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \class   VertexBuffer
    /// \brief   Wraps an OpenGL vertex buffer object.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API VertexBuffer
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new Qube2D::VertexBuffer.
        ///
        ///////////////////////////////////////////////////////////
        VertexBuffer();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Allocates a new OpenGL vertex buffer object.
        /// \param  type One of Qube2D::BufferType
        /// \param  usage One of Qube2D::BufferUsage
        ///
        ///////////////////////////////////////////////////////////
        void create(BufferType type, BufferUsage usage);

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Frees this OpenGL vertex buffer object.
        ///
        ///////////////////////////////////////////////////////////
        void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn       id -> const
        /// \brief    Retrieves the ID of this vertex buffer object.
        /// \returns  the non-zero ID of this VBO.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 id() const;


        ///////////////////////////////////////////////////////////
        /// \fn      bind
        /// \brief   Binds this VBO to the current context.
        /// \remark  Unbinds any previously bound VBO.
        ///
        ///////////////////////////////////////////////////////////
        void bind();

        ///////////////////////////////////////////////////////////
        /// \fn      unbind
        /// \brief   Unbinds this VBO from the current context.
        /// \remark  This function actually unbinds any VBO.
        ///
        ///////////////////////////////////////////////////////////
        void unbind();

        ///////////////////////////////////////////////////////////
        /// \fn       fill
        /// \brief    Fills this buffer with the given data.
        /// \param    data Data to store in the buffer
        /// \param    size Size to store, in bytes
        ///
        ///////////////////////////////////////////////////////////
        void fill(const void *data, int size);

        ///////////////////////////////////////////////////////////
        /// \fn     modify
        /// \brief  Modifies the buffer's contents.
        ///
        /// Same as fill, but this function allows to you specify
        /// a source and destination offset.
        ///
        /// \param  data Data to use
        /// \param  src Offset within 'data' to start copying from
        /// \param  dst Start offset within the buffer
        /// \param  size Amount of bytes to copy from 'data'
        ///
        ///////////////////////////////////////////////////////////
        void modify(void *data, int src, int dst, int size);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt32 m_ID;       ///< VBO identifier within OpenGL
        QUInt32 m_Type;     ///< Buffer type (vertex or index)
        QUInt32 m_Usage;    ///< Buffer usage (static or dynamic)

    };
}


#endif  // __Q2D_VERTEXBUFFER_HPP__
