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
#include <Qube2D/Graphics/System/OpenGL/GLErrors.hpp>
#include <Qube2D/Graphics/System/OpenGL/Texture.hpp>
#include <Qube2D/System/Storage/File.hpp>
#include <Qube2D/Assets/Assets.hpp>
#include <Qube2D/Debug/GLCheck.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <lodepng/lodepng.h>
#include <glad/glad.h>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 28th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Texture::Texture() :
        m_ID(0),
        m_Width(0),
        m_Height(0),
        m_Format(0)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 28th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    void Texture::create(int width,
                         int height,
                         TextureFormat format,
                         Color color)
    {
        assert(m_ID == 0);
        assert(width%2 == 0);
        assert(height%2 == 0);


        // Creates an OpenGL texture
        glCheck(glGenTextures(1, &m_ID));
        glCheck(glBindTexture(GL_TEXTURE_2D, m_ID));

        // Generates the initial texture data
        QUInt8 red = color.r();
        QUInt8 green = color.g();
        QUInt8 blue = color.b();
        QUInt8 alpha = color.a();
        std::vector<QUInt8> pixelData;

        for (int i = 0; i < width*height; ++i)
        {
            if (format == TextureFormat::FormatRED)
            {
                pixelData.push_back(red);
            }
            else if (format == TextureFormat::FormatRG)
            {
                pixelData.push_back(red);
                pixelData.push_back(green);
            }
            else if (format == TextureFormat::FormatRGB)
            {
                pixelData.push_back(red);
                pixelData.push_back(green);
                pixelData.push_back(blue);
            }
            else if (format == TextureFormat::FormatBGR)
            {
                pixelData.push_back(blue);
                pixelData.push_back(green);
                pixelData.push_back(red);
            }
            else if (format == TextureFormat::FormatRGBA)
            {
                pixelData.push_back(red);
                pixelData.push_back(green);
                pixelData.push_back(blue);
                pixelData.push_back(alpha);
            }
            else if (format == TextureFormat::FormatBGRA)
            {
                pixelData.push_back(blue);
                pixelData.push_back(green);
                pixelData.push_back(red);
                pixelData.push_back(alpha);
            }
        }

        // Sets the pixel data within OpenGL
        glCheck(glTexImage2D(
                    GL_TEXTURE_2D, GL_NONE, static_cast<QUInt32>(format),
                    width, height, GL_NONE, static_cast<QUInt32>(format),
                    GL_UNSIGNED_BYTE, pixelData.data()));

        m_Width = static_cast<QFloat>(width);
        m_Height = static_cast<QFloat>(height);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 28th, 2016
    /// \fn      createFromFile
    ///
    ///////////////////////////////////////////////////////////
    bool Texture::createFromFile(const char *path)
    {
        assert(m_ID == 0 && path);

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
            return false;
        }


        // Creates the texture
        QUInt8 *bytes = file.readBytes(file.size());
        createFromMemory(bytes, file.size());
        delete [] bytes;
        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 28th, 2016
    /// \fn      createFromFile
    ///
    ///////////////////////////////////////////////////////////
    bool Texture::createFromMemory(const QUInt8 *bytes, QUInt32 size)
    {
        assert(m_ID == 0 && bytes);


        QUInt32 width, height;
        LodePNGState state;
        memset(&state, 0, sizeof(state));

        // Validates the given PNG image
        if (lodepng_inspect(&width, &height, &state, bytes, size))
        {
            Q2DErrorNoArg(Q2D_TEXTURE_ERROR_1);
            return false;
        }

        // Loads the PNG image
        QUInt32 colorType = 0;
        QUInt8 *pixelData = 0;
        if (state.info_png.color.colortype == LCT_GREY)
            colorType = GL_RED;
        else if (state.info_png.color.colortype == LCT_RGB)
            colorType = GL_RGB;
        else if (state.info_png.color.colortype == LCT_RGBA)
            colorType = GL_RGBA;

        lodepng_decode(&pixelData, &width, &height, &state, bytes, size);

        // Allocates an OpenGL texture
        glCheck(glGenTextures(1, &m_ID));
        glCheck(glBindTexture(GL_TEXTURE_2D, m_ID));
        glCheck(glTexImage2D(
                    GL_TEXTURE_2D, GL_NONE,
                    GL_RGBA,
                    static_cast<int>(width),
                    static_cast<int>(height), GL_NONE,
                    colorType,
                    GL_UNSIGNED_BYTE,
                    pixelData));

        m_Width = static_cast<QFloat>(width);
        m_Height = static_cast<QFloat>(height);

        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 28th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void Texture::destroy()
    {
        if (m_ID)
            glDeleteTextures(1, &m_ID);

        m_ID = 0;
        m_Width = 0;
        m_Height = 0;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      bind
    ///
    ///////////////////////////////////////////////////////////
    void Texture::bind()
    {
        glCheck(glBindTexture(GL_TEXTURE_2D, m_ID));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      unbind
    ///
    ///////////////////////////////////////////////////////////
    void Texture::unbind()
    {
        glCheck(glBindTexture(GL_TEXTURE_2D, 0));
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      id
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 Texture::id() const
    {
        return m_ID;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      width
    ///
    ///////////////////////////////////////////////////////////
    QFloat Texture::width() const
    {
        return m_Width;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      height
    ///
    ///////////////////////////////////////////////////////////
    QFloat Texture::height() const
    {
        return m_Height;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setMagFilter
    ///
    ///////////////////////////////////////////////////////////
    void Texture::setMagFilter(InterpolationMode filter)
    {
        glCheck(glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_MAG_FILTER,
                                static_cast<QUInt32>(filter)));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setMinFilter
    ///
    ///////////////////////////////////////////////////////////
    void Texture::setMinFilter(InterpolationMode filter)
    {
        glCheck(glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_MIN_FILTER,
                                static_cast<QUInt32>(filter)));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setVerticalWrap
    ///
    ///////////////////////////////////////////////////////////
    void Texture::setVerticalWrap(WrapMode wrap)
    {
        glCheck(glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_WRAP_T,
                                static_cast<QUInt32>(wrap)));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      setVerticalWrap
    ///
    ///////////////////////////////////////////////////////////
    void Texture::setHorizontalWrap(WrapMode wrap)
    {
        glCheck(glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_WRAP_S,
                                static_cast<QUInt32>(wrap)));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 1st, 2016
    /// \fn      updatePixels
    ///
    ///////////////////////////////////////////////////////////
    void Texture::updatePixels(const QUInt8 *data,
                               const RectI &rect,
                               TextureFormat format)
    {
        assert(data && m_ID);


        // Determines the unpacking alignment
        if (format == TextureFormat::FormatRED || format == TextureFormat::FormatRGB || format == TextureFormat::FormatBGR)
            glCheck(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
        else if (format == TextureFormat::FormatRG)
            glCheck(glPixelStorei(GL_UNPACK_ALIGNMENT, 2));
        else
            glCheck(glPixelStorei(GL_UNPACK_ALIGNMENT, 4));


        // Updates the pixel data
        glCheck(glBindTexture(GL_TEXTURE_2D, m_ID));
        glCheck(glTexSubImage2D(
                    GL_TEXTURE_2D, GL_NONE,
                    rect.x(), rect.y(),
                    rect.width(), rect.height(),
                    static_cast<QUInt32>(format),
                    GL_UNSIGNED_BYTE, data));
    }
}
