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


#ifndef __Q2D_VERTEXARRAY_HPP__
#define __Q2D_VERTEXARRAY_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    VertexArray.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \class   VertexArray
    /// \brief   Wraps an OpenGL vertex array object.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API VertexArray
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new Qube2D::VertexArray.
        ///
        ///////////////////////////////////////////////////////////
        VertexArray();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Allocates a new OpenGL vertex array object.
        ///
        ///////////////////////////////////////////////////////////
        void create();

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Frees this OpenGL vertex array object.
        ///
        ///////////////////////////////////////////////////////////
        void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn       id -> const
        /// \brief    Retrieves the ID of this vertex array object.
        /// \returns  the non-zero ID of this VAO.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 id() const;


        ///////////////////////////////////////////////////////////
        /// \fn      bind
        /// \brief   Binds this VAO to the current context.
        /// \remark  Unbinds any previously bound VAO.
        ///
        ///////////////////////////////////////////////////////////
        void bind();

        ///////////////////////////////////////////////////////////
        /// \fn      unbind
        /// \brief   Unbinds this VAO from the current context.
        /// \remark  This function actually unbinds any VAO.
        ///
        ///////////////////////////////////////////////////////////
        void unbind();

        ///////////////////////////////////////////////////////////
        /// \fn       enableAttrib
        /// \brief    Enables the specified vertex attrib location.
        ///
        /// After calling this function, the specified attribute
        /// within the shader might be modified as desired.
        ///
        /// \param    location Location index of the variable
        /// \example  GLSL: layout(location = 0) in vec2 var;
        ///
        ///////////////////////////////////////////////////////////
        void enableAttrib(QUInt32 location);

        ///////////////////////////////////////////////////////////
        /// \fn     disableAttrib
        /// \brief  Disables the specified vertex attrib location.
        ///
        /// After calling this function, the specified attribute
        /// can not be modified anymore.
        ///
        /// \param  location Location index of the variable
        ///
        ///////////////////////////////////////////////////////////
        void disableAttrib(QUInt32 location);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt32 m_ID;   ///< VAO identifier within OpenGL

    };
}


#endif  // __Q2D_VERTEXARRAY_HPP__
