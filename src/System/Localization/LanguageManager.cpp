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
#include <Qube2D/Assets/Assets.hpp>
#include <Qube2D/System/Localization/LanguageManager.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 27th, 2016
    /// \fn      loadFromFolder
    ///
    ///////////////////////////////////////////////////////////
    int LanguageManager::loadFromFolder(const char *dir, const char *ext)
    {
        if (ext == NULL)
            ext = "qdl";


        // Retrieves all files within the folder
        QUInt32 fileCount, i;
        const char *files = Assets::folderFiles(dir, ext, &fileCount);

        // Attempts to load all languages
        for (i = 0; i < fileCount; i++)
        {
            Language language;
            if (!language.load(files[i]))
            {
                Q2DError(Q2D_LANG_ERROR_0, files[i]);
                return -1;
            }

            m_Languages.push_back(language);
        }

        // Defaults the selected language to 0
        m_ActiveLanguage = &m_Languages.at(0);


        return static_cast<QUInt32>(i);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 27th, 2016
    /// \fn      setActiveLanguage
    ///
    ///////////////////////////////////////////////////////////
    void LanguageManager::setActiveLanguage(const char *lang)
    {
        auto it = std::find(m_Identifiers.begin(), m_Identifiers.end(), lang);
        if (it == m_Identifiers.end())
        {
            Q2DError(Q2D_LANG_ERROR_1, lang);
            return;
        }


        m_ActiveLanguage = &(*it);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 27th, 2016
    /// \fn      at
    ///
    ///////////////////////////////////////////////////////////
    const String &LanguageManager::at(const char *key)
    {
        return m_ActiveLanguage->at(key);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 27th, 2016
    /// \fn      at
    ///
    ///////////////////////////////////////////////////////////
    const String &LanguageManager::at(QUInt32 index)
    {
        return m_ActiveLanguage->at(index);
    }
}
