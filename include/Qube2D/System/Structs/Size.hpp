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


#ifndef __Q2D_SIZE_HPP__
#define __Q2D_SIZE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Size.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \class   Size
    /// \brief   Defines the size of an object.
    ///
    /// Contains extra checks to determine whether the size
    /// is valid. If one dimension is zero, then it is invalid.
    ///
    ///////////////////////////////////////////////////////////
    template <typename T> class Q2D_API Size
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes all values to default.
        ///
        ///////////////////////////////////////////////////////////
        Size()
        {
            /* Triggers a compiler error for non-integral types */
            w = 0;
            h = 0;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Initializes this class with the given values.
        /// \param  w Initial width of the object
        /// \param  h Initial height of the object
        ///
        ///////////////////////////////////////////////////////////
        Size(T _w, T _h)
        {
            w = _w;
            h = _h;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Copies the values of the given object.
        /// \param  val Value to copy to this object
        ///
        ///////////////////////////////////////////////////////////
        Size(const Size &val)
        {
            w = val.w;
            h = val.h;
        }


        ///////////////////////////////////////////////////////////
        /// \fn      width -> const
        /// \brief   Retrieves the width of the object.
        /// \returns a constant copy of the object width.
        ///
        ///////////////////////////////////////////////////////////
        inline const T width() const
        {
            return w;
        }

        ///////////////////////////////////////////////////////////
        /// \fn      height -> const
        /// \brief   Retrieves the height of the object.
        /// \returns a constant copy of the object height.
        ///
        ///////////////////////////////////////////////////////////
        inline const T height() const
        {
            return h;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     setWidth
        /// \brief  Modifies the width of the object.
        /// \param  _w Value to replace the current width.
        ///
        ///////////////////////////////////////////////////////////
        inline void setWidth(const T &_w)
        {
            w = _w;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     setHeight
        /// \brief  Modifies the height of the object.
        /// \param  _h Value to replace the current height.
        ///
        ///////////////////////////////////////////////////////////
        inline void setHeight(const T &_h)
        {
            h = _h;
        }


        ///////////////////////////////////////////////////////////
        /// \fn     rwidth
        /// \brief  Returns a reference to the width.
        ///
        /// The reference returned in this function is non-constant
        /// and can therefore be modified without calling the
        /// respective 'Qube2D::Size::setWidth' function.
        ///
        /// \returns a modifiable reference to the width.
        ///
        ///////////////////////////////////////////////////////////
        inline T &rwidth()
        {
            return w;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     rheight
        /// \brief  Returns a reference to the height.
        ///
        /// The reference returned in this function is non-constant
        /// and can therefore be modified without calling the
        /// respective 'Qube2D::Size::setY' function.
        ///
        /// \returns a modifiable reference to the height.
        ///
        ///////////////////////////////////////////////////////////
        inline T &rheight()
        {
            return h;
        }


        ///////////////////////////////////////////////////////////
        /// \fn     isValid -> const
        /// \brief  Determines whether this size is valid.
        ///
        /// A size is considered invalid if at least one of it's
        /// dimensions is zero or less.
        ///
        /// \returns true if the size is valid and usable.
        ///
        ///////////////////////////////////////////////////////////
        inline bool isValid() const
        {
            return (w > 0 && h > 0);
        }


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        T w;    ///< Horizontal dimension of the object
        T h;   ///< Vertical dimension of the object

    };


    ///////////////////////////////////////////////////////////
    /// \file    Size.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 23th, 2016
    /// \def     SizeI, SizeF, SizeU
    ///
    /// Simplifies the template type declaration.
    ///
    ///////////////////////////////////////////////////////////
    typedef Size<int>              SizeI;
    typedef Size<float>            SizeF;
    typedef Size<unsigned>         SizeU;
}


#endif  // __Q2D_SIZE_HPP__
