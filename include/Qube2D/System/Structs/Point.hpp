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


#ifndef __Q2D_POINT_HPP__
#define __Q2D_POINT_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Point.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \class   Point
    /// \brief   Defines a coordinate pair of any type.
    ///
    /// Can be used to define coordinates or a value pair.
    ///
    ///////////////////////////////////////////////////////////
    template <typename T> class Q2D_API Point
    {
    
    public:
    
        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes all values to default.
        ///
        ///////////////////////////////////////////////////////////
        Point()
        {
            x = T();
            y = T();
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Initializes this class with the given values.
        /// \param  x X-position or first pair value
        /// \param  y Y-position or second pair value
        ///
        ///////////////////////////////////////////////////////////
        Point(T _x, T _y)
        {
            x = _x;
            y = _y;
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Copies the values of the given object.
        /// \param  val Value to copy to this object
        ///
        ///////////////////////////////////////////////////////////
        Point(const Point &val)
        {
            x = val.x;
            y = val.y;
        }
        
        
        ///////////////////////////////////////////////////////////
        /// \fn      x -> const
        /// \brief   Retrieves the value of the first pair entry.
        /// \returns a constant copy of the first pair entry.
        ///
        ///////////////////////////////////////////////////////////
        const T x() const
        {
            return x;
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn      y -> const
        /// \brief   Retrieves the value of the second pair entry.
        /// \returns a constant copy of the second pair entry.
        ///
        ///////////////////////////////////////////////////////////
        const T y() const
        {
            return y;
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     setX
        /// \brief  Modifies the first pair entry.
        /// \param  _x Value to copy to the first pair entry
        ///
        ///////////////////////////////////////////////////////////
        void setX(const T &_x)
        {
            x = _x;
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     setY
        /// \brief  Modifies the second pair entry.
        /// \param  _y Value to copy to the second pair entry
        ///
        ///////////////////////////////////////////////////////////
        void setY(const T &_y)
        {
            y = _y;
        }
        
        
        ///////////////////////////////////////////////////////////
        /// \fn     rx
        /// \brief  Returns a reference to the first pair entry.
        ///
        /// The reference returned in this function is non-constant
        /// and can therefore be modified without calling the
        /// respective 'Qube2D::Point::setX' function.
        ///
        /// \returns a modifiable reference to the first entry.
        ///
        ///////////////////////////////////////////////////////////
        T &rx()
        {
            return x;
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     ry
        /// \brief  Returns a reference to the second pair entry.
        ///
        /// The reference returned in this function is non-constant
        /// and can therefore be modified without calling the
        /// respective 'Qube2D::Point::setY' function.
        ///
        /// \returns a modifiable reference to the second entry.
        ///
        ///////////////////////////////////////////////////////////
        T &ry()
        {
            return y;
        }
        
        
    private:
    
        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        T x;    ///< First value pair entry
        T y;    ///< Second value pair entry
    
    };
    
    
    ///////////////////////////////////////////////////////////
    /// \file    Point.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     Point<int>, Point<float>, Point<unsigned>
    ///
    /// Instantiates the three most common point types which
    /// are being used by the Qube2D library.
    ///
    ///////////////////////////////////////////////////////////
    Q2D_TPL Point<int>;
    Q2D_TPL Point<float>;
    Q2D_TPL Point<unsigned>;
    
    
    ///////////////////////////////////////////////////////////
    /// \file    Point.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     PointI, PointF, PointU
    ///
    /// Simplifies the template type declaration.
    ///
    ///////////////////////////////////////////////////////////
    typedef Point<int>              PointI;
    typedef Point<float>            PointF;
    typedef Point<unsigned>         PointU;
    typedef Point                   Pair;
}


#endif  // __Q2D_POINT_HPP__