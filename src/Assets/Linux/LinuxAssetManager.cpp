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
#include <Qube2D/Assets/Linux/LinuxAssetManager.hpp>
#include <Qube2D/Assets/AssetErrors.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <cstdio>
#include <vector>
#include <unistd.h>
#include <dirent.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 4th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    LinuxAssetManager::LinuxAssetManager()
    {
        m_AppDirectory = new char[FILENAME_MAX];
        if (readlink("/proc/self/exe", m_AppDirectory, FILENAME_MAX) <= 0)
        {
            Q2DErrorNoArg(Q2D_ASSETS_ERROR_3);
            return;
        }


        std::string str(m_AppDirectory);
        QInt8 index = str.find_last_of("/");

        m_AppDirectory[index+1] = '\0';
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 4th, 2016
    /// \fn      Destructor
    ///
    //////////////////////////////////////////////////////////
    LinuxAssetManager::~LinuxAssetManager()
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 4th, 2016
    /// \fn      executableDir
    ///
    //////////////////////////////////////////////////////////
    const char *LinuxAssetManager::executableDir() const
    {
        return m_AppDirectory;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 4th, 2016
    /// \fn      folderFiles
    ///
    //////////////////////////////////////////////////////////
    const char **LinuxAssetManager::folderFiles(
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
        std::vector<const char *> fileVec;


        // Determines whether the given folder is relative
        if (folder[0] == ':' && folder[1] == '/')
        {
            strFolder.erase(0, 1);
            strFolder.insert(0, m_AppDirectory);
        }


        // Prepares the extension string for Linux
        if (extension[0] != '.')
            strExt.insert(0, ".");


        // Opens the directory
        DIR *dir = opendir(strFolder.c_str());
        if (!dir)
            return NULL;

        struct dirent *file;
        errno = 0;

        // Loops through every file and compares extension
        while ((file = readdir(dir)) != NULL)
        {
            // Check for invalid file-names
            if (!strcmp(file->d_name, "."))  continue;
            if (!strcmp(file->d_name, "..")) continue;


            // Compare extension string
            if (!strcmp(strrchr(file->d_name, '.'), strExt.c_str()))
                fileVec.push_back(file->d_name);
        }


        // Assures that at least one file matched the conditions
        if (fileVec.size() == 0)
        {
            Q2DError(Q2D_ASSETS_ERROR_4, strFolder.c_str());
            return NULL;
        }


        // Copies the vector contents to a vanilla array
        const char **files = new const char *[fileVec.size()];
        std::copy(fileVec.begin(), fileVec.end(), files);

        // Specifies the return/output values
        *count = fileVec.size();
        return files;
    }
}
