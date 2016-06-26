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
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Storage/Variant.hpp>
#include <Qube2D/System/Debug.hpp>
#include <string>
#include <cstring>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Variant::Variant()
        : m_Type(VT_Invalid)
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Variant::Variant(const Variant &variant)
        : m_Buffer(variant.m_Buffer),
          m_Type(variant.m_Type)
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      Assignment operator
    ///
    ///////////////////////////////////////////////////////////
    Variant &Variant::operator =(const Variant &variant)
    {
        m_Buffer = variant.m_Buffer;
        m_Type = variant.m_Type;

        return *this;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromInt8
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromInt8(QInt8 s8)
    {
        m_Buffer.clear();
        m_Buffer.push_back(s8);
        m_Type = VT_Int8;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromInt16
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromInt16(QInt16 s16)
    {
        m_Buffer.clear();
        m_Buffer.push_back(static_cast<QInt8>(s16 & 0xFF));
        m_Buffer.push_back(static_cast<QInt8>(s16 << 0x8));
        m_Type = VT_Int16;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromInt32
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromInt32(QInt32 s32)
    {
        m_Buffer.clear();
        m_Buffer.push_back(static_cast<QInt8>(s32 & 0xFF));
        m_Buffer.push_back(static_cast<QInt8>(s32 << 0x8));
        m_Buffer.push_back(static_cast<QInt8>(s32 << 0x10));
        m_Buffer.push_back(static_cast<QInt8>(s32 << 0x18));
        m_Type = VT_Int32;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromInt64
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromInt64(QInt64 s64)
    {
        m_Buffer.clear();
        m_Buffer.push_back(static_cast<QInt8>(s64 & 0xFF));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x8));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x10));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x18));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x20));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x28));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x30));
        m_Buffer.push_back(static_cast<QInt8>(s64 << 0x38));
        m_Type = VT_Int64;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromString
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromString(const char *utf8)
    {
        m_Buffer = std::vector<QInt8>(utf8, utf8 + strlen(utf8)+1);
        m_Type = VT_Utf8;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromString (overload #1)
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromString(const char16_t *utf16)
    {
        std::u16string str(utf16);

        m_Buffer = std::vector<QInt8>(utf16, utf16 + (str.length()+1) * sizeof(char16_t));
        m_Type = VT_Utf16;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromString (overload #2)
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromString(const char32_t *utf32)
    {
        std::u32string str(utf32);

        m_Buffer = std::vector<QInt8>(utf32, utf32 + (str.length()+1) * sizeof(char32_t));
        m_Type = VT_Utf32;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromArray
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromArray(const QInt8 *v8, int size)
    {
        m_Buffer = std::vector<QInt8>(v8, v8 + size);
        m_Type = VT_PInt8;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromArray (overload #1)
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromArray(const QInt16 *v16, int size)
    {
        m_Buffer = std::vector<QInt8>(v16, v16 + size * sizeof(QInt16));
        m_Type = VT_PInt16;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromArray (overload #2)
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromArray(const QInt32 *v32, int size)
    {
        m_Buffer = std::vector<QInt8>(v32, v32 + size * sizeof(QInt32));
        m_Type = VT_PInt32;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromArray (overload #3)
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromArray(const QInt64 *v64, int size)
    {
        m_Buffer = std::vector<QInt8>(v64, v64 + size * sizeof(QInt64));
        m_Type = VT_PInt64;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromColor
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromColor(const Color &color)
    {
        m_Buffer.clear();
        m_Buffer.push_back(color.r());
        m_Buffer.push_back(color.g());
        m_Buffer.push_back(color.b());
        m_Buffer.push_back(color.a());
        m_Type = VT_Color;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromColor (overload #1)
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromColor(const GLColor &color)
    {
        m_Buffer.clear();
        m_Buffer.resize(4 * sizeof(float));

        ((float *)(m_Buffer.data()))[0] = color.r();
        ((float *)(m_Buffer.data()))[1] = color.g();
        ((float *)(m_Buffer.data()))[2] = color.b();
        ((float *)(m_Buffer.data()))[3] = color.a();

        m_Type = VT_GLColor;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromPoint
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromPoint(const PointF &point)
    {
        m_Buffer.clear();
        m_Buffer.resize(2 * sizeof(float));

        ((float *)(m_Buffer.data()))[0] = point.x();
        ((float *)(m_Buffer.data()))[1] = point.y();

        m_Type = VT_Point;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromSize
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromSize(const SizeF &size)
    {
        m_Buffer.clear();
        m_Buffer.resize(2 * sizeof(float));

        ((float *)(m_Buffer.data()))[0] = size.width();
        ((float *)(m_Buffer.data()))[1] = size.height();

        m_Type = VT_Size;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      fromRect
    ///
    ///////////////////////////////////////////////////////////
    void Variant::fromRect(const RectF &rect)
    {
        m_Buffer.clear();
        m_Buffer.resize(4 * sizeof(float));

        ((float *)(m_Buffer.data()))[0] = rect.x();
        ((float *)(m_Buffer.data()))[1] = rect.y();
        ((float *)(m_Buffer.data()))[2] = rect.width();
        ((float *)(m_Buffer.data()))[3] = rect.height();

        m_Type = VT_Rect;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      isType
    ///
    ///////////////////////////////////////////////////////////
    bool Variant::isType(VariantType type) const
    {
        return m_Type == type;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toInt8
    ///
    ///////////////////////////////////////////////////////////
    QInt8 Variant::toInt8() const
    {
        assert(isType(VT_Int8));
        return m_Buffer.at(0);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toInt16
    ///
    ///////////////////////////////////////////////////////////
    QInt16 Variant::toInt16() const
    {
        assert(isType(VT_Int16));
        return static_cast<QInt16>
        (
              (m_Buffer.at(1) << 8) |
               m_Buffer.at(0)
        );
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toInt32
    ///
    ///////////////////////////////////////////////////////////
    QInt32 Variant::toInt32() const
    {
        assert(isType(VT_Int32));
        return static_cast<QInt32>
        (
              (m_Buffer.at(3) << 24) |
              (m_Buffer.at(2) << 16) |
              (m_Buffer.at(1) << 8)  |
               m_Buffer.at(0)
        );
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toInt64
    ///
    ///////////////////////////////////////////////////////////
    QInt64 Variant::toInt64() const
    {
        assert(isType(VT_Int64));
        return static_cast<QInt64>
        (
              ((QInt64)m_Buffer.at(7) << 54) |
              ((QInt64)m_Buffer.at(6) << 48) |
              ((QInt64)m_Buffer.at(5) << 40) |
              ((QInt64)m_Buffer.at(4) << 32) |
              ((QInt64)m_Buffer.at(3) << 24) |
              ((QInt64)m_Buffer.at(2) << 16) |
              ((QInt64)m_Buffer.at(1) << 8)  |
               (QInt64)m_Buffer.at(0)
        );
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toUtf8
    ///
    ///////////////////////////////////////////////////////////
    const char *Variant::toUtf8() const
    {
        assert(isType(VT_Utf8));
        return m_Buffer.data();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toUtf16
    ///
    ///////////////////////////////////////////////////////////
    const char16_t *Variant::toUtf16() const
    {
        assert(isType(VT_Utf16));
        return (char16_t *)(m_Buffer.data());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toUtf32
    ///
    ///////////////////////////////////////////////////////////
    const char32_t *Variant::toUtf32() const
    {
        assert(isType(VT_Utf32));
        return (char32_t *)(m_Buffer.data());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toByteArray
    ///
    ///////////////////////////////////////////////////////////
    const QInt8 *Variant::toByteArray(int *size) const
    {
        *size = static_cast<int>(m_Buffer.size());

        assert(isType(VT_PInt8));
        return m_Buffer.data();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toShortArray
    ///
    ///////////////////////////////////////////////////////////
    const QInt16 *Variant::toShortArray(int *size) const
    {
        *size = static_cast<int>(m_Buffer.size());

        assert(isType(VT_PInt16));
        return (QInt16 *)(m_Buffer.data());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toIntArray
    ///
    ///////////////////////////////////////////////////////////
    const QInt32 *Variant::toIntArray(int *size) const
    {
        *size = static_cast<int>(m_Buffer.size());

        assert(isType(VT_PInt32));
        return (QInt32 *)(m_Buffer.data());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toLongArray
    ///
    ///////////////////////////////////////////////////////////
    const QInt64 *Variant::toLongArray(int *size) const
    {
        *size = static_cast<int>(m_Buffer.size());

        assert(isType(VT_PInt64));
        return (QInt64 *)(m_Buffer.data());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toColor
    ///
    ///////////////////////////////////////////////////////////
    const Color Variant::toColor() const
    {
        assert(isType(VT_Color));
        return Color
        (
            m_Buffer.at(0),
            m_Buffer.at(1),
            m_Buffer.at(2),
            m_Buffer.at(3)
        );
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toGLColor
    ///
    ///////////////////////////////////////////////////////////
    const GLColor Variant::toGLColor() const
    {
        assert(isType(VT_GLColor));

        float r = ((float *)(m_Buffer.data()))[0];
        float g = ((float *)(m_Buffer.data()))[1];
        float b = ((float *)(m_Buffer.data()))[2];
        float a = ((float *)(m_Buffer.data()))[3];

        return GLColor(r, g, b, a);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toPoint
    ///
    ///////////////////////////////////////////////////////////
    const PointF Variant::toPoint() const
    {
        assert(isType(VT_Point));

        float x = ((float *)(m_Buffer.data()))[0];
        float y = ((float *)(m_Buffer.data()))[1];

        return PointF(x, y);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toSize
    ///
    ///////////////////////////////////////////////////////////
    const SizeF Variant::toSize() const
    {
        assert(isType(VT_Size));

        float w = ((float *)(m_Buffer.data()))[0];
        float h = ((float *)(m_Buffer.data()))[1];

        return SizeF(w, h);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \fn      toRect
    ///
    ///////////////////////////////////////////////////////////
    const RectF Variant::toRect() const
    {
        assert(isType(VT_Rect));

        float x = ((float *)(m_Buffer.data()))[0];
        float y = ((float *)(m_Buffer.data()))[1];
        float w = ((float *)(m_Buffer.data()))[2];
        float h = ((float *)(m_Buffer.data()))[3];

        return RectF(x, y, w, h);
    }
}
