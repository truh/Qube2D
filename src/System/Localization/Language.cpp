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
}
