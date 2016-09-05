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


#ifndef __Q2D_RESOURCES_HPP__
#define __Q2D_RESOURCES_HPP__
#define __Q2D_EXPOSE_RESOURCE__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Resources/Resource.hpp>
#include <map>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Resources.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 9th, 2016
    /// \class   Resources
    /// \brief   Initializes and loads resource files.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Resources
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     initialize -> static
        /// \brief  Initializes the given resource class.
        ///
        /// Throws a static assertion error if the given resoure
        /// class is not a type of Qube2D::Resource.
        ///
        ///////////////////////////////////////////////////////////
        template <typename T> static void initialize();

        ///////////////////////////////////////////////////////////
        /// \fn     load -> static
        /// \brief  Loads a resource of given type and name
        /// \param  name Resource name, e.g. "res:/folder/file"
        /// \note   Resource name without file extension!
        ///
        ///////////////////////////////////////////////////////////
        template <typename T> static T load(const char *name);


    private:

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static std::map<const char*, PrivateRes> m_Resources;

    };



    // template function definitions
    #include <Qube2D/Resources/Resources.inl>
}


#endif  // __Q2D_RESOURCES_HPP__
