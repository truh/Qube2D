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


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Structs/GLColor.hpp>
#include <Qube2D/System/Structs/Color.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    GLColor::GLColor()
        : cr(0.0f),
          cg(0.0f),
          cb(0.0f),
          ca(1.0f)
    {
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Constructor
    ///
    ///////////////////////////////////////////////////////////
    GLColor::GLColor(QFloat rgb, QFloat alpha)
        : cr(rgb),
          cg(rgb),
          cb(rgb),
          ca(alpha)
    {
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Constructor
    ///
    ///////////////////////////////////////////////////////////
    GLColor::GLColor(QFloat red, QFloat green, QFloat blue, QFloat alpha)
        : cr(red),
          cg(green),
          cb(blue),
          ca(alpha)
    {
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Copy Constructor
    ///
    ///////////////////////////////////////////////////////////
    GLColor::GLColor(const GLColor &color)
        : cr(color.cr),
          cg(color.cg),
          cb(color.cb),
          ca(color.ca)
    {
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Assignment operator
    ///
    ///////////////////////////////////////////////////////////
    GLColor &GLColor::operator =(const GLColor &color)
    {
        cr = color.cr;
        cg = color.cg;
        cb = color.cb;
        ca = color.ca;
        
        return *this;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      r -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat GLColor::r() const
    {
        return cr;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      g -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat GLColor::g() const
    {
        return cg;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      b -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat GLColor::b() const
    {
        return cb;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      a -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat GLColor::a() const
    {
        return ca;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setR
    ///
    ///////////////////////////////////////////////////////////
    void GLColor::setR(QFloat red)
    {
        cr = red;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setG
    ///
    ///////////////////////////////////////////////////////////
    void GLColor::setG(QFloat green)
    {
        cg = green;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setB
    ///
    ///////////////////////////////////////////////////////////
    void GLColor::setB(QFloat blue)
    {
        cb = blue;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setA
    ///
    ///////////////////////////////////////////////////////////
    void GLColor::setA(QFloat alpha)
    {
        ca = alpha;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      toRGBA -> const
    ///
    ///////////////////////////////////////////////////////////
    Color GLColor::toRGBA() const
    {
        QUInt8 rgba_r = static_cast<QUInt8>(cr * 255.0f);
        QUInt8 rgba_g = static_cast<QUInt8>(cg * 255.0f);
        QUInt8 rgba_b = static_cast<QUInt8>(cb * 255.0f);
        QUInt8 rgba_a = static_cast<QUInt8>(ca * 255.0f);
        
        return Color(rgba_r, rgba_g, rgba_b, rgba_a);
    }
}
