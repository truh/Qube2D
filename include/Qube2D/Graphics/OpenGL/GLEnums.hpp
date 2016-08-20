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


#ifndef __Q2D_GLENUMS_HPP__
#define __Q2D_GLENUMS_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    GLEnums.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    ///
    ///////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////
    /// \enum   BufferType
    /// \brief  Defines types for OpenGL buffers.
    /// 
    ///////////////////////////////////////////////////////////
    enum class BufferType : unsigned int
    {
        Vertex  = 0x8892,   ///< Normal buffer for vertices
        Index   = 0x8893    ///< Buffer for vertex indices
    };
    
    ///////////////////////////////////////////////////////////
    /// \enum   BufferType
    /// \brief  Defines types for OpenGL buffers.
    /// 
    ///////////////////////////////////////////////////////////
    enum class BufferUsage : unsigned int
    {
        Static  = 0x88E4,   ///< Static draw
        Dynamic = 0x88E8    ///< Dynamic draw
    };
    
    ///////////////////////////////////////////////////////////
    /// \enum   TextureFormat
    /// \brief  Defines imaging formats for the texture.
    /// 
    ///////////////////////////////////////////////////////////
    enum class TextureFormat : unsigned int
    {
        FormatRED       = 0x1903,   ///< 8-bits
        FormatRG        = 0x8227,   ///< 16-bits
        FormatRGB       = 0x1907,   ///< 24-bits
        FormatRGBA      = 0x1908,   ///< 32-bits
        FormatBGR       = 0x80E0,   ///< 24-bits (reversed)
        FormatBGRA      = 0x80E1    ///< 32-bits (reversed)
    };
    
    ///////////////////////////////////////////////////////////
    /// \enum   InterpolationMode
    /// \brief  Defines magnifying/minifying filter modes.
    /// 
    ///////////////////////////////////////////////////////////
    enum class InterpolationMode : unsigned int
    {
        NearestNeighbor         = 0x2600,   ///< No anti-aliasing
        LinearInterpolation     = 0x2601,   ///< Anti-aliasing
        Nearest_Mipmap_Nearest  = 0x2700,   ///< Closely match textured pixel (no aa)
        Linear_Mipmap_Nearest   = 0x2701,   ///< Closely match textured pixel (aa)
        Nearest_Mipmap_Linear   = 0x2702,   ///< Average of two mipmaps (no aa)
        Linear_Mipmap_Linear    = 0x2703    ///< Average of two mipmaps (aa)
    };
    
    ///////////////////////////////////////////////////////////
    /// \enum   WrapMode
    /// \brief  Defines texture wrapping modes.
    /// 
    ///////////////////////////////////////////////////////////
    enum class WrapMode : unsigned int
    {
        Clamp           = 0x2900,   ///< No wrapping used (with border)
        Repeat          = 0x2901,   ///< Repeat texture
        ClampToEdge     = 0x812F,   ///< No wrapping used (w.o. border)
        ClampToBorder   = 0x812D,   ///< No wrapping used (outside border)
        RepeatMirrored  = 0x8370    ///< Repeat texture flipped
    };
    
    ///////////////////////////////////////////////////////////
    /// \enum   ShaderType
    /// \brief  Defines several shader kinds.
    /// 
    ///////////////////////////////////////////////////////////
    enum class ShaderType : unsigned int
    {
        Vertex      = 0x8B31,       ///< Computes vertex positions
        Fragment    = 0x8B30,       ///< Computes vertex output color
        Geometry    = 0x8DD9        ///< Modifies vertex count and more
    };
}


#endif  // __Q2D_GLENUMS_HPP__
