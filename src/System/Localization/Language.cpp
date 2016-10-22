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
#include <Qube2D/System/Localization/Language.hpp>
#include <Qube2D/System/Storage/File.hpp>
#include <Qube2D/Assets/Assets.hpp>
#include <Qube2D/Debug/Debug.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 21th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Language::Language()
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 21th, 2016
    /// \fn      Destructor
    ///
    /////////////////////////////////////////////////////////
    Language::~Language()
    {
        for (const char *key : m_Keys)
            delete[] key;

        delete m_Id;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 21th, 2016
    /// \fn      at -> const
    ///
    ///////////////////////////////////////////////////////////
    const String &Language::at(const char *key) const
    {
    #ifdef Q2D_DEBUG
        if (m_Map.find(key) == m_Map.end())
        {
            Q2DError("Key does not exist within the map. Key: %0", key);
            assert(false);
        }
    #endif

        return m_Map.at(key);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 21th, 2016
    /// \fn      at -> const
    ///
    ///////////////////////////////////////////////////////////
    const String &Language::at(QUInt32 index) const
    {
    #ifdef Q2D_DEBUG
        if (index >= m_List.size())
        {
            std::string s = std::to_string(index);
            Q2DError("Index out of bounds. Index: %0", s.c_str());
            assert(false);
        }
    #endif

        return m_List.at(index);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      load
    ///
    ///////////////////////////////////////////////////////////
    const char *Language::load(const char *path)
    {
        assert(path);


        // Converts the relative path to an absolute one.
        std::string filePath;
        if (Assets::isRelative(path))
            filePath = Assets::makePath(path);
        else
            filePath = path;


        File file;
        file.open(filePath.c_str(), FA_Read);

        // Fetches information about the language properties
        QUInt8 idSize, fiType;
        idSize = file.readByte();
        m_Id = file.readString(idSize);
        fiType = file.readByte();

        // Fetches all language entries
        QUInt32 strCount = file.readUInt32();
        QInt64 tblBegin = file.position();
        for (QUInt32 i = 0; i < strCount; ++i)
        {
            // Retrieves the entry position
            file.seek(tblBegin + (i * 4), SD_Begin);
            file.seek(static_cast<QInt64>(file.readUInt32()), SD_Begin);

            // 0 = indices, 1 = map
            if (fiType == 0)
            {
                QUInt32 strLen = file.readUInt32();
                m_List.push_back(file.readString(strLen));
            }
            else if (fiType == 1)
            {
                const char *strKey, *strVal;

                QUInt32 lenKey, lenVal;
                lenKey = file.readUInt32();
                strKey = file.readString(lenKey);
                lenVal = file.readUInt32();
                strVal = file.readString(lenVal);
                m_Keys.push_back(strKey);
                m_Map.insert(std::make_pair(strKey, String(strVal)));
            }
            else
            {
                Q2DErrorNoArg("ERROR"/*Q2D_LANG_ERROR_2*/);
                return NULL;
            }
        }
    }
}
