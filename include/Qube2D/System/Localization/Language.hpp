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


#ifndef __Q2D_LANGUAGE_HPP__
#define __Q2D_LANGUAGE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Localization/String.hpp>
#include <memory>
#include <map>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Language.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 21th, 2016
    /// \class   Language
    /// \brief   Holds all strings for one language.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Language
    {

    #ifdef __Q2D_LIBRARY__

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Language.
        ///
        ///////////////////////////////////////////////////////////
        Language();

        ///////////////////////////////////////////////////////////
        /// \fn     Copy constructor
        /// \brief  Copies one language to another.
        ///
        ///////////////////////////////////////////////////////////
        Language(const Language &lang) = default;

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor
        /// \brief  Frees all strings.
        ///
        ///////////////////////////////////////////////////////////
        ~Language();


        ///////////////////////////////////////////////////////////
        /// \fn       load
        /// \brief    Attempts to load the given language file.
        /// \param    path Path to language file
        /// \returns  a pointer to the language identifier string.
        ///
        ///////////////////////////////////////////////////////////
        const char *load(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn     setStringMap
        /// \brief  Specifies the language map.
        /// \param  map Map containing string <> string pairs.
        ///
        ///////////////////////////////////////////////////////////
        void setStringMap(const std::map<const char *, String> &map);

        ///////////////////////////////////////////////////////////
        /// \fn     setStringList
        /// \brief  Specifies the language string list.
        /// \param  list List containing all strings.
        ///
        ///////////////////////////////////////////////////////////
        void setStringList(const std::vector<String> &list);

    #endif


        ///////////////////////////////////////////////////////////
        /// \fn       at -> const
        /// \brief    Retrieves the string corresponding to the key.
        /// \param    key Unique string key connected to value
        /// \returns  a reference to the value.
        ///
        ///////////////////////////////////////////////////////////
        const String &at(const char *key) const;

        ///////////////////////////////////////////////////////////
        /// \fn       at -> const
        /// \brief    Retrieves the string corresponding to the index.
        /// \param    index Index of the string in the list
        /// \returns  a reference to the value.
        ///
        ///////////////////////////////////////////////////////////
        const String &at(QUInt32 index) const;


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        std::map<const char *, String> m_Map;
        std::vector<String> m_List;
        std::vector<const char *> m_Keys;
        const char *m_Id;
    };
}


#endif  // __Q2D_LANGUAGE_HPP__
