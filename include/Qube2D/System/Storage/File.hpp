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
//  along with Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


#ifndef __Q2D_FILE_HPP__
#define __Q2D_FILE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Uncopyable.hpp>
#include <Qube2D/System/Storage/FileEnums.hpp>
#include <iostream>
#include <fstream>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    File.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \class   File
    /// \brief   Reads from and writes to a file.
    ///
    /// This class uses streams but is also able to discard
    /// any changes made to the file upon closing the stream.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API File : Uncopyable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::File.
        ///
        ///////////////////////////////////////////////////////////
        File();


        ///////////////////////////////////////////////////////////
        /// \fn      open
        /// \brief   Attempts to open a file on the disk.
        ///
        /// A relative path in Qube2D includes the prefix ':/' in
        /// order to distinguish between relative and absolute paths.
        /// Example for relative path: ':/assets/file.txt'
        ///
        /// \param   path Relative or absolute file path
        /// \param   access File access (read|write)
        /// \returns true if file opened successfully.
        ///
        ///////////////////////////////////////////////////////////
        bool open(const char *path, FileAccess access);

        ///////////////////////////////////////////////////////////
        /// \fn     save
        /// \brief  Saves the buffered data to the file.
        ///
        /// Does absolutely nothing if the buffer is empty.
        ///
        ///////////////////////////////////////////////////////////
        void save();


        ///////////////////////////////////////////////////////////
        /// \fn      size -> const
        /// \brief   Retrieves the file's size in a portable way.
        ///
        /// This function may be expensive, it is not recommended to
        /// call it extensively.
        ///
        /// \returns the size of the file, in bytes.
        ///
        ///////////////////////////////////////////////////////////
        QInt64 size() const;

        ///////////////////////////////////////////////////////////
        /// \fn      position -> const
        /// \brief   Retrieves the current streaming position.
        /// \returns the streaming position, in bytes.
        ///
        ///////////////////////////////////////////////////////////
        QInt64 position() const;


        ///////////////////////////////////////////////////////////
        /// \fn     seek
        /// \brief  Modifies the current streaming position.
        ///
        /// Modifies both, the reading (getting) and writing
        /// (putting) stream position.
        ///
        /// \param  pos Position within the stream
        /// \param  (opt) dir Seeking direction
        ///
        ///////////////////////////////////////////////////////////
        void seek(QInt64 pos, SeekDirection dir);


        ///////////////////////////////////////////////////////////
        /// \fn      readByte -> const
        /// \brief   Reads one byte and advances position by one.
        /// \returns an unsigned 8-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QUInt8 readByte() const;

        ///////////////////////////////////////////////////////////
        /// \fn      readUInt16 -> const
        /// \brief   Reads one ushort and advances position by two.
        /// \returns an unsigned 16-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QUInt16 readUInt16() const;

        ///////////////////////////////////////////////////////////
        /// \fn      readUInt32 -> const
        /// \brief   Reads one uint and advances position by four.
        /// \returns an unsigned 32-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QUInt32 readUInt32() const;

        ///////////////////////////////////////////////////////////
        /// \fn      readUInt64 -> const
        /// \brief   Reads one ulong and advances position by eight.
        /// \returns an unsigned 64-bit value.
        ///
        ///////////////////////////////////////////////////////////
        QUInt64 readUInt64() const;

        ///////////////////////////////////////////////////////////
        /// \fn      readBytes -> const
        /// \brief   Reads the specified amount of bytes.
        ///
        /// Returns NULL if position exceeded the file's bounds.
        ///
        /// \param   count Amount of bytes to read
        /// \returns an array of bytes of specified size.
        ///
        ///////////////////////////////////////////////////////////
        QUInt8 *readBytes(QUInt32 count) const;

        ///////////////////////////////////////////////////////////
        /// \fn      readString -> const
        /// \brief   Reads a string with given amount of characters.
        ///
        /// Returns NULL if position exceeded the file's bounds.
        ///
        /// \param   count Amount of characters to read
        /// \returns an array of characters of specified size.
        ///
        ///////////////////////////////////////////////////////////
        const char *readString(QUInt32 count) const;


        ///////////////////////////////////////////////////////////
        /// \fn     writeByte
        /// \brief  Writes one byte to the buffer.
        ///
        /// The stream position is advanced by one afterwards.
        ///
        /// \param byte Unsigned 8-bit value to write
        ///
        ///////////////////////////////////////////////////////////
        void writeByte(QUInt8 byte);

        ///////////////////////////////////////////////////////////
        /// \fn     writeUInt16
        /// \brief  Writes one ushort to the buffer.
        ///
        /// The stream position is advanced by two afterwards.
        ///
        /// \param  u16 Unsigned 16-bit value to write
        ///
        ///////////////////////////////////////////////////////////
        void writeUInt16(QUInt16 u16);

        ///////////////////////////////////////////////////////////
        /// \fn     writeUInt32
        /// \brief  Writes one uint to the buffer.
        ///
        /// The stream position is advanced by four afterwards.
        ///
        /// \param  u32 Unsigned 32-bit value to write
        ///
        ///////////////////////////////////////////////////////////
        void writeUInt32(QUInt32 u32);

        ///////////////////////////////////////////////////////////
        /// \fn     writeUInt64
        /// \brief  Writes one ulong to the buffer.
        ///
        /// The stream position is advanced by eight afterwards.
        ///
        /// \param  u64 Unsigned 64-bit value to write
        ///
        ///////////////////////////////////////////////////////////
        void writeUInt64(QUInt64 u64);

        ///////////////////////////////////////////////////////////
        /// \fn     writeBytes
        /// \brief  Writes multiple bytes to the buffer.
        ///
        /// The stream position is advanced by the number of bytes
        /// specified in the second argument.
        ///
        /// \param  bytes Byte array to write
        /// \param  size Size of the byte array
        ///
        ///////////////////////////////////////////////////////////
        void writeBytes(QUInt8 *bytes, QUInt32 size);

        ///////////////////////////////////////////////////////////
        /// \fn     writeString
        /// \brief  Writes the specified string to the buffer.
        ///
        /// The stream position is advanced by the string length.
        /// No size parameter must be specified.
        ///
        /// \param  str NULL terminated UTF-8 string.
        ///
        ///////////////////////////////////////////////////////////
        void writeString(const char *str);


    private:

        ///////////////////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////////////////
        mutable std::fstream m_Stream;              ///< Underlying file stream
        std::vector<QInt64> m_Offsets;              ///< Buffer offsets
        std::vector<std::vector<QUInt8>> m_Buffers; ///< Buffered byte arrays
        FileAccess m_Access;                        ///< Access flags
        SeekDirection m_Direction;                  ///< Current seek direction
        mutable QInt64 m_Position;                  ///< Current stream position

    };
}


#endif  // __Q2D_FILE_HPP__
