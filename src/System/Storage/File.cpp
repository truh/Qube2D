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
#include <Qube2D/System/Storage/File.hpp>
#include <Qube2D/System/Debug.hpp>
#include <cstring>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    File::File()
        : Uncopyable(),
          m_Access(FA_Invalid),
          m_Direction(SD_Invalid),
          m_Position(0U)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \fn      open
    ///
    ///////////////////////////////////////////////////////////
    bool File::open(const char *path, FileAccess access)
    {
        assert(path != NULL);
        assert(access != FA_Invalid);


        // Determines whether the given path is relative or absolute
        // and converts the relative to an absolute in case.
        std::string pathFile;
        if (path[0] == ':' && path[1] == '/')
            /*pathFile = Assets::makePath(path)*/;
        else
            pathFile = path;


        // Determines the stream open flags
        std::ios_base::openmode mode = std::ios_base::binary;
        if ((access & FA_Read) != 0)
            mode |= std::ios_base::in;
        if ((access & FA_Write) != 0)
            mode |= std::ios_base::out;


        // Attempts to open the file
        m_Stream.open(pathFile, mode);
        m_Access = access;


        // Determines whether loading was successful
        return m_Stream.is_open();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \fn      save
    ///
    ///////////////////////////////////////////////////////////
    void File::save()
    {
        if ((m_Access & FA_Write) == 0)
            return;


        // Writes all entries to the stream
        for (unsigned i = 0; i < m_Offsets.size(); i++)
        {
            m_Stream.seekp(m_Offsets.at(i), std::ios_base::beg);
            m_Stream.write((const char *)m_Buffers.at(i).data(), m_Buffers.at(i).size());
        }


        // Saves all changes to the underlying file
        m_Stream.flush();


        // Restores the seeking position
        if (m_Direction == SD_Begin)
            m_Stream.seekp(m_Position, std::ios_base::beg);
        else
            m_Stream.seekp(m_Position, std::ios_base::end);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \fn      size
    ///
    ///////////////////////////////////////////////////////////
    QInt64 File::size() const
    {
        QInt64 size;


        // Reads until the EOF bit is set and then retrieves the
        // amount of characters read during this process.
        m_Stream.ignore(UINT_MAX);
        size = m_Stream.gcount();
        m_Stream.clear();


        // Restores the seeking position
        if (m_Direction == SD_Begin)
            m_Stream.seekg(m_Position, std::ios_base::beg);
        else
            m_Stream.seekg(m_Position, std::ios_base::end);


        return size;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 24th, 2016
    /// \fn      position
    ///
    ///////////////////////////////////////////////////////////
    QInt64 File::position() const
    {
        return m_Position;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      seek
    ///
    ///////////////////////////////////////////////////////////
    void File::seek(QInt64 pos, SeekDirection dir)
    {
        assert(pos > 0);
        assert(dir != SD_Invalid);


        // Changes the position in both sub-classes (istream & ostream)
        m_Stream.seekg(pos, (dir == SD_Begin) ? std::ios_base::beg : std::ios_base::end);
        m_Stream.seekp(pos, (dir == SD_Begin) ? std::ios_base::beg : std::ios_base::end);

        // Changes the member position variable
        m_Position = pos;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      readByte
    ///
    ///////////////////////////////////////////////////////////
    QUInt8 File::readByte() const
    {
        m_Position++;

        char value;
        this->m_Stream.read(&value, 1);
        return static_cast<QUInt8>(value);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      readUInt16
    ///
    ///////////////////////////////////////////////////////////
    QUInt16 File::readUInt16() const
    {
        m_Position += 2;

        char value[2];
        this->m_Stream.read(value, 2);
        return static_cast<QUInt16>((value[1] << 8) | value[0]);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      readUInt32
    ///
    ///////////////////////////////////////////////////////////
    QUInt32 File::readUInt32() const
    {
        m_Position += 4;

        char value[4];
        this->m_Stream.read(value, 4);
        return static_cast<QUInt32>
        (
               (value[3] << 24) |
               (value[2] << 16) |
               (value[1] << 8)  |
                value[0]
        );
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      readUInt64
    ///
    ///////////////////////////////////////////////////////////
    QUInt64 File::readUInt64() const
    {
        m_Position += 8;

        char value[8];
        this->m_Stream.read(value, 8);
        return static_cast<QUInt64>
        (
               ((QUInt64)value[7] << 56) |
               ((QUInt64)value[6] << 48) |
               ((QUInt64)value[5] << 40) |
               ((QUInt64)value[4] << 32) |
               ((QUInt64)value[3] << 24) |
               ((QUInt64)value[2] << 16) |
               ((QUInt64)value[1] << 8)  |
                (QUInt64)value[0]
        );
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      readBytes
    ///
    ///////////////////////////////////////////////////////////
    QUInt8 *File::readBytes(QUInt32 count) const
    {
        m_Position += count;

        char *buffer = new char[count];
        this->m_Stream.read(buffer, count);
        return reinterpret_cast<QUInt8* >(buffer);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      readString
    ///
    ///////////////////////////////////////////////////////////
    const char *File::readString(QUInt32 count) const
    {
        m_Position += count;

        char *string = new char[count + 1];
        string[count] = '\0';
        m_Stream.read(string, count);

        return string;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      writeByte
    ///
    ///////////////////////////////////////////////////////////
    void File::writeByte(QUInt8 byte)
    {
        assert(m_Position < size());

        m_Offsets.push_back(m_Position);
        m_Buffers.push_back({ byte });
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      writeUInt16
    ///
    ///////////////////////////////////////////////////////////
    void File::writeUInt16(QUInt16 u16)
    {
        assert(m_Position < size());

        m_Offsets.push_back(m_Position);
        m_Buffers.push_back
        ({
            (QUInt8)(u16 & 255),
            (QUInt8)(u16 >> 8)
        });
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      writeUInt32
    ///
    ///////////////////////////////////////////////////////////
    void File::writeUInt32(QUInt32 u32)
    {
        assert(m_Position < size());

        m_Offsets.push_back(m_Position);
        m_Buffers.push_back
        ({
             (QUInt8)(u32 & 255),
             (QUInt8)(u32 >> 8),
             (QUInt8)(u32 >> 16),
             (QUInt8)(u32 >> 24)
        });
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      writeUInt64
    ///
    ///////////////////////////////////////////////////////////
    void File::writeUInt64(QUInt64 u64)
    {
        assert(m_Position < size());

        m_Offsets.push_back(m_Position);
        m_Buffers.push_back
        ({
             (QUInt8)(u64 & 255),
             (QUInt8)(u64 >> 8),
             (QUInt8)(u64 >> 16),
             (QUInt8)(u64 >> 24),
             (QUInt8)(u64 >> 32),
             (QUInt8)(u64 >> 40),
             (QUInt8)(u64 >> 48),
             (QUInt8)(u64 >> 56)
        });
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      writeBytes
    ///
    ///////////////////////////////////////////////////////////
    void File::writeBytes(QUInt8 *bytes, QUInt32 size)
    {
        assert(m_Position < this->size());

        m_Offsets.push_back(m_Position);
        m_Buffers.push_back(std::vector<QUInt8>(bytes, bytes + size));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      writeString
    ///
    ///////////////////////////////////////////////////////////
    void File::writeString(const char *str)
    {
        assert(m_Position < size());

        m_Offsets.push_back(m_Position);
        m_Buffers.push_back(std::vector<QUInt8>((const QUInt8 *)str, (const QUInt8 *)(str + strlen(str))));
    }
}
