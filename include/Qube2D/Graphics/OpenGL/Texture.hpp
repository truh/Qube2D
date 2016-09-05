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


#ifndef __Q2D_TEXTURE_HPP__
#define __Q2D_TEXTURE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Structs/Rect.hpp>
#include <Qube2D/System/Structs/Color.hpp>
#include <Qube2D/Graphics/OpenGL/GLEnums.hpp>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Texture.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 19th, 2016
    /// \class   Texture
    /// \brief   Wraps an OpenGL 2D texture.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Texture
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new Qube2D::Texture.
        ///
        ///////////////////////////////////////////////////////////
        Texture();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Creates a new texture with a single color.
        /// \param  width Width of the texture to create
        /// \param  height Height of the texture to create
        /// \param  format Internal OpenGL image format
        /// \param  color Color to fill texture with (default=black)
        ///
        ///////////////////////////////////////////////////////////
        void create(int width,
                    int height,
                    TextureFormat format,
                    Color color = Color());

        ///////////////////////////////////////////////////////////
        /// \fn     createFromFile
        /// \brief  Loads a PNG image and converts it to a texture.
        /// \param  path Absolute file path or asset path
        ///
        ///////////////////////////////////////////////////////////
        void createFromFile(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn     createFromMemory
        /// \brief  Loads an image from memory and converts it.
        /// \param  bytes PNG image as raw byte data
        /// \param  size Size of the given data array
        ///
        ///////////////////////////////////////////////////////////
        void createFromMemory(const QUInt8 *bytes, QUInt32 size);

        ///////////////////////////////////////////////////////////
        /// \fn      destroy
        /// \brief   Frees the OpenGL texture.
        /// \remark  Allocate a texture using Texture::create,
        ///          Texture::createFromFile or
        ///          Texture::createFromMemory.
        ///
        ///////////////////////////////////////////////////////////
        void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn     bind
        /// \brief  Binds this texture to the current context.
        ///
        ///////////////////////////////////////////////////////////
        void bind();

        ///////////////////////////////////////////////////////////
        /// \fn     unbind
        /// \brief  Unbinds this texture from the current context.
        /// \note   Unbinds any texture that is currently bound.
        ///
        ///////////////////////////////////////////////////////////
        void unbind();


        ///////////////////////////////////////////////////////////
        /// \fn       id -> const
        /// \brief    Retrieves the texture ID within OpenGL.
        /// \returns  the non-zero texture ID.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 id() const;

        ///////////////////////////////////////////////////////////
        /// \fn       width -> const
        /// \brief    Retrieves the width of this texture.
        /// \returns  the width of the texture, in pixels.
        ///
        ///////////////////////////////////////////////////////////
        QFloat width() const;

        ///////////////////////////////////////////////////////////
        /// \fn       height -> const
        /// \brief    Retrieves the height of this texture.
        /// \returns  the height of the texture, in pixels.
        ///
        ///////////////////////////////////////////////////////////
        QFloat height() const;


        ///////////////////////////////////////////////////////////
        /// \fn      setMagFilter
        /// \brief   Specifies the magnifying filter/interpolation.
        /// \param   filter One of the InterpolationMode values
        ///
        ///////////////////////////////////////////////////////////
        void setMagFilter(InterpolationMode filter);

        ///////////////////////////////////////////////////////////
        /// \fn     setMinFilter
        /// \brief  Specifies the minifying filter/interpolation.
        /// \param  filter One of the InterpolationMode values
        ///
        ///////////////////////////////////////////////////////////
        void setMinFilter(InterpolationMode filter);

        ///////////////////////////////////////////////////////////
        /// \fn     setVerticalWrap
        /// \brief  Specifies the vertical wrap.
        ///
        /// Wrapping always occurs if one of the texture coordinates
        /// exceed the texture's bounds.
        ///
        /// \param  wrap One of the WrapMode values
        ///
        ///////////////////////////////////////////////////////////
        void setVerticalWrap(WrapMode wrap);

        ///////////////////////////////////////////////////////////
        /// \fn     setHorizontalWrap
        /// \brief  Specifies the horizontal wrap.
        ///
        /// Wrapping always occurs if one of the texture coordinates
        /// exceed the texture's bounds.
        ///
        /// \param  wrap One of the WrapMode values
        ///
        ///////////////////////////////////////////////////////////
        void setHorizontalWrap(WrapMode wrap);


        ///////////////////////////////////////////////////////////
        /// \fn      updatePixels
        /// \brief   Updates the pixels of the texture.
        /// \param   data Raw pixel data to store
        /// \param   rect Part of the texture to update
        /// \param   format Format of the given pixel data
        ///
        ///////////////////////////////////////////////////////////
        void updatePixels(const QUInt8 *data,
                          const RectI &rect,
                          TextureFormat format);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt32 m_ID;           ///< Texture ID within OpenGL
        QFloat  m_Width;        ///< Width of the texture in pixels
        QFloat  m_Height;       ///< Height of the texture in pixels
        QUInt32 m_Format;       ///< Texture format within OpenGL

    };
}


#endif  // __Q2D_TEXTURE_HPP__
