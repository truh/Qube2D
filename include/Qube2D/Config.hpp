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


#ifndef __Q2D_CONFIG_HPP__
#define __Q2D_CONFIG_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Config.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     Q2D_SYS
    ///
    /// The macro Q2D_SYS is used to determine the underlying
    /// operating system in order to call system-specific
    /// functions, such as 'readlink' on unix systems.
    ///
    ///////////////////////////////////////////////////////////
    
    #   if defined (_WIN32)
    #       define Q2D_SYS_WINDOWS
    #   elif defined (__unix__)
    #       if defined (__linux__)
    #          define Q2D_SYS_LINUX
    #       elif defined (__FreeBSD__)
    #          define Q2D_SYS_FREEBSD
    #       elif defined (__ANDROID__)
    #           define Q2D_SYS_ANDROID
    #       endif
    #   elif defined (__APPLE__) && defined (__MACH__)
    #       include "TargetConditionals.h"
    #       if TARGET_OS_MAC
    #           define Q2D_SYS_MACOS
    #       else
    #           define Q2D_SYS_IOS
    #       endif
    #   else
    #       error Underlying system not supported!
    #   endif
    
    
    ///////////////////////////////////////////////////////////
    /// \file    Config.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     Q2D_API
    ///
    /// The macro Q2D_API is used to export symbols to the
    /// Qube2D dynamic link library or import symbols from
    /// it to link to Qube2D classes and functions.
    ///
    ///////////////////////////////////////////////////////////
    
    #   if defined (Q2D_SYS_WINDOWS)
    #       if defined (__Q2D_LIBRARY__)
    #          define Q2D_API __declspec(dllexport)
    #       else
    #          define Q2D_API __declspec(dllimport)
    #       endif
    #   else
    #       if __GNUC__ >= 4
    #          define Q2D_API __attribute__((__visibility__("default")))
    #       else
    #          define Q2D_API ///< No export/import attribute
    #       endif
    #   endif
    
    
    ///////////////////////////////////////////////////////////
    /// \file    Config.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     Q2D_TPL
    ///
    /// The macro Q2D_TPL is used to instantiate pre-defined
    /// templates, such as 'Qube2D::Vector<int>'. Dynamic link
    /// libraries require you to export these types, because
    /// compilers produce different code for templates when
    /// they have different settings.
    ///
    ///////////////////////////////////////////////////////////
    
    #   if defined (__Q2D_LIBRARY__)
    #      define Q2D_TPL template class Q2D_API
    #   else
    #      define Q2D_TPL extern template class
    #   endif
}


    /* Platform independent type definitions */
    typedef char                        QInt8;
    typedef unsigned char               QUInt8;
    typedef signed   short              QInt16;
    typedef unsigned short              QUInt16;
    typedef signed   int                QInt32;
    typedef unsigned int                QUInt32;
    
    /* 64-bit types act differently on MSVC */
    #if defined (_MSC_VER)
    
        typedef signed   __int64        QInt64;
        typedef unsigned __int64        QUInt64;
        
    #else
    
        typedef signed   long long      QInt64;
        typedef unsigned long long      QUInt64;
        
    #endif
    
    /* Floating point types */
    typedef float                       QFloat;
    typedef double                      QDouble;


#endif  // __Q2D_CONFIG_HPP__
