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
#   include <Qube2D/Assets/Assets.hpp>
#ifdef Q2D_SYS_WINDOWS
#   include <Qube2D/Assets/Win32/Win32AssetManager.hpp>
#elif Q2D_SYS_LINUX
#   include <Qube2D/Assets/Linux/LinuxAssetManager.hpp>
#elif Q2D_SYS_FREEBSD
#   include <Qube2D/Assets/FreeBSD/FreeBSDAssetManager.hpp>
#elif Q2D_SYS_ANDROID
#   include <Qube2D/Assets/Android/AndroidAssetManager.hpp>
#elif Q2D_SYS_MACOS
#   include <Qube2D/Assets/MacOS/MacOSAssetManager.hpp>
#elif Q2D_SYS_IOS
#   include <Qube2D/Assets/IOS/IOSAssetManager.hpp>
#endif
#   include <string>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 28th, 2016
    /// \def     m_Manager, m_Buffer
    /// \brief   Defines the static member variables.
    ///
    ///////////////////////////////////////////////////////////
    AssetManager    *Assets::m_Manager  = NULL;
    char            *Assets::m_Buffer   = NULL;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 28th, 2016
    /// \fn      initialize
    ///
    ///////////////////////////////////////////////////////////
    void Assets::initialize()
    {

#   ifdef Q2D_SYS_WINDOWS
        m_Manager = new Win32AssetManager();
#   elif Q2D_SYS_LINUX
        m_Manager = new LinuxAssetManager();
#   elif Q2D_SYS_FREEBSD
        m_Manager = new FreeBSDAssetManager();
#   elif Q2D_SYS_ANDROID
        m_Manager = new AndroidAssetManager();
#   elif Q2D_SYS_MACOS
        m_Manager = new MacOSAssetManager();
#   elif Q2D_SYS_IOS
        m_Manager = new IOSAssetManager();
#   endif

    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 28th, 2016
    /// \fn      dispose
    ///
    ///////////////////////////////////////////////////////////
    void Assets::dispose()
    {
        if (m_Manager != NULL)
            delete m_Manager;
        if (m_Buffer != NULL)
            delete m_Buffer;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 28th, 2016
    /// \fn      isRelative -> static
    ///
    ///////////////////////////////////////////////////////////
    bool Assets::isRelative(const char *path)
    {
        return path[0] == ':' &&
               path[1] == '/';
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 28th, 2016
    /// \fn      makePath -> static
    ///
    ///////////////////////////////////////////////////////////
    const char *Assets::makePath(const char *path)
    {
        // Deletes the previous buffer, if existing
        if (m_Buffer != NULL)
            delete m_Buffer;


        std::string strAppl = m_Manager->executableDir();
        std::string strPath = path;
        strPath.erase(0U, 1U);


        // Appends the path to the application
        strAppl.append(strPath);

        // Allocates a new string and copies the contents
        m_Buffer = new char[strAppl.length() + 1];
        memcpy(m_Buffer, strAppl.data(), strAppl.length());
        m_Buffer[strAppl.length()] = '\0';


        // String should not be free'd manually!
        return m_Buffer;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 29th, 2016
    /// \fn      getFolderFiles -> static
    ///
    ///////////////////////////////////////////////////////////
    char **Assets::folderFiles
    (
        const char    *folder,
        const char    *extension,
        unsigned int  *count
    )
    {
        return m_Manager->folderFiles(folder, extension, count);
    }
}
