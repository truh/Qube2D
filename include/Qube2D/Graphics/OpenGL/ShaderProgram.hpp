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


#ifndef __Q2D_SHADERPROGRAM_HPP__
#define __Q2D_SHADERPROGRAM_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Graphics/OpenGL/Shader.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    ShaderProgram.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 20th, 2016
    /// \class   ShaderProgram
    /// \brief   Wraps an OpenGL shader program.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API ShaderProgram
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new Qube::ShaderProgram.
        ///
        ///////////////////////////////////////////////////////////
        ShaderProgram();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Allocates a new OpenGL shader program.
        ///
        ///////////////////////////////////////////////////////////
        void create();

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Frees this OpenGL shader program.
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
        /// \fn     addShader
        /// \brief  Attaches a shader to this program.
        /// \param  shader Shader object to attach
        ///
        ///////////////////////////////////////////////////////////
        void addShader(const Shader &shader);

        ///////////////////////////////////////////////////////////
        /// \fn     removeShader
        /// \brief  Detaches the given shader from this program.
        /// \param  shader Shader object to detach
        ///
        ///////////////////////////////////////////////////////////
        void removeShader(const Shader &shader);

        ///////////////////////////////////////////////////////////
        /// \fn      link
        /// \brief   Links the attached shaders to the program.
        /// \remark  After calling this function, the program may
        ///          be bound by using ShaderProgram::bind.
        ///
        ///////////////////////////////////////////////////////////
        void link();

        ///////////////////////////////////////////////////////////
        /// \fn     bind
        /// \brief  Uses this program for OpenGL related rendering.
        ///
        ///////////////////////////////////////////////////////////
        void bind();

        ///////////////////////////////////////////////////////////
        /// \fn     unbind
        /// \brief  Does not use this program for rendering anymore.
        /// \note   In fact, unbinds any currently bound program.
        ///
        ///////////////////////////////////////////////////////////
        void unbind();


        ///////////////////////////////////////////////////////////
        /// \fn     bindLocation
        /// \brief  Associates a variable with an index.
        /// \param  var Name of the variable
        /// \param  index New index to use for this variable
        ///
        ///////////////////////////////////////////////////////////
        void bindLocation(const char *var, QUInt32 index);

        ///////////////////////////////////////////////////////////
        /// \fn       getLocation -> const
        /// \brief    Retrieves the location of a variable.
        /// \param    var Name of variable to retrieve index from
        /// \returns  the location of the given variable.
        /// \remarks  This method should not be used for >= GL 3.3;
        ///           use 'layout(location = X) in VAR' instead.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 getLocation(const char *var) const;

        ///////////////////////////////////////////////////////////
        /// \fn       getUniformLocation -> const
        /// \brief    Retrieves the location of an uniform variable.
        /// \param    uni Name of the uniform variable
        /// \returns  the location of the given uniform variable.
        /// \remarks  This method has to be used for uniform vars,
        ///           because they do not support 'layout' yet.
        ///
        ///////////////////////////////////////////////////////////
        QInt32 getUniformLocation(const char *uni) const;


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt32 m_ID;   ///< Shader program ID within OpenGL

    };
}


#endif  // __Q2D_SHADERPROGRAM_HPP__
