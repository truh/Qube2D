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
#include <Qube2D/Assets/Win32/Win32AssetManager.hpp>
#include <Qube2D/Assets/AssetErrors.hpp>
#include <Qube2D/System/Debug.hpp>
#include <windows.h>
#include <vector>
#include <string>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Win32AssetManager::Win32AssetManager()
        : AssetManager()
    {
        // Retrieves the full executable path
        m_AppDirectory = new char[MAX_PATH];
        if (!GetModuleFileNameA(NULL, m_AppDirectory, MAX_PATH))
        {
            Q2DErrorNoArg(Q2D_ASSETS_ERROR_3);
            return;
        }

        std::string str(m_AppDirectory);
        QInt8 index = str.find_last_of("\\/");

        // Removes the executable name
        m_AppDirectory[index+1] = '\0';
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \fn      Destructor
    ///
    ///////////////////////////////////////////////////////////
    Win32AssetManager::~Win32AssetManager()
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \fn      executableDir
    ///
    ///////////////////////////////////////////////////////////
    const char *Win32AssetManager::executableDir() const
    {
        return m_AppDirectory;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \fn      folderFiles
    ///
    ///////////////////////////////////////////////////////////
    const char **Win32AssetManager::folderFiles
    (
        const char *folder,
        const char *extension,
        unsigned int *count
    ) const
    {
        assert(folder);
        assert(extension);
        assert(count);


        std::string strFolder = folder;
        std::string strExt = extension;

        // Determines whether the given folder is relative
        if (folder[0] == ':' && folder[1] == '/')
        {
            strFolder.erase(0, 1);
            strFolder.insert(0, m_AppDirectory);
        }

        // Repairs the extension string
        if (extension[0] != '*' && extension[1] != '.')
            strExt.insert(0, "*.");

        strFolder.append(strExt);


        // Searches the first file in the folder
        WIN32_FIND_DATAA findData;
        HANDLE findHandle = FindFirstFileA(strFolder.c_str(), &findData);

        // Determines whether there is any file
        if (findHandle == INVALID_HANDLE_VALUE)
            return NULL;

        // Finds all remaining files
        std::vector<const char *> foundFiles;
        do
        {
          foundFiles.push_back(findData.cFileName);
        } while (FindNextFileA(findHandle, &findData));


        // Assures that at least one file matched the conditions
        if (foundFiles.size() == 0)
        {
            // Windows requires the extension string after the folder; we do not need it.
            strFolder.erase(strFolder.length()-strExt.length(), strExt.length());
            Q2DError(Q2D_ASSETS_ERROR_4, strFolder.c_str());
            return;
        }


        // Copies the contents from the vector to a vanilla array
        const char **files = new const char *[foundFiles.size()];
        std::copy(foundFiles.begin(), foundFiles.end(), files);

        // Specifies the return/output values
        *count = foundFiles.size();
        return files;
    }
}
