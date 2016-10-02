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


#ifndef __Q2D_LANGUAGEMANAGER_HPP__
#define __Q2D_LANGUAGEMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Localization/Language.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    LanguageManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 21th, 2016
    /// \class   LanguageManager
    /// \brief   Manages all languages in the game.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API LanguageManager
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn       loadFromFolder
        /// \brief    Attempts to load language files from a folder.
        /// \param    dir Folder containing the language files
        /// \param    (opt) ext Extension of the language file(s)
        /// \returns  the amount of languages loaded.
        ///
        ///////////////////////////////////////////////////////////
        static int loadFromFolder(const char *dir, const char *ext = NULL);

        ///////////////////////////////////////////////////////////
        /// \fn    setActiveLanguage
        /// \brief Specifies the currently active language.
        /// \param lang Language identifier as string (e.g. "en")
        ///
        ///////////////////////////////////////////////////////////
        static void setActiveLanguage(const char *lang);

        ///////////////////////////////////////////////////////////
        /// \fn       at -> const
        /// \brief    Retrieves the string corresponding to the key.
        /// \param    key Unique string key connected to value
        /// \returns  a reference to the value.
        ///
        ///////////////////////////////////////////////////////////
        static const String &at(const char *key);

        ///////////////////////////////////////////////////////////
        /// \fn       at -> const
        /// \brief    Retrieves the string corresponding to the index.
        /// \param    index Index of the string in the list
        /// \returns  a reference to the value.
        ///
        ///////////////////////////////////////////////////////////
        static const String &at(QUInt32 index);


    private:

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static std::vector<Language> m_Languages;
        static std::vector<const char *> m_Identifiers;
        static Language *m_ActiveLanguage;

    };
}


#endif  // __Q2D_LANGUAGEMANAGER_HPP__
