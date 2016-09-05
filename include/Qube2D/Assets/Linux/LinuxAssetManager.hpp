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


#ifndef __Q2D_LINUXASSETMANAGER_HPP__
#define __Q2D_LINUXASSETMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Assets/AssetManager.hpp>
#include <cstring>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    LinuxAssetManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 4th, 2016
    /// \class   LinuxAssetManager : AssetManager
    /// \brief   Implements the AssetManager for Linux.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API LinuxAssetManager : public AssetManager
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Pre-loads the executable path for Linux.
        ///
        ///////////////////////////////////////////////////////////
        LinuxAssetManager();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor -> implemented
        /// \brief  Frees the string allocated by the constructor.
        ///
        ///////////////////////////////////////////////////////////
        ~LinuxAssetManager();


        ///////////////////////////////////////////////////////////
        /// \fn      executableDir -> implemented
        /// \brief   Retrieves the executable directory on Linux.
        /// \returns the absolute path to the application.
        ///
        ///////////////////////////////////////////////////////////
        const char *executableDir() const;

        ///////////////////////////////////////////////////////////
        /// \fn      folderFiles -> implemented
        /// \brief   Retrieves all files within a specified folder.
        /// \param   folder Relative-or-absolute folder path
        /// \param   extension File extension of the files to fetch
        /// \param   (out) count Amount of files found
        /// \returns an array of file paths that met the conditions.
        /// \returns NULL if no files or an error occured.
        ///
        ///////////////////////////////////////////////////////////
        const char **folderFiles
        (
            const char    *folder,
            const char    *extension,
            unsigned int  *count
        ) const;

    };
}


#endif  // __Q2D_LINUXASSETMANAGER_HPP__
