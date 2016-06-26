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


#ifndef __Q2D_UNCOPYABLE_HPP__
#define __Q2D_UNCOPYABLE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Uncopyable.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \class   Uncopyable
    /// \brief   Suppresses copying a devired class object.
    ///
    /// This is achieved by completely removing the copy
    /// constructor and the assignment operator. Stack allocation
    /// therefore needs to be done this way: 'Type obj(args);'
    ///
    /// Functions can not return an object of that type directly,
    /// they must either be allocated dynamically within the
    /// function and returned as a pointer or as a reference in
    /// case returning a class member.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Uncopyable
    {
        
    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Uncopyable.
        ///
        ///////////////////////////////////////////////////////////
        Uncopyable() = default;

        ///////////////////////////////////////////////////////////
        /// \fn     Copy constructor
        /// \brief  Function disabled through the 'delete' keyword.
        ///
        ///////////////////////////////////////////////////////////
        Uncopyable(const Uncopyable &ref) = delete;

        ///////////////////////////////////////////////////////////
        /// \fn     Assignment operator
        /// \brief  Operator disabled through the 'delete' keyword.
        ///
        ///////////////////////////////////////////////////////////
        Uncopyable &operator =(const Uncopyable &ref) = delete;
        
    };
}


#endif  // __Q2D_UNCOPYABLE_HPP__
