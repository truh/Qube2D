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


#ifndef __Q2D_ASSETS_HPP__
#define __Q2D_ASSETS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Debug.hpp>
#include <Qube2D/System/Storage/File.hpp>
#include <Qube2D/System/Localization/String.hpp>
#include <Qube2D/Assets/AssetManager.hpp>
#include <Qube2D/Assets/AssetErrors.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Assets.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 27th, 2016
    /// \class   Assets
    /// \brief   Provides useful functions to handle resources.
    ///
    /// The function load<T> may be specialized with a Qube2D
    /// type such as Texture, but also types like char pointer
    /// (string) are supported.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Assets
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     initialize -> static
        /// \brief  Initializes a platform-specific AssetManager.
        ///
        ///////////////////////////////////////////////////////////
        static void initialize();

        ///////////////////////////////////////////////////////////
        /// \fn     dispose -> static
        /// \brief  Disposes of the initialized AssetManager.
        ///
        ///////////////////////////////////////////////////////////
        static void dispose();


        ///////////////////////////////////////////////////////////
        /// \fn      isRelative -> static
        /// \brief   Determines whether the path is relative.
        ///
        /// A path is considered relative if the given sequence
        /// starts with ':/'. The sequence ':/' is platform-
        /// independent and is not ambiguous to any other paths.
        ///
        /// \param   path Relative-or-absolute asset path
        /// \returns true if the given path is a relative one.
        ///
        ///////////////////////////////////////////////////////////
        static bool isRelative(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn      makePath -> static
        /// \brief   Converts a relative path to an absolute path.
        /// \param   path Relative path to a resource file
        /// \returns the absolute path of the resource file
        ///
        ///////////////////////////////////////////////////////////
        static const char *makePath(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn      folderFiles -> static
        /// \brief   Retrieves all files within a specified folder.
        /// \param   folder Relative-or-absolute folder path
        /// \param   extension File extension of the files to fetch
        /// \param   (out) count Amount of files found
        /// \returns an array of file paths that met the conditions.
        /// \returns NULL if no files or an error occured.
        ///
        ///////////////////////////////////////////////////////////
        static const char **folderFiles(const char *folder,
                                        const char *extension,
                                        unsigned int *count);


        ///////////////////////////////////////////////////////////
        /// \fn      load<T> -> static
        /// \brief   Attempts to load a resource of type T.
        ///
        /// If type T is not the type of a specialized function,
        /// the function call defaults to this function and throws
        /// a static assertion error.
        ///
        /// \param   path Relative-or-absolute asset path
        /// \returns an initialized instance of T.
        ///
        ///////////////////////////////////////////////////////////
        template <typename T> static T load(const char *path);

        ///////////////////////////////////////////////////////////
        /// \fn      loadTextFile -> static
        /// \brief   Attempts to load the given text resource.
        ///
        /// Determines the encoding of the given text file and
        /// loads it into an encoding-portable Qube2D::String.
        /// An empty Qube2D::String is returned upon an error.
        ///
        /// \param   path Relative-or-absolute asset path
        /// \returns a Qube2D::String containing the text.
        ///
        ///////////////////////////////////////////////////////////
        static String loadTextFile(const char *path);


    private:

        //////////////////////////////////////////////////////////////
        // Class members
        //
        //////////////////////////////////////////////////////////////
        static AssetManager *m_Manager; ///< Platform-specific manager
        static char *m_Buffer;          ///< Buffer for 'makePath'

    };


    // template function definitions
    #include <Qube2D/Assets/Assets.inl>
}


#endif  // __Q2D_ASSETS_HPP__
