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
#include <Qube2D/System/Structs/Color.hpp>
#include <Qube2D/System/Structs/GLColor.hpp>
#include <bitset>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Color::Color()
        : cr(0),
          cg(0),
          cb(0),
          ca(255)
    {
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      Constructor
    ///
    ///////////////////////////////////////////////////////////
    Color::Color(QUInt8 rgb, QUInt8 alpha)
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
    Color::Color(QUInt8 red, QUInt8 green, QUInt8 blue, QUInt8 alpha)
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
    Color::Color(const Color &color)
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
    Color &Color::operator =(const Color &color)
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
    QUInt8 Color::r() const
    {
        return cr;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      g -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt8 Color::g() const
    {
        return cg;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      b -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt8 Color::b() const
    {
        return cb;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      ca -> const
    ///
    ///////////////////////////////////////////////////////////
    QUInt8 Color::a() const
    {
        return ca;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setR
    ///
    ///////////////////////////////////////////////////////////
    void Color::setR(QUInt8 red)
    {
        cr = red;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setG
    ///
    ///////////////////////////////////////////////////////////
    void Color::setG(QUInt8 green)
    {
        cg = green;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setB
    ///
    ///////////////////////////////////////////////////////////
    void Color::setB(QUInt8 blue)
    {
        cb = blue;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      setA
    ///
    ///////////////////////////////////////////////////////////
    void Color::setA(QUInt8 alpha)
    {
        ca = alpha;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      invert
    ///
    ///////////////////////////////////////////////////////////
    void Color::invert()
    {
        // Substracts the current components from 255
        // whereas the alpha component remains untouched.
        cr = (255 - cr);
        cg = (255 - cg);
        cb = (255 - cb);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      brighten
    ///
    ///////////////////////////////////////////////////////////
    void Color::brighten(QFloat factor)
    {
        // Performs no operation if out of range
        if (factor < 0 || factor > 2)
            return;
            
        
        // Multiplies each component with the factor
        // whereas the alpha component remains untouched.
        cr = static_cast<QUInt8>(cr * factor);
        cg = static_cast<QUInt8>(cg * factor);
        cb = static_cast<QUInt8>(cb * factor);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      multiplyBlend
    ///
    ///////////////////////////////////////////////////////////
    void Color::multiplyBlend(const Color &color)
    {
        // Converts the given color to float components
        float fac_r = color.cr / 255.0f;
        float fac_g = color.cg / 255.0f;
        float fac_b = color.cb / 255.0f;
        
        // Multiplies each component with the corresponding factor,
        // the color will appear darker than it did before.
        cr *= fac_r;
        cg *= fac_g;
        cb *= fac_b;
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      additiveBlend
    ///
    ///////////////////////////////////////////////////////////
    void Color::additiveBlend(const Color &color)
    {
        // Adds each corresponding component
        QUInt32 add_r = cr + color.cr;
        QUInt32 add_g = cg + color.cg;
        QUInt32 add_b = cb + color.cb;
        
        // Clamps possible overflown values
        cr = static_cast<QUInt8>((add_r > 255) ? 255 : add_r);
        cg = static_cast<QUInt8>((add_g > 255) ? 255 : add_g);
        cb = static_cast<QUInt8>((add_b > 255) ? 255 : add_b);
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      xorBlend
    ///
    ///////////////////////////////////////////////////////////
    void Color::xorBlend(const Color &color)
    {
        // Retrieves the memory location for the first component
        // while copying the alpha value, as it should remain unmodified
        QUInt32 *rgb = (QUInt32 *) (&cr);
        QUInt32 *bld = (QUInt32 *) (&color.cr);
        QUInt8 alpha = ca;
        
        // Modifies the RGB components bit-by-bit using the XOR blending method.
        std::bitset<32> rgbBits(*rgb);
        std::bitset<32> bldBits(*bld);
        rgbBits ^= bldBits;
        
        // Copies the bits back to this color. The size didn't change
        // during the operation, so static_cast can be used safely.
        *rgb = static_cast<QUInt32>(rgbBits.to_ulong());
        ca = alpha;
    }
    
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \fn      toGL -> const
    ///
    ///////////////////////////////////////////////////////////
    GLColor Color::toGL() const
    {
        QFloat gl_r = cr / 255.0f;
        QFloat gl_g = cg / 255.0f;
        QFloat gl_b = cb / 255.0f;
        QFloat gl_a = ca / 255.0f;
        
        return GLColor(gl_r, gl_g, gl_b, gl_a);
    }
}