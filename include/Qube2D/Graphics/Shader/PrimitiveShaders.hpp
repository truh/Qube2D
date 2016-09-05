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


#ifndef __Q2D_PRIMITIVESHADER_HPP__
#define __Q2D_PRIMITIVESHADER_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    PrimitiveShader.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \var     Qube2D_PrimitiveVertexShader
    ///
    ///////////////////////////////////////////////////////////
    const char Qube2D_PrimitiveVertexShader[] =
    {
        "#version 330 core                          \n"
        "                                           \n"
        "layout(location = 0) in vec2 in_xy;        \n"
        "layout(location = 1) in vec4 in_rgba;      \n"
        "                                           \n"
        "out vec4 frag_rgba;                        \n"
        "uniform mat4 uni_mvp;                      \n"
        "                                           \n"
        "void main()                                \n"
        "{                                          \n"
        "   frag_rgba = in_rgba;                    \n"
        "   gl_Position = uni_mvp * vec4(           \n"
        "           in_xy,                          \n"
        "           0.0,                            \n"
        "           1.0);                           \n"
        "}                                          \n"

    };

    ///////////////////////////////////////////////////////////
    /// \file    PrimitiveShader.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \var     Qube2D_PrimitiveFragShader
    ///
    ///////////////////////////////////////////////////////////
    const char Qube2D_PrimitiveFragShader[] =
    {
        "#version 330 core                          \n"
        "                                           \n"
        "in vec4 frag_rgba;                         \n"
        "out vec4 out_color;                        \n"
        "uniform float uni_opacity;                 \n"
        "                                           \n"
        "void main()                                \n"
        "{                                          \n"
        "   vec4 v_opac =                           \n"
        "       vec4(1.0, 1.0, 1.0, uni_opacity);   \n"
        "   out_color = frag_rgba * v_opac;         \n"
        "}                                          \n"
    };
}


#endif  // __Q2D_PRIMITIVESHADER_HPP__
