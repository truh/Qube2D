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


#ifndef __Q2D_STRING_HPP__
#define __Q2D_STRING_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Localization/StringEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    String.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \class   String
    /// \brief   Holds a string of UTF-32 characters.
    ///
    /// Supports creating UTF-32 strings from UTF-16 and UTF-8
    /// strings by either using the respective constructors or
    /// assignment operators. Thus every Qube2D method that
    /// requires a Qube2D::String to be passed also directly
    /// accepts UTF-8/16/32 values. Most of the member functions
    /// return a reference to this string in order to make
    /// something like this possible:
    /// string.replace(...).insert(...) [...]
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API String
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes an empty UTF-32 string.
        ///
        ///////////////////////////////////////////////////////////
        String();

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #1)
        /// \brief  Copies the given UTF-32 codepoints.
        /// \param  utf32 Codepoints to copy to new string
        ///
        ///////////////////////////////////////////////////////////
        String(const char32_t *utf32);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #2)
        /// \brief  Converts the given UTF-16 string.
        /// \param  utf16 UTF-16 characters to copy and convert
        ///
        ///////////////////////////////////////////////////////////
        String(const char16_t *utf16);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #3)
        /// \brief  Converts the given UTF-8 string.
        /// \param  utf8 UTF-8 characters to copy and convert
        ///
        ///////////////////////////////////////////////////////////
        String(const char *utf8);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #4)
        /// \brief  Converts the given byte value.
        /// \param  s8 Byte value to convert to a string
        /// \param  (opt) useHex Convert byte to hex string?
        ///
        ///////////////////////////////////////////////////////////
        String(QInt8 s8, bool useHex = false);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #5)
        /// \brief  Converts the given short value.
        /// \param  s16 Short value to convert to a string
        /// \param  (opt) useHex Convert short to hex string?
        ///
        ///////////////////////////////////////////////////////////
        String(QInt16 s16, bool useHex = false);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #6)
        /// \brief  Converts the given integer value.
        /// \param  s32 Integer value to convert to a string
        /// \param  (opt) useHex Convert integer to hex string?
        ///
        ///////////////////////////////////////////////////////////
        String(QInt32 s32, bool useHex = false);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #7)
        /// \brief  Converts the given long value.
        /// \param  s64 Byte value to convert to a string
        /// \param  (opt) useHex Convert long to hex string?
        ///
        ///////////////////////////////////////////////////////////
        String(QInt64 s64, bool useHex = false);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor (overload #8)
        /// \brief  Converts the given floating-point number.
        /// \param  dec Floating-point number to convert to a string
        ///
        ///////////////////////////////////////////////////////////
        String(QFloat dec);

        ///////////////////////////////////////////////////////////
        /// \fn     Copy constructor
        /// \brief  Copies the given Qube2D::String to this string.
        /// \param  str String object to copy
        ///
        ///////////////////////////////////////////////////////////
        String(const String &str);


        ///////////////////////////////////////////////////////////
        /// \fn      Assignment operator
        /// \brief   Assigns the given UTF-32 codepoints.
        /// \param   utf32 Codepoints to copy to new string
        /// \returns a reference to this string.
        ///
        ///////////////////////////////////////////////////////////
        String &operator=(const char32_t *utf32);

        ///////////////////////////////////////////////////////////
        /// \fn      Assignment operator (overload #1)
        /// \brief   Assigns the given UTF-16 string.
        /// \param   utf16 UTF-16 characters to copy to new string
        /// \returns a reference to this string.
        ///
        ///////////////////////////////////////////////////////////
        String &operator=(const char16_t *utf16);

        ///////////////////////////////////////////////////////////
        /// \fn      Assignment operator (overload #2)
        /// \brief   Assigns the given UTF-8 string.
        /// \param   utf8 UTF-8 characters to copy to new string
        /// \returns a reference to this string.
        ///
        ///////////////////////////////////////////////////////////
        String &operator=(const char *utf8);

        ///////////////////////////////////////////////////////////
        /// \fn      Assignment operator (overload #3)
        /// \brief   Assigns the given UTF-32 codepoints.
        /// \param   str Other Qube2D::String value
        /// \returns a reference to this string.
        ///
        ///////////////////////////////////////////////////////////
        String &operator=(const String &str);

        ///////////////////////////////////////////////////////////
        /// \fn      Relational operator ==
        /// \brief   Determines whether the strings are the same.
        /// \param   other Other string to check
        /// \returns true if both strings are the same.
        ///
        ///////////////////////////////////////////////////////////
        bool operator==(const String &other);

        ///////////////////////////////////////////////////////////
        /// \fn      Relational operator !=
        /// \brief   Determines whether the strings differ.
        /// \param   other Other string to check
        /// \returns true if both strings differ.
        ///
        ///////////////////////////////////////////////////////////
        bool operator!=(const String &other);

        ///////////////////////////////////////////////////////////
        /// \fn      Subscript operator
        /// \brief   Retrieves the UTF-32 char at specified position.
        /// \param   pos Position of character within the string
        /// \returns a reference to the UTF-32 character.
        ///
        ///////////////////////////////////////////////////////////
        char32_t &operator[](QInt32 pos);

        ///////////////////////////////////////////////////////////
        /// \fn      Subscript operator (overload #1)
        /// \brief   Retrieves the UTF-32 char at specified position.
        /// \param   pos Position of character within the string
        /// \returns a reference to the UTF-32 character.
        ///
        ///////////////////////////////////////////////////////////
        char32_t &operator[](QUInt32 pos);


        ///////////////////////////////////////////////////////////
        /// \fn      data -> const
        /// \brief   Retrieves the raw UTF-32 data of this string.
        /// \returns an array of UTF-32 characters.
        ///
        ///////////////////////////////////////////////////////////
        const char32_t *data() const;

        ///////////////////////////////////////////////////////////
        /// \fn      length -> const
        /// \brief   Retrieves the amount of characters.
        /// \returns the character-length of the string.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 length() const;

        ///////////////////////////////////////////////////////////
        /// \fn      at -> const
        /// \brief   Retrieves the UTF-32 char at specified position.
        /// \param   pos Position of character within the string
        /// \returns a UTF-32 character.
        ///
        ///////////////////////////////////////////////////////////
        char32_t at(QInt32 pos) const;

        ///////////////////////////////////////////////////////////
        /// \fn      at -> const
        /// \brief   Retrieves the UTF-32 char at specified position.
        /// \param   pos Position of character within the string
        /// \returns a UTF-32 character.
        ///
        ///////////////////////////////////////////////////////////
        char32_t at(QUInt32 pos) const;


        ///////////////////////////////////////////////////////////
        /// \fn      isEmpty -> const
        /// \brief   Determines whether the string is empty.
        /// \returns true if this string is empty.
        ///
        ///////////////////////////////////////////////////////////
        bool isEmpty() const;

        ///////////////////////////////////////////////////////////
        /// \fn      contains -> const
        /// \brief   Determines whether the string contains 'str'.
        /// \param   str Sequence to check
        /// \returns true if 'str' exists within this string.
        ///
        ///////////////////////////////////////////////////////////
        bool contains(const String &str) const;

        ///////////////////////////////////////////////////////////
        /// \fn      startsWith -> const
        /// \brief   Determines whether the string starts with 'str'.
        /// \param   str Sequence to check
        /// \returns true if this string starts with 'str'.
        ///
        ///////////////////////////////////////////////////////////
        bool startsWith(const String &str) const;

        ///////////////////////////////////////////////////////////
        /// \fn      endsWith -> const
        /// \brief   Determines whether the string ends with 'str'.
        /// \param   str Sequence to check
        /// \returns true if this string ends with 'str'.
        ///
        ///////////////////////////////////////////////////////////
        bool endsWith(const String &str) const;

        ///////////////////////////////////////////////////////////
        /// \fn      substr -> const
        /// \brief   Returns a specific fragment of the string.
        ///
        /// If -1 is passed to size, the entire string will be
        /// copied from the specified start position.
        ///
        /// \param   pos Position to start copying from
        /// \param   size Size, in characters, to copy
        /// \returns a part of the string defined by given bounds.
        ///
        ///////////////////////////////////////////////////////////
        String substr(QInt32 pos, QInt32 size = -1) const;

        ///////////////////////////////////////////////////////////
        /// \fn     indexOf -> const
        /// \brief  Retrieves the position of the given character.
        ///
        /// If the given character does not exist in this string,
        /// the position -1 will be returned. Alternatively, can
        /// check against Qube2D::String::npos.
        ///
        /// \param   u32 UTF-32 character to search in the string.
        /// \returns the position of the char or -1 if not existing.
        /// \see     indexOf(const String &str, QInt32 pos)
        ///
        ///////////////////////////////////////////////////////////
        QInt32 indexOf(char32_t u32, QUInt32 pos = 0) const;

        ///////////////////////////////////////////////////////////
        /// \fn     indexOf -> const (overload #1)
        /// \brief  Retrieves the position of the given sequence.
        ///
        /// If the given sequence does not exist in this string,
        /// the position -1 will be returned. Alternatively, can
        /// check against Qube2D::String::npos.
        ///
        /// \param   str Character sequence to search in the string
        /// \returns the position of the string or -1 if not existing.
        /// \see     indexOf(char32_t u32, QInt32 pos)
        ///
        ///////////////////////////////////////////////////////////
        QInt32 indexOf(const String &str, QUInt32 pos = 0) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toUtf16 -> const
        /// \brief   Converts this string to an UTF-16 string.
        /// \returns a sequence of UTF-16-encoded characters.
        ///
        ///////////////////////////////////////////////////////////
        std::u16string toUtf16() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toUtf8 -> const
        /// \brief   Converts this string to an UTF-8 string.
        /// \returns a sequence of UTF-8-encoded characters.
        ///
        ///////////////////////////////////////////////////////////
        std::string toUtf8() const;

        ///////////////////////////////////////////////////////////
        /// \fn      toByte -> const
        /// \brief   Converts this string to a byte value.
        /// \param   (opt) result Success of the process
        /// \param   (opt) isHex Is string a hex number?
        /// \returns the byte representation of the string.
        ///
        ///////////////////////////////////////////////////////////
        QInt8 toByte(bool *result = NULL, bool isHex = false) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toShort -> const
        /// \brief   Converts this string to a short value.
        /// \param   (opt) result Success of the process
        /// \param   (opt) isHex Is string a hex number?
        /// \returns the short representation of the string.
        ///
        ///////////////////////////////////////////////////////////
        QInt16 toShort(bool *result = NULL, bool isHex = false) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toInt -> const
        /// \brief   Converts this string to an integer value.
        /// \param   (opt) result Success of the process
        /// \param   (opt) isHex Is string a hex number?
        /// \returns the integer representation of the string.
        ///
        ///////////////////////////////////////////////////////////
        QInt32 toInt(bool *result = NULL, bool isHex = false) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toLong -> const
        /// \brief   Converts this string to a long value.
        /// \param   (opt) result Success of the process
        /// \param   (opt) isHex Is string a hex number?
        /// \returns the long representation of the string.
        ///
        ///////////////////////////////////////////////////////////
        QInt64 toLong(bool *result = NULL, bool isHex = false) const;

        ///////////////////////////////////////////////////////////
        /// \fn      toFloat -> const
        /// \brief   Converts this string to a float number.
        /// \param   (opt) result Success of the process
        /// \returns the float representation of the string.
        ///
        ///////////////////////////////////////////////////////////
        QFloat toFloat(bool *result = NULL) const;

        ///////////////////////////////////////////////////////////
        /// \fn      split -> const
        /// \brief   Splits this string into several sub-strings.
        ///
        /// The separator can either be a single character or an
        /// entire sequence. If the separator is '\n', for example,
        /// then the string will be split up into lines of text.
        ///
        /// \param   sep Separator that determines split logic
        /// \param   (opt) options Split options
        /// \returns a list of strings that meet the conditions.
        ///
        ///////////////////////////////////////////////////////////
        std::vector<String> split(
                const String &sep,
                SplitOptions options = SO_KeepEmptyEntries
                ) const;


        ///////////////////////////////////////////////////////////
        /// \fn     append
        /// \brief  Adds a single character to the string.
        /// \param  u32 UTF-32 character to add
        ///
        ///////////////////////////////////////////////////////////
        String &append(char32_t u32);

        ///////////////////////////////////////////////////////////
        /// \fn     append (overload #1)
        /// \brief  Adds an entire sequence to the string.
        /// \param  str Qube2D::String to add
        ///
        ///////////////////////////////////////////////////////////
        String &append(const String &str);

        ///////////////////////////////////////////////////////////
        /// \fn     insert
        /// \brief  Inserts a single character into the string.
        ///
        /// If pos is outside of bounds, appends the character.
        ///
        /// \param  pos Position to insert character into
        /// \param  u32 UTF-32 character to insert
        ///
        ///////////////////////////////////////////////////////////
        String &insert(QUInt32 pos, char32_t u32);

        ///////////////////////////////////////////////////////////
        /// \fn     insert (overload #1)
        /// \brief  Inserts an entire sequence into the string.
        ///
        /// If pos is outside of bounds, appends the string
        ///
        /// \param  pos Position to insert string into
        /// \param  str Qube2D::String to insert
        ///
        ///////////////////////////////////////////////////////////
        String &insert(QUInt32 pos, const String &str);

        ///////////////////////////////////////////////////////////
        /// \fn     replace
        /// \brief  Replaces a character with another one.
        ///
        /// Either replaces one or all occurrences of the given
        /// character. One of the Qube2D::ReplaceOptions enum
        /// values might be used to control the process.
        ///
        /// \param  rep Character to replace
        /// \param  ins Character to insert
        /// \param  (opt) options Replace options
        ///
        ///////////////////////////////////////////////////////////
        String &replace(char32_t rep, char32_t ins,
                        ReplaceOptions options = RO_OneEntry);

        ///////////////////////////////////////////////////////////
        /// \fn     replace (overload #1)
        /// \brief  Replaces a string with another one.
        ///
        /// Either replaces one or all occurrences of the given
        /// string. One of the Qube2D::ReplaceOptions enum
        /// values might be used to control the process.
        ///
        /// \param  rep String to replace
        /// \param  ins String to insert
        /// \param  (opt) options Replace options
        ///
        ///////////////////////////////////////////////////////////
        String &replace(const String &rep, const String &ins,
                        ReplaceOptions options = RO_OneEntry);

        ///////////////////////////////////////////////////////////
        /// \fn     replace (overload #2)
        /// \brief  Replaces a specified section with a string.
        /// \param  pos Position to start replacing from
        /// \param  size Size of characters to replace
        /// \param  str String to insert instead
        ///
        ///////////////////////////////////////////////////////////
        String &replace(QUInt32 pos, QUInt32 size, const String &str);

        ///////////////////////////////////////////////////////////
        /// \fn     erase
        /// \brief  Deletes some characters.
        /// \param  pos Position to start erasing from
        /// \param  cnt Amount of characters to erase
        ///
        ///////////////////////////////////////////////////////////
        String &erase(QUInt32 pos, QUInt32 cnt);

        ///////////////////////////////////////////////////////////
        /// \fn     erase (overload #1)
        /// \brief  Deletes the given sequence in this string.
        ///
        /// Either erases one or all occurrences of the given
        /// character. One of the Qube2D::EraseOptions enum
        /// values might be used to control the process.
        ///
        /// \param  str String to erase
        /// \param  (opt) options Erase options
        ///
        ///////////////////////////////////////////////////////////
        String &erase(const String &str, EraseOptions options = EO_OneEntry);

        ///////////////////////////////////////////////////////////
        /// \fn     toLower
        /// \brief  Converts all characters to lowercase.
        /// \note   ASCII-only at the moment.
        ///
        ///////////////////////////////////////////////////////////
        String &toLower();

        ///////////////////////////////////////////////////////////
        /// \fn     toUpper
        /// \brief  Converts all characters to uppercase.
        /// \note   ASCII-only at the moment.
        ///
        ///////////////////////////////////////////////////////////
        String &toUpper();

        ///////////////////////////////////////////////////////////
        /// \fn     trim
        /// \brief  Trims leading and trailing whitespace.
        ///
        /// Whitespace is considered spaces, tabs, line-breaks, ...
        ///
        ///////////////////////////////////////////////////////////
        String &trim();

        ///////////////////////////////////////////////////////////
        /// \fn     args
        /// \brief  Replaces argument identifiers with strings.
        ///
        /// Replaces arguments like %0 and %1 with Qube2D::String
        /// values. The amount of arguments is only limited by the
        /// maximum value of a 32-bit signed integer.
        ///
        /// \param  n Number of arguments in the string
        /// \param  (var) Strings to replace with the arguments
        ///
        ///////////////////////////////////////////////////////////
        String &args(QUInt32 n, ...);


        ///////////////////////////////////////////////////////////////////
        static const int npos = -1; ///< Invalid position within the string


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        std::u32string m_String;    ///< Underlying basic_string

    };
}


#endif  // __Q2D_STRING_HPP__
