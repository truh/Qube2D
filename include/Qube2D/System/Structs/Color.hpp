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


#ifndef __Q2D_COLOR_HPP__
#define __Q2D_COLOR_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Forward declaration for 'Qube2D::Color::toGL'
    //
    ///////////////////////////////////////////////////////////
    class GLColor;


    ///////////////////////////////////////////////////////////
    /// \file    Color.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \class   Color
    /// \brief   Defines a color with R, G, B and A components.
    ///
    /// Each of these components range from 0 to 255 with 255
    /// being a full color component. As for the alpha value,
    /// 255 means that the color is fully visible.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Color
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes all color components to zero.
        ///
        /// Initializes the alpha component to 255 -> black.
        ///
        ///////////////////////////////////////////////////////////
        Color();

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Specifies an 8-bit color with RGB components.
        /// \param  rgb Same component for R, G and B
        /// \param  (opt) alpha Transparency value
        ///
        ///////////////////////////////////////////////////////////
        Color(QUInt8 rgb, QUInt8 alpha = 255);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Specifies the R, G and B components.
        /// \param  red Red color component
        /// \param  green Green color component
        /// \param  blue Blue color component
        /// \param  (opt) alpha Transparency value
        ///
        ///////////////////////////////////////////////////////////
        Color(QUInt8 red, QUInt8 green, QUInt8 blue, QUInt8 alpha = 255);

        ///////////////////////////////////////////////////////////
        /// \fn     Copy constructor
        /// \brief  Copies all the four components to this color.
        /// \param  color Color with RGBA components
        ///
        ///////////////////////////////////////////////////////////
        Color(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     Assignment operator
        /// \brief  Copies all the four components to this color.
        /// \param  color Color with RGBA components
        ///
        ///////////////////////////////////////////////////////////
        Color &operator =(const Color &color);


        ///////////////////////////////////////////////////////////
        /// \fn      r -> const
        /// \brief   Retrieves the red color component.
        /// \returns the red intensity ranging between 0 and 255.
        ///
        ///////////////////////////////////////////////////////////
        QUInt8 r() const;

        ///////////////////////////////////////////////////////////
        /// \fn      g -> const
        /// \brief   Retrieves the green color component.
        /// \returns the green intensity ranging between 0 and 255.
        ///
        ///////////////////////////////////////////////////////////
        QUInt8 g() const;

        ///////////////////////////////////////////////////////////
        /// \fn      b -> const
        /// \brief   Retrieves the blue color component.
        /// \returns the blue intensity ranging between 0 and 255.
        ///
        ///////////////////////////////////////////////////////////
        QUInt8 b() const;

        ///////////////////////////////////////////////////////////
        /// \fn      a -> const
        /// \brief   Retrieves the alpha component.
        /// \returns the transparency of the entire color.
        ///
        ///////////////////////////////////////////////////////////
        QUInt8 a() const;


        ///////////////////////////////////////////////////////////
        /// \fn     setR
        /// \brief  Modifies the red color component.
        /// \param  red Red intensity between 0 and 255
        ///
        ///////////////////////////////////////////////////////////
        void setR(QUInt8 red);

        ///////////////////////////////////////////////////////////
        /// \fn     setG
        /// \brief  Modifies the green color component.
        /// \param  green Green intensity between 0 and 255
        ///
        ///////////////////////////////////////////////////////////
        void setG(QUInt8 green);

        ///////////////////////////////////////////////////////////
        /// \fn     setB
        /// \brief  Modifies the blue color component.
        /// \param  blue The blue intensity between 0 and 255
        ///
        ///////////////////////////////////////////////////////////
        void setB(QUInt8 blue);

        ///////////////////////////////////////////////////////////
        /// \fn     setA
        /// \brief  Modifies the alpha component.
        /// \param  alpha The transparency between 0 and 255
        ///
        ///////////////////////////////////////////////////////////
        void setA(QUInt8 alpha);


        ///////////////////////////////////////////////////////////
        /// \fn     invert
        /// \brief  Inverts all color components, but not alpha.
        ///
        ///////////////////////////////////////////////////////////
        void invert();

        ///////////////////////////////////////////////////////////
        /// \fn     brighten
        /// \brief  Brightens all color components by FACTOR.
        ///
        /// A value under 1 will darken all color components.
        ///
        /// \param  factor Brightening factor between 0 and 2.
        ///
        ///////////////////////////////////////////////////////////
        void brighten(QFloat factor);

        ///////////////////////////////////////////////////////////
        /// \fn     multiplyBlend
        /// \brief  Multiplies two corresponding color components.
        /// \param  color Color to blend with this color
        ///
        ///////////////////////////////////////////////////////////
        void multiplyBlend(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     additiveBlend
        /// \brief  Adds two corresponding color components.
        /// \param  color Color to blend with this color
        ///
        ///////////////////////////////////////////////////////////
        void additiveBlend(const Color &color);

        ///////////////////////////////////////////////////////////
        /// \fn     xorBlend
        /// \brief  XORs two corresponding color components.
        /// \param  color Color to blend with this color
        ///
        ///////////////////////////////////////////////////////////
        void xorBlend(const Color &color);


        ///////////////////////////////////////////////////////////
        /// \fn      toGL -> const
        /// \brief   Converts this color to an OpenGL color.
        ///
        /// Unlike normal colors, OpenGL colors range from 0 to 1
        /// and their components are represented as float number.
        ///
        ///////////////////////////////////////////////////////////
        GLColor toGL() const;


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt8 cr;       ///< Red color component
        QUInt8 cg;       ///< Green color component
        QUInt8 cb;       ///< Blue color component
        QUInt8 ca;       ///< Transparency value

    };
}


#endif  // __Q2D_COLOR_HPP__
