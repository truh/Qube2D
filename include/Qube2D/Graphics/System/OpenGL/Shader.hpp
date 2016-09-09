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


#ifndef __Q2D_SHADER_HPP__
#define __Q2D_SHADER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Graphics/System/OpenGL/GLEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Shader.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \class   Shader
    /// \brief   Wraps an OpenGL vertex or fragment shader.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Shader
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new Qube2D::Shader.
        ///
        ///////////////////////////////////////////////////////////
        Shader();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Allocates a new OpenGL shader object.
        /// \param  type One of the ShaderType values
        ///
        ///////////////////////////////////////////////////////////
        void create(ShaderType type);

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Frees this OpenGL shader object.
        ///
        ///////////////////////////////////////////////////////////
        void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn       id -> const
        /// \brief    Retrieves the shader ID within OpenGL.
        /// \returns  the non-zero shader ID.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 id() const;


        ///////////////////////////////////////////////////////////
        /// \fn     compileFromFile
        /// \brief  Compiles the shader written in a file.
        /// \param  path Absolute path or asset path to ASCII file
        ///
        ///////////////////////////////////////////////////////////
        void compileFromFile(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn     compileFromString
        /// \brief  Compiles the shader specified as ASCII string.
        /// \param  code ASCII string containing shader code
        ///
        ///////////////////////////////////////////////////////////
        void compileFromString(const char *code);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt32 m_ID;       ///< Shader ID within OpenGL
        QUInt32 m_Type;     ///< Type of the shader

    };
}


#endif  // __Q2D_SHADER_HPP__
