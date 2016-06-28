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


#ifndef __Q2D_ASSETMANAGER_HPP__
#define __Q2D_ASSETMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Uncopyable.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    AssetManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \class   AssetManager
    /// \brief   Abstracts out differences between platforms.
    ///
    /// Supports retrieving the executable path and all the
    /// files within a relative folder.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API AssetManager : Uncopyable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of AssetManager.
        ///
        ///////////////////////////////////////////////////////////
        AssetManager();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor -> virtual
        /// \brief  Destructs the devired AssetManager object.
        ///
        ///////////////////////////////////////////////////////////
        virtual ~AssetManager();


        ///////////////////////////////////////////////////////////
        /// \fn      executableDir -> virtual const
        /// \brief   Retrieves the executable directory.
        /// \returns the absolute path to the application.
        ///
        ///////////////////////////////////////////////////////////
        virtual const char *executableDir() const = 0;

        ///////////////////////////////////////////////////////////
        /// \fn      folderFiles -> virtual const
        /// \brief   Retrieves all files within a specified folder.
        /// \param   folder Relative-or-absolute folder path
        /// \param   extension File extension of the files to fetch
        /// \param   (out) count Amount of files found
        /// \returns an array of file paths that met the conditions.
        /// \returns NULL if no files or an error occured.
        ///
        ///////////////////////////////////////////////////////////
        virtual char **folderFiles
        (
            const char    *folder,
            const char    *extension,
            unsigned int  *count
        ) const = 0;


    protected:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        char *m_AppDirectory;

    };
}


#endif  // __Q2D_ASSETMANAGER_HPP__
