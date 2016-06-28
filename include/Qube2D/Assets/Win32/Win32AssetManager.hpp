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


#ifndef __Q2D_WIN32ASSETMANAGER_HPP__
#define __Q2D_WIN32ASSETMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Assets/AssetManager.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Win32AssetManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \class   Win32AssetManager : AssetManager
    /// \brief   Implements the AssetManager for MS Windows.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Win32AssetManager : public AssetManager
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Pre-loads the executable path for Windows.
        ///
        ///////////////////////////////////////////////////////////
        Win32AssetManager();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor -> implemented
        /// \brief  Frees the string allocated by the constructor.
        ///
        ///////////////////////////////////////////////////////////
        ~Win32AssetManager();


        ///////////////////////////////////////////////////////////
        /// \fn      executableDir -> implemented
        /// \brief   Retrieves the executable directory on Windows.
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
        char **folderFiles
        (
            const char    *folder,
            const char    *extension,
            unsigned int  *count
        ) const;

    };
}


#endif  // __Q2D_WIN32ASSETMANAGER_HPP__
