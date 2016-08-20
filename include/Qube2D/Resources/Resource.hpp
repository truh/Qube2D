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


#ifdef  __Q2D_EXPOSE_RESOURCE__
#ifndef __Q2D_RESOURCE_HPP__
#define __Q2D_RESOURCE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Resources/ResTypes.hpp>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Resource.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 9th, 2016
    /// \class   Resource
    /// \brief   Base class for all resource classes.
    ///
    /// This class creates an interface between Qube2D and the
    /// game. Through this class, Qube2D is capable of reading
    /// resources defined in the header of the resource classes.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Resource
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn      getResources
        /// \brief   Returns a vector defined in the resource class.
        /// \returns a vector containing all the resources.
        ///
        ///////////////////////////////////////////////////////////
        virtual std::vector<ResEntry *> getResources() = 0;

    };
}


#endif  // __Q2D_RESOURCE_HPP__
#endif  // __Q2D_EXPOSE_RESOURCE__
