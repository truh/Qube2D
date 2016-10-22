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


#ifndef __Q2D_VARIANT_HPP__
#define __Q2D_VARIANT_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Structs/Rect.hpp>
#include <Qube2D/System/Structs/Color.hpp>
#include <Qube2D/System/Structs/GLColor.hpp>
#include <Qube2D/System/Storage/VariantEnums.hpp>
#include <Qube2D/System/Localization/String.hpp>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Variant.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 26th, 2016
    /// \class   Variant
    /// \brief   Stores a value of any supported type.
    /// \note    Variant takes ownership of all arrays.
    ///
    /// Supported types:
    /// Int8, Int16, Int32, Int64,
    /// char*, char16_t*, char32_t*,
    /// Int8*, Int16*, Int32*, Int64*,
    /// Color, GLColor,
    /// PointF, RectF, SizeF,
    /// String
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Variant
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Variant.
        ///
        ///////////////////////////////////////////////////////////
        Variant();

        ///////////////////////////////////////////////////////////
        /// \fn     Copy constructor
        /// \brief  Copies all values from one variant to another.
        /// \param  variant Initialized variant instance
        ///
        ///////////////////////////////////////////////////////////
        Variant(const Variant &variant);

        ///////////////////////////////////////////////////////////
        /// \fn     Assignment operator
        /// \brief  Copies all values from one variant to another.
        /// \param  variant Initializes variant instance
        ///
        ///////////////////////////////////////////////////////////
        Variant &operator =(const Variant &variant);


        ///////////////////////////////////////////////////////////
        /// \fn     fromBoolean
        /// \brief  Converts the given bool value to a variant.
        /// \param  b Boolean value
        ///
        ///////////////////////////////////////////////////////////
        void fromBoolean(QBool b);

        ///////////////////////////////////////////////////////////
        /// \fn     fromInt8
        /// \brief  Converts the given Int8 value to a variant.
        /// \param  s8 Signed 8-bit value
        ///
        ///////////////////////////////////////////////////////////
        void fromInt8(QInt8 s8);

        ///////////////////////////////////////////////////////////
        /// \fn     fromInt16
        /// \brief  Converts the given Int16 value to a variant.
        /// \param  s16 Signed 16-bit value
        ///
        ///////////////////////////////////////////////////////////
        void fromInt16(QInt16 s16);

        ///////////////////////////////////////////////////////////
        /// \fn     fromInt32
        /// \brief  Converts the given Int32 value to a variant.
        /// \param  s32 Signed 32-bit value
        ///
        ///////////////////////////////////////////////////////////
        void fromInt32(QInt32 s32);

        ///////////////////////////////////////////////////////////
        /// \fn     fromInt64
        /// \brief  Converts the given Int64 value to a variant.
        /// \param  s64 Signed 64-bit value
        ///
        ///////////////////////////////////////////////////////////
        void fromInt64(QInt64 s64);

        ///////////////////////////////////////////////////////////
        /// \fn     fromFloat
        /// \brief  Converts the given float value to a variant.
        /// \param  f Float value
        ///
        ///////////////////////////////////////////////////////////
        void fromFloat(QFloat f);

        ///////////////////////////////////////////////////////////
        /// \fn     fromString
        /// \brief  Converts the given UTF-8 string to a variant.
        /// \param  utf8 UTF-8 encoded string
        ///
        ///////////////////////////////////////////////////////////
        void fromString(const char *utf8);

        ///////////////////////////////////////////////////////////
        /// \fn     fromString (overload #1)
        /// \brief  Converts the given UTF-16 string to a variant.
        /// \param  utf16 UTF-16 encoded string
        ///
        ///////////////////////////////////////////////////////////
        void fromString(const char16_t *utf16);

        ///////////////////////////////////////////////////////////
        /// \fn     fromString (overload #2)
        /// \brief  Converts the given UTF-32 string to a variant.
        /// \param  utf32 UTF-32 encoded string
        ///
        ///////////////////////////////////////////////////////////
        void fromString(const char32_t *utf32);

        ///////////////////////////////////////////////////////////
        /// \fn     fromArray
        /// \brief  Converts the given Int8 array to a variant.
        /// \param  v8 Array to Int8 values
        /// \param  size Size of the underlying array
        ///
        ///////////////////////////////////////////////////////////
        void fromArray(const QInt8 *v8, int size);

        ///////////////////////////////////////////////////////////
        /// \fn     fromArray (overload #1)
        /// \brief  Converts the given Int16 array to a variant.
        /// \param  v16 Array to Int16 values
        /// \param  size Size of the underlying array
        ///
        ///////////////////////////////////////////////////////////
        void fromArray(const QInt16 *v16, int size);

        ///////////////////////////////////////////////////////////
        /// \fn     fromArray (overload #2)
        /// \brief  Converts the given Int32 array to a variant.
        /// \param  v32 Array to Int32 values
        /// \param  size Size of the underlying array
        ///
        ///////////////////////////////////////////////////////////
        void fromArray(const QInt32 *v32, int size);

        ///////////////////////////////////////////////////////////
        /// \fn     fromArray (overload #3)
        /// \brief  Converts the given Int64 array to a variant.
        /// \param  v64 Array to Int64 values
        /// \param  size Size of underlying array
        ///
        ///////////////////////////////////////////////////////////
        void fromArray(const QInt64 *v64, int size);

        ///////////////////////////////////////////////////////////
        /// \fn     fromColor
        /// \brief  Converts the given color to a variant.
        /// \param  color Initializes color instance
        ///
        ///////////////////////////////////////////////////////////
        void fromColor(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     fromColor (overload #1)
        /// \brief  Converts the given GLcolor to a variant.
        /// \param  color Initialized GLcolor instance
        ///
        ///////////////////////////////////////////////////////////
        void fromColor(const GLColor &color);

        ///////////////////////////////////////////////////////////
        /// \fn     fromPoint
        /// \brief  Converts the given PointF to a variant.
        /// \param  point Point with floating point values
        ///
        ///////////////////////////////////////////////////////////
        void fromPoint(const PointF &point);

        ///////////////////////////////////////////////////////////
        /// \fn     fromSize
        /// \brief  Converts the given SizeF to a variant.
        /// \param  size Size with floating point values
        ///
        ///////////////////////////////////////////////////////////
        void fromSize(const SizeF &size);

        ///////////////////////////////////////////////////////////
        /// \fn     fromRect
        /// \brief  Converts the given RectF to a variant.
        /// \param  rect Rect with floating point values
        ///
        ///////////////////////////////////////////////////////////
        void fromRect(const RectF &rect);

        ///////////////////////////////////////////////////////////
        /// \fn     fromString (overload #3)
        /// \brief  Converts the given String to a variant.
        /// \param  str UTF-32 encoded string
        ///
        ///////////////////////////////////////////////////////////
        void fromString(const String &str);


        ///////////////////////////////////////////////////////////
        /// \fn      isType -> const
        /// \brief   Determines whether the variant is the given type.
        /// \param   type One of the Qube2D::VariantType enum values
        /// \returns true if the variant is the given type.
        ///
        ///////////////////////////////////////////////////////////
        bool isType(VariantType type) const;


        ///////////////////////////////////////////////////////////
        /// \fn      toBool -> const
        /// \brief   Converts this variant to a boolean value.
        /// \returns a boolean value.
        ///
        ///////////////////////////////////////////////////////////
        QBool toBool() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toInt8 -> const
        /// \brief   Converts this variant to an 8-bit value.
        /// \returns a signed 8-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QInt8 toInt8() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toInt16 -> const
        /// \brief   Converts this variant to a 16-bit value.
        /// \returns a signed 16-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QInt16 toInt16() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toInt32 -> const
        /// \brief   Converts this variant to a 32-bit value.
        /// \returns a signed 32-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QInt32 toInt32() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toInt64 -> const
        /// \brief   Converts this variant to a 64-bit value.
        /// \returns a signed 64-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QInt64 toInt64() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toFloat -> const
        /// \brief   Converts this variant to a float value.
        /// \returns a float value.
        ///
        ///////////////////////////////////////////////////////////
        QFloat toFloat() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toUtf8 -> const
        /// \brief   Converts this variant to an UTF-8 string.
        ///
        /// Warning: Conversion between different encoding is not
        /// supported. Qube2D::Variant does only exist for storage.
        ///
        /// \returns an UTF-8 encoded string.
        ///
        ///////////////////////////////////////////////////////////
        const char *toUtf8() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toUtf16 -> const
        /// \brief   Converts this variant to an UTF-16 string.
        ///
        /// Warning: Conversion between different encoding is not
        /// supported. Qube2D::Variant does only exist for storage.
        ///
        /// \returns an UTF-16 encoded string.
        ///
        ///////////////////////////////////////////////////////////
        const char16_t *toUtf16() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toUtf32 -> const
        /// \brief   Converts this variant to an UTF-32 string.
        ///
        /// Warning: Conversion between different encoding is not
        /// supported. Qube2D::Variant does only exist for storage.
        ///
        /// \returns an UTF-32 encoded string.
        ///
        ///////////////////////////////////////////////////////////
        const char32_t *toUtf32() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toByteArray -> const
        /// \brief   Converts this variant to a byte array.
        /// \param   (out) size Size of the array
        /// \returns an array of signed bytes.
        ///
        ///////////////////////////////////////////////////////////
        const QInt8 *toByteArray(int *size) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toShortArray -> const
        /// \brief   Converts this variant to a short array.
        /// \param   (out) size Size of the array
        /// \returns an array of signed shorts.
        ///
        ///////////////////////////////////////////////////////////
        const QInt16 *toShortArray(int *size) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toIntArray -> const
        /// \brief   Converts this variant to an int array.
        /// \param   (out) size Size of the array
        /// \returns an array of signed ints.
        ///
        ///////////////////////////////////////////////////////////
        const QInt32 *toIntArray(int *size) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toLongArray -> const
        /// \brief   Converts this variant to a long array.
        /// \param   (out) size Size of the array
        /// \returns an array of signed longs.
        ///
        ///////////////////////////////////////////////////////////
        const QInt64 *toLongArray(int *size) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toColor -> const
        /// \brief   Converts this variant to a color structure.
        /// \returns a Qube2D::Color structure.
        ///
        ///////////////////////////////////////////////////////////
        const Color toColor() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toGLColor -> const
        /// \brief   Converts this variant to a GLcolor structure.
        /// \returns a Qube2D::GLColor structure.
        ///
        ///////////////////////////////////////////////////////////
        const GLColor toGLColor() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toPoint -> const
        /// \brief   Converts this variant to a Point structure.
        /// \returns a Qube2D::PointF structure.
        ///
        ///////////////////////////////////////////////////////////
        const PointF toPoint() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toSize -> const
        /// \brief   Converts this variant to a Size structure.
        /// \returns a Qube2D::SizeF structure.
        ///
        ///////////////////////////////////////////////////////////
        const SizeF toSize() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toRect -> const
        /// \brief   Converts this variant to a Rect structure.
        /// \returns a Qube2D::RectF structure.
        ///
        ///////////////////////////////////////////////////////////
        const RectF toRect() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toString -> const
        /// \brief   Converts this variant to a String instance.
        /// \returns a Qube2D::String instance.
        ///
        ///////////////////////////////////////////////////////////
        const String toString() const;


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        std::vector<QInt8> m_Buffer;    ///< Holds the raw data
        VariantType m_Type;             ///< Holds the data type

    };
}


#endif  // __Q2D_VARIANT_HPP__
