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
#include <Qube2D/System/Localization/String.hpp>
#include <Qube2D/System/Structs/Point.hpp>
#include <Qube2D/System/Debug.hpp>
#include <cstdarg>
#include <codecvt>
#include <sstream>
#include <locale>
#include <climits>
#include <cmath>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    String::String()
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #1
    ///
    ///////////////////////////////////////////////////////////
    String::String(const char32_t *utf32)
        : m_String(utf32)
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #2
    ///
    ///////////////////////////////////////////////////////////
    String::String(const char16_t *utf16)
    {
        assert(utf16);

        // Converts UTF-16 to UTF-8 first
        std::u16string u16(utf16);
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv16;
        std::string u8 = conv16.to_bytes(u16);

        // Converts UTF-8 to UTF-32
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv32;
        m_String = conv32.from_bytes(u8);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #3
    ///
    ///////////////////////////////////////////////////////////
    String::String(const char *utf8)
    {
        assert(utf8);

        // Converts UTF-8 to UTF-32
        std::string str(utf8);
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        m_String = conv32.from_bytes(str);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #4
    ///
    ///////////////////////////////////////////////////////////
    String::String(QInt8 s8, bool useHex)
    {
        // Converts the number to an UTF-8 string. The cast to
        // short is required in order to tell std::stringstream
        // that we want a number conversion and not to append a
        // single character to the string.
        std::stringstream stream;
        if (useHex)
            stream << "0x" << std::hex << static_cast<QInt16>(s8);
        else
            stream << static_cast<QInt16>(s8);


        // Converts the UTF-8 string to an UTF-32 string
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        m_String = conv32.from_bytes(stream.str());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #5
    ///
    ///////////////////////////////////////////////////////////
    String::String(QInt16 s16, bool useHex)
    {
        // Converts the number to an UTF-8 string
        std::stringstream stream;
        if (useHex)
            stream << "0x" << std::hex << s16;
        else
            stream << s16;


        // Converts the UTF-8 string to an UTF-32 string
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        m_String = conv32.from_bytes(stream.str());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #6
    ///
    ///////////////////////////////////////////////////////////
    String::String(QInt32 s32, bool useHex)
    {
        // Converts the number to an UTF-8 string
        std::stringstream stream;
        if (useHex)
            stream << "0x" << std::hex << s32;
        else
            stream << s32;


        // Converts the UTF-8 string to an UTF-32 string
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        m_String = conv32.from_bytes(stream.str());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #7
    ///
    ///////////////////////////////////////////////////////////
    String::String(QInt64 s64, bool useHex)
    {
        // Converts the number to an UTF-8 string
        std::stringstream stream;
        if (useHex)
            stream << "0x" << std::hex << s64;
        else
            stream << s64;


        // Converts the UTF-8 string to an UTF-32 string
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        m_String = conv32.from_bytes(stream.str());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Constructor -> overload #8
    ///
    ///////////////////////////////////////////////////////////
    String::String(QFloat dec)
    {
        // Converts the number to an UTF-8 string
        std::stringstream stream;
        stream << std::defaultfloat << dec;

        // Converts the UTF-8 string to an UTF-32 string
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        m_String = conv32.from_bytes(stream.str());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Copy constructor
    ///
    ///////////////////////////////////////////////////////////
    String::String(const String &str)
        : m_String(str.m_String)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Assignment operator
    ///
    ///////////////////////////////////////////////////////////
    String &String::operator=(const char32_t *utf32)
    {
        assert(utf32);

        m_String.append(utf32);
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Assignment operator -> overload #1
    ///
    ///////////////////////////////////////////////////////////
    String &String::operator=(const char16_t *utf16)
    {
        assert(utf16);

        // Converts UTF-16 to UTF-8 first
        std::u16string u16(utf16);
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv16;
        std::string u8 = conv16.to_bytes(u16);

        // Converts UTF-8 to UTF-32
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv32;
        m_String = conv32.from_bytes(u8);
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Assignment operator -> overload #2
    ///
    ///////////////////////////////////////////////////////////
    String &String::operator=(const char *utf8)
    {
        assert(utf8);

        std::string str(utf8);
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;

        // Directly converts UTF-8 to UTF-32
        m_String = conv32.from_bytes(str);
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Assignment operator -> overload #3
    ///
    ///////////////////////////////////////////////////////////
    String &String::operator=(const String &str)
    {
        m_String = str.m_String;
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Relational operator ==
    ///
    ///////////////////////////////////////////////////////////
    bool String::operator==(const String &other)
    {
        // Strings cannot be the same if having different lengths
        QUInt32 len = length();
        if (len != other.length())
            return false;

        // Determines whether every character is the same
        for (QUInt32 i = 0; i < len; i++)
            if (at(i) != other.at(i))
                return false;

        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Relational operator !=
    ///
    ///////////////////////////////////////////////////////////
    bool String::operator!=(const String &other)
    {
        return (!(operator==(other)));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Subscript operator
    ///
    ///////////////////////////////////////////////////////////
    char32_t &String::operator[](QInt32 pos)
    {
        assert(pos < (QInt32)(length()));
        return m_String[pos];
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Subscript operator -> overload #1
    ///
    ///////////////////////////////////////////////////////////
    char32_t &String::operator[](QUInt32 pos)
    {
        assert(pos < length());
        return m_String[pos];
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      data -> const
    ///
    ///////////////////////////////////////////////////////////
    const char32_t *String::data() const
    {
        return m_String.data();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      length -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 String::length() const
    {
        // Safe; UTF-32 is a fixed-width encoding
        return m_String.length();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      at -> const
    ///
    ///////////////////////////////////////////////////////////
    char32_t String::at(QInt32 pos) const
    {
        assert(pos < (QInt32)(length()));
        return m_String.at(pos);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      at -> const, overload #1
    ///
    ///////////////////////////////////////////////////////////
    char32_t String::at(QUInt32 pos) const
    {
        assert(pos < length());
        return m_String.at(pos);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      isEmpty -> const
    ///
    ///////////////////////////////////////////////////////////
    bool String::isEmpty() const
    {
        return (length() == 0);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      contains -> const
    ///
    ///////////////////////////////////////////////////////////
    bool String::contains(const String &str) const
    {
        if (str.isEmpty())
            return false;

        // Finds the first character in the string
        QInt32 pos = indexOf(str.at(0));
        if (pos == String::npos)
            return false;


        // Checks for all the other characters
        QUInt32 len = str.length();
        while (pos != String::npos)
        {
            QUInt32 i;
            for (i = 1; i < len; i++)
                if (at(pos+i) != str.at(i))
                    break;

            // If iteration is complete without abort, string is inside this
            if (i == len)
                return true;

            // Searches another occurrence of the first character
            pos = indexOf(str.at(0), pos+1);
        }


        // Iteration never succeeded; string not inside this
        return false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      startsWith -> const
    ///
    ///////////////////////////////////////////////////////////
    bool String::startsWith(const String &str) const
    {
        QUInt32 len = str.length();
        for (QUInt32 i = 0; i < len; i++)
            if (at(i) != str.at(i))
                return false;

        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      endsWith -> const
    ///
    ///////////////////////////////////////////////////////////
    bool String::endsWith(const String &str) const
    {
        QUInt32 len = str.length();
        QUInt32 start = length()-len;

        for (QUInt32 i = 0; i < len; i++)
            if (at(start+i) != str.at(i))
                return false;

        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      substr -> const
    ///
    ///////////////////////////////////////////////////////////
    String String::substr(QInt32 pos, QInt32 size) const
    {
        assert(pos >= 0);
        assert(pos + size <= (QInt32)length());
        if (size == 0)
            return String();

        String str;

        // If size is -1, entire string should be copied, starting from pos
        if (size == String::npos)
            size = length() - pos;

        // Copies the given amount of characters
        for (QInt32 i = pos; i < pos+size; i++)
            str.append(at(i));

        return str;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      indexOf -> const
    ///
    ///////////////////////////////////////////////////////////
    QInt32 String::indexOf(char32_t u32, QUInt32 pos) const
    {
        QUInt32 len = length();
        for (QUInt32 i = pos; i < len; i++)
            if (at(i) == u32)
                return static_cast<QInt32>(i);

        return String::npos;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      indexOf -> const, overload #1
    ///
    ///////////////////////////////////////////////////////////
    QInt32 String::indexOf(const String &str, QUInt32 pos) const
    {
        if (str.isEmpty())
            return String::npos;


        QUInt32 mylen = length();
        QUInt32 len = str.length();
        char32_t start = str.at(0);

        for (QUInt32 i = pos; i < mylen; i++)
        {
            // Found starting character; check for others
            if (at(i) == start)
            {
                QUInt32 j;
                for (j = 1; j < len; j++)
                    if (at(i+j) != str.at(j))
                        break;

                // If iteration ran throughoutly, string equals
                if (j == len)
                    return static_cast<QInt32>(i);
            }
        }


        // Iteration never ran throughoutly; string does not exist
        return String::npos;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toUtf16 -> const
    ///
    ///////////////////////////////////////////////////////////
    std::u16string String::toUtf16() const
    {
        // Converts UTF-32 to UTF-8 first
        std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv32;
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> conv16;
        std::string temp = conv32.to_bytes(m_String);

        // Converts UTF-8 to UTF-16
        return conv16.from_bytes(temp);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toUtf8 -> const
    ///
    ///////////////////////////////////////////////////////////
    std::string String::toUtf8() const
    {
        // Converts UTF-32 to UTF-8
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>,char32_t> conv32;
        return conv32.to_bytes(m_String);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toByte -> const
    ///
    ///////////////////////////////////////////////////////////
    QInt8 String::toByte(bool *result, bool isHex) const
    {
        // Converts the string to an UTF-8 string first
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>,char32_t> conv32;
        std::string str = conv32.to_bytes(m_String);

        // Converts the UTF-8 string to a number
        QInt16 value;
        std::istringstream stream(str);

        if (isHex)
            stream >> std::hex >> value;
        else
            stream >> value;

        if (result)
        {
            if (stream.fail() || value > CHAR_MAX)
                *result = false;
            else
                *result = true;
        }


        return static_cast<QInt8>(value);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toShort -> const
    ///
    ///////////////////////////////////////////////////////////
    QInt16 String::toShort(bool *result, bool isHex) const
    {
        // Converts the string to an UTF-8 string first
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>,char32_t> conv32;
        std::string str = conv32.to_bytes(m_String);

        // Converts the UTF-8 string to a number
        QInt16 value;
        std::istringstream stream(str);

        if (isHex)
            stream >> std::hex >> value;
        else
            stream >> value;

        if (result)
        {
            if (stream.fail())
                *result = false;
            else
                *result = true;
        }


        return value;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toInt -> const
    ///
    ///////////////////////////////////////////////////////////
    QInt32 String::toInt(bool *result, bool isHex) const
    {
        // Converts the string to an UTF-8 string first
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>,char32_t> conv32;
        std::string str = conv32.to_bytes(m_String);

        // Converts the UTF-8 string to a number
        QInt32 value;
        std::istringstream stream(str);

        if (isHex)
            stream >> std::hex >> value;
        else
            stream >> value;

        if (result)
        {
            if (stream.fail() || value > INT_MAX)
                *result = false;
            else
                *result = true;
        }


        return value;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toLong -> const
    ///
    ///////////////////////////////////////////////////////////
    QInt64 String::toLong(bool *result, bool isHex) const
    {
        // Converts the string to an UTF-8 string first
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>,char32_t> conv32;
        std::string str = conv32.to_bytes(m_String);

        // Converts the UTF-8 string to a number
        QInt64 value;
        std::istringstream stream(str);

        if (isHex)
            stream >> std::hex >> value;
        else
            stream >> value;

        if (result)
        {
            if (stream.fail() || value > LONG_LONG_MAX)
                *result = false;
            else
                *result = true;
        }


        return value;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toFloat -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat String::toFloat(bool *result) const
    {
        // Converts the string to an UTF-8 string first
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>,char32_t> conv32;
        std::string str = conv32.to_bytes(m_String);

        // Converts the UTF-8 string to a number
        QFloat value;
        std::istringstream stream(str);
        stream >> std::defaultfloat >> value;

        if (result)
        {
            if (stream.fail() || std::isnan(value))
                *result = false;
            else
                *result = true;
        }


        return value;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      split -> const
    ///
    ///////////////////////////////////////////////////////////
    std::vector<String> String::split(const String &sep,
                                      SplitOptions options) const
    {
        std::vector<String> splitList;
        std::vector<PointI> bounds;

        // Finds the first occurence
        QUInt32 len = sep.length();
        QInt32 pos = indexOf(sep);
        bounds.push_back(PointI(0, pos));

        // Finds all other occurrences and stores position plus
        // the distance to the next occurrence.
        while (pos != String::npos)
        {
            QInt32 size;
            QInt32 next = indexOf(sep, pos+len);
            if (next == String::npos)
                size = length()-pos-len;
            else
                size = next-pos-len;
            if (size == -1) // caused by empty sub-string
                size = 0;

            bounds.push_back(PointI(pos+len, size));
            pos = next;
        }


        // Substrings every occurrence and adds it
        QUInt32 occ_size = bounds.size();
        for (QUInt32 i = 0; i < occ_size; i++)
            splitList.push_back(substr(bounds.at(i).x(), bounds.at(i).y()));

        // Deletes empty entries on request
        if (options == SO_EraseEmptyEntries)
        {
            for (QUInt32 i = 0; i < occ_size; i++)
            {
                if (splitList.at(i).isEmpty())
                {
                    splitList.erase(splitList.begin()+i);
                    occ_size--;
                }
            }
        }

        return splitList;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      append
    ///
    ///////////////////////////////////////////////////////////
    String &String::append(char32_t u32)
    {
        m_String.push_back(u32);
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      append, overload #1
    ///
    ///////////////////////////////////////////////////////////
    String &String::append(const String &str)
    {
        m_String.append(str.m_String);
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      insert
    ///
    ///////////////////////////////////////////////////////////
    String &String::insert(QUInt32 pos, char32_t u32)
    {
        if (pos >= length())
            append(u32);
        else
            m_String.insert(m_String.begin()+pos, u32);

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      insert, overload #1
    ///
    ///////////////////////////////////////////////////////////
    String &String::insert(QUInt32 pos, const String &str)
    {
        if (pos >= length())
            append(str);
        else
            m_String.insert(pos, str.m_String);

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      replace
    ///
    ///////////////////////////////////////////////////////////
    String &String::replace(char32_t rep, char32_t ins,
                            ReplaceOptions options)
    {
        // Finds the position of the character to replace
        QInt32 pos = indexOf(rep);
        if (pos == String::npos)
            return *this;

        // Replaces the character
        m_String.erase((QUInt32)pos, 1);
        m_String.insert(m_String.begin()+pos, ins);

        if (options == RO_OneEntry)
            return *this;
        else
            pos = indexOf(rep, pos+1);

        while (pos != String::npos)
        {
            m_String.erase((QUInt32)pos, 1);
            m_String.insert(m_String.begin()+pos, ins);
            pos = indexOf(rep, pos+1);
        }

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      replace -> overload #1
    ///
    ///////////////////////////////////////////////////////////
    String &String::replace(const String &rep, const String &ins,
                            ReplaceOptions options)
    {
        // Finds the position of the string to replace
        QInt32 pos = indexOf(rep);
        if (pos == String::npos)
            return *this;

        // Replaces the string
        erase((QUInt32)pos, rep.length());
        insert((QUInt32)pos, ins);

        if (options == RO_OneEntry)
            return *this;
        else
            pos = indexOf(rep, pos+rep.length());

        while (pos != String::npos)
        {
            erase((QUInt32)pos, rep.length());
            insert((QUInt32)pos, ins);
            pos = indexOf(rep, pos+rep.length());
        }

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      replace -> overload #2
    ///
    ///////////////////////////////////////////////////////////
    String &String::replace(QUInt32 pos, QUInt32 size, const String &str)
    {
        // Replaces the string
        erase(pos, size);
        insert(pos, str);

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      erase
    ///
    ///////////////////////////////////////////////////////////
    String &String::erase(QUInt32 pos, QUInt32 cnt)
    {
        assert(pos + cnt <= length());

        m_String.erase(pos, cnt);
        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      erase -> overload #1
    ///
    ///////////////////////////////////////////////////////////
    String &String::erase(const String &str, EraseOptions options)
    {
        // Finds the position of the string erase
        QInt32 pos = indexOf(str);
        if (pos == String::npos)
            return *this;

        // Erases the string
        m_String.erase((QUInt32)pos, str.length());
        if (options == EO_OneEntry)
            return *this;
        else
            pos = indexOf(str, pos+str.length());

        while (pos != String::npos)
        {
            m_String.erase((QUInt32)pos, str.length());
            pos = indexOf(str, pos+str.length());
        }

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toLower
    ///
    ///////////////////////////////////////////////////////////
    String &String::toLower()
    {
        QUInt32 i = 0;
        QUInt32 len = length();
        if (startsWith(U"0x"))
            i = 2;

        for (; i < len; i++)
        {
            char32_t c = at(i);
            if (c >= 65 && c <= 90)
            {
                erase(i, 1);
                insert(i, c+32);
            }
        }

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      toUpper
    ///
    ///////////////////////////////////////////////////////////
    String &String::toUpper()
    {
        QUInt32 i = 0;
        QUInt32 len = length();
        if (startsWith(U"0x"))
            i = 2;

        for (; i < len; i++)
        {
            char32_t c = at(i);
            if (c >= 97 && c <= 122)
            {
                erase(i, 1);
                insert(i, c-32);
            }
        }

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      trim
    ///
    ///////////////////////////////////////////////////////////
    String &String::trim()
    {
        // Removes any leading whitespace
        std::locale loc;
        QUInt32 len = length();
        QUInt32 i; // first real character
        for (i = 0; i < len; i++)
            if (at(i) < 128)
                if (!std::isspace((char)at(i), loc))
                    break;

        if (i != 0)
            erase(0, i);
        len = length();

        // Removes any trailing whitespace
        for (i = len-1; i > 0; i--)
            if (at(i) < 128)
                if (!std::isspace((char)at(i), loc))
                    break;

        if (i != len-1)
            erase(i+1, (len-1) - i);

        return *this;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      args
    ///
    ///////////////////////////////////////////////////////////
    String &String::args(QUInt32 n, ...)
    {
        /* Variadic argument list */
        va_list argList;
        va_start(argList, n);

        // Replaces all arguments
        for (QUInt32 i = 0; i < n; i++)
        {
            String rep((QInt32)i);
            String arg = va_arg(argList, String);

            rep.insert(0, U'%');
            replace(rep, arg);
        }

        va_end(argList);
        return *this;
    }
}
