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


#ifndef __Q2D_RECT_HPP__
#define __Q2D_RECT_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Structs/Size.hpp>
#include <Qube2D/System/Structs/Point.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Rect.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \class   Rect
    /// \brief   Defines a rectangle with location and size.
    ///
    /// Inherits Qube2D::Point and Qube2D::Size and therefore
    /// grants access to all their functions. The function
    /// Qube2D::Size::isValid also validates the rectangle.
    ///
    ///////////////////////////////////////////////////////////
    template <typename T> 
    class Q2D_API Rect : public Point<T>, public Size<T>
    {
        
    public:
        
        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes all values to default.
        ///
        ///////////////////////////////////////////////////////////
        Rect() : Point<T>(0, 0), Size<T>(100, 100)
        {
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Specifies the position and the size.
        /// \param  x The rectangle's X-position
        /// \param  y The rectangle's Y-position
        /// \param  w The rectangle's vertical dimension
        /// \param  h The rectangle's horizontal dimension
        ///
        ///////////////////////////////////////////////////////////
        Rect(T _x, T _y, T _w, T _h)
            : Point<T>(_x, _y),
              Size<T>(_w, _h)
        {
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn     Constructor
        /// \brief  Specifies the position and the size.
        /// \param  pos Position of the rectangle
        /// \param  size Size of the rectangle
        ///
        ///////////////////////////////////////////////////////////
        Rect(const Point<T> &pos, const Size<T> &size)
            : Point<T>(pos),
              Size<T>(size)
        {
        }
        
        
        ///////////////////////////////////////////////////////////
        /// \fn      pos -> const
        /// \brief   Retrieves the position of the rectangle.
        /// \returns a value that contains a (xy) coordinate pair. 
        ///
        ///////////////////////////////////////////////////////////
        Point<T> pos() const
        {
            return Point<T>(this->x(), this->y());
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn      size -> const
        /// \brief   Retrieves the size of the rectangle.
        /// \returns a value that contains a (wh) size pair. 
        ///
        ///////////////////////////////////////////////////////////
        Size<T> size() const
        {
            return Size<T>(this->width(), this->height());
        }
        
        
        ///////////////////////////////////////////////////////////
        /// \fn      setPos
        /// \brief   Specifies the rectangle's position.
        ///
        ///////////////////////////////////////////////////////////
        void setPos(const Point<T> &pos)
        {
            this->setX(pos.x());
            this->setY(pos.y());
        }
        
        ///////////////////////////////////////////////////////////
        /// \fn      setSize
        /// \brief   Specifies the rectangle's size.
        ///
        ///////////////////////////////////////////////////////////
        void setSize(const Size<T> &size)
        {
            this->setWidth(size.width());
            this->setHeight(size.height());
        }
        
    };
    
    
    ///////////////////////////////////////////////////////////
    /// \file    Rect.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 22th, 2016
    /// \def     RectI, RectF, RectU
    ///
    /// Simplifies the template type declaration.
    ///
    ///////////////////////////////////////////////////////////
    typedef Rect<int>               RectI;
    typedef Rect<float>             RectF;
    typedef Rect<unsigned>          RectU;
}


#endif  // __Q2D_RECT_HPP__
