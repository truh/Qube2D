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


#ifndef __Q2D_GLCOLOR_HPP__
#define __Q2D_GLCOLOR_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Forward declaration for 'Qube2D::GLColor::toRGBA'
    //
    ///////////////////////////////////////////////////////////
    class Color;


    ///////////////////////////////////////////////////////////
    /// \file    GLColor.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \class   GLColor
    /// \brief   Defines an OpenGL color with RGBA components.
    ///
    /// Each of these components range from 0.0 to 1.0 with 1.0
    /// being a full color component. As for the alpha value,
    /// 1.0 means that the color is fully visible.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API GLColor
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes all color components to zero.
        ///
        /// Initializes the alpha component to 1.0 -> black.
        ///
        ///////////////////////////////////////////////////////////
        GLColor();

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Specifies an 8-bit color with RGB components.
        /// \param  rgb Same component for R, G and B
        /// \param  (opt) alpha Transparency value
        ///
        ///////////////////////////////////////////////////////////
        GLColor(QFloat rgb, QFloat alpha = 1.0f);

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Specifies the R, G and B components.
        /// \param  red Red color component
        /// \param  green Green color component
        /// \param  blue Blue color component
        /// \param  (opt) alpha Transparency value
        ///
        ///////////////////////////////////////////////////////////
        GLColor(QFloat red, QFloat green, QFloat blue, QFloat alpha = 1.0f);

        ///////////////////////////////////////////////////////////
        /// \fn     Copy constructor
        /// \brief  Copies all the four components to this color.
        /// \param  color Color with RGBA components
        ///
        ///////////////////////////////////////////////////////////
        GLColor(const GLColor &GLColor);

        ///////////////////////////////////////////////////////////
        /// \fn     Assignment operator
        /// \brief  Copies all the four components to this color.
        /// \param  color Color with RGBA components
        ///
        ///////////////////////////////////////////////////////////
        GLColor &operator =(const GLColor &GLColor);


        ///////////////////////////////////////////////////////////
        /// \fn      r -> const
        /// \brief   Retrieves the red color component.
        /// \returns the red intensity ranging between 0 and 1.
        ///
        ///////////////////////////////////////////////////////////
        QFloat r() const;

        ///////////////////////////////////////////////////////////
        /// \fn      g -> const
        /// \brief   Retrieves the green color component.
        /// \returns the green intensity ranging between 0 and 1.
        ///
        ///////////////////////////////////////////////////////////
        QFloat g() const;

        ///////////////////////////////////////////////////////////
        /// \fn      b -> const
        /// \brief   Retrieves the blue color component.
        /// \returns the blue intensity ranging between 0 and 1.
        ///
        ///////////////////////////////////////////////////////////
        QFloat b() const;

        ///////////////////////////////////////////////////////////
        /// \fn      a -> const
        /// \brief   Retrieves the alpha component.
        /// \returns the transparency of the entire color.
        ///
        ///////////////////////////////////////////////////////////
        QFloat a() const;


        ///////////////////////////////////////////////////////////
        /// \fn     setR
        /// \brief  Modifies the red color component.
        /// \param  red Red intensity between 0 and 1
        ///
        ///////////////////////////////////////////////////////////
        void setR(QFloat red);

        ///////////////////////////////////////////////////////////
        /// \fn     setG
        /// \brief  Modifies the green color component.
        /// \param  green Green intensity between 0 and 1
        ///
        ///////////////////////////////////////////////////////////
        void setG(QFloat green);

        ///////////////////////////////////////////////////////////
        /// \fn     setB
        /// \brief  Modifies the blue color component.
        /// \param  blue The blue intensity between 0 and 1
        ///
        ///////////////////////////////////////////////////////////
        void setB(QFloat blue);

        ///////////////////////////////////////////////////////////
        /// \fn     setA
        /// \brief  Modifies the alpha component.
        /// \param  alpha The transparency between 0 and 1
        ///
        ///////////////////////////////////////////////////////////
        void setA(QFloat alpha);


        ///////////////////////////////////////////////////////////
        /// \fn      toRGBA -> const
        /// \brief   Converts this OpenGL color to a RGBA GLColor.
        ///
        /// This function needs to be called if the user decides
        /// to use the blending methods of Qube2D::Color.
        ///
        ///////////////////////////////////////////////////////////
        Color toRGBA() const;


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QFloat cr;       ///< Red color component
        QFloat cg;       ///< Green color component
        QFloat cb;       ///< Blue color component
        QFloat ca;       ///< Transparency value

    };
}


#endif  // __Q2D_GLCOLOR_HPP__
