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
#ifndef __Q2D_RESTYPES_HPP__
#define __Q2D_RESTYPES_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    ResTypes.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 9th, 2016
    /// \def     ResTypes
    /// \brief   Defines all resource types within Qube2D.
    ///
    ///////////////////////////////////////////////////////////
    enum ResTypes
    {
        RT_Bytes,
        RT_Utf8,
        RT_Utf16,
        RT_Utf32,
        RT_Image,
        RT_Texture,
        RT_Animation
    };


    ///////////////////////////////////////////////////////////
    /// \file    ResTypes.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 9th, 2016
    /// \struct  ResEntry
    /// \brief   Defines a resource with name, data and type.
    ///
    ///////////////////////////////////////////////////////////
    struct ResEntry
    {
        const char *name;   ///< Unique resource name
        ResTypes type;      ///< Resource type
        const QUInt8 *data; ///< Raw byte data
    };

    ///////////////////////////////////////////////////////////
    /// \file    ResTypes.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 9th, 2016
    /// \struct  PrivateRes
    /// \brief   Private resource structure, in Qube2D only
    ///
    ///////////////////////////////////////////////////////////
    struct PrivateRes
    {
        ResTypes type;      ///< Resource type
        const QUInt8 *data; ///< Raw byte data
    };

}


#endif  // __Q2D_RESTYPES_HPP__
#endif  // __Q2D_EXPOSE_RESOURCE__
