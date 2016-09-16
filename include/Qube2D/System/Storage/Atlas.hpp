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


///////////////////////////////////////////////////////////////////////////////////
// !!! NOTICE !!!
// The original algorithm, "MaxRects-BSSF-BFF" was developed by Jukka Jylänki.
// This is just an optimized version of it, using templates and own changes.
//
///////////////////////////////////////////////////////////////////////////////////


#ifndef __Q2D_ATLAS_HPP__
#define __Q2D_ATLAS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Structs/Rect.hpp>
#include <algorithm>
#include <utility>
#include <iostream>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Atlas.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 15th, 2016
    /// \class   Atlas
    /// \brief   Packs small textures into a bigger one.
    ///
    ///////////////////////////////////////////////////////////
    template <QUInt32 _s>
    class Q2D_API Atlas
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn       Default constructor
        /// \brief    Creates a new free rectangle of size _s*_s.
        ///
        ///////////////////////////////////////////////////////////
        Atlas()
        {
            m_Free.push_back(RectI(0, 0, _s, _s));
        }

        ///////////////////////////////////////////////////////////
        /// \fn       find
        /// \brief    Finds an unused rectangle in the texture.
        /// \param    width Width of the rectangle to find
        /// \param    height Height of the rectangle to find
        /// \returns  the unused rectangle or an invalid, if failed.
        ///
        ///////////////////////////////////////////////////////////
        inline RectI find(QInt32 width, QInt32 height)
        {
            RectI fit = score(width, height);
            if (!fit.isValid())
                return fit;

            // Places the rectangle in a free one
            place(fit);
            return fit;
        }


    private:

        ///////////////////////////////////////////////////////////
        /// \fn       contains
        /// \brief    Determines whether a rect contains another.
        /// \param    r1 First rectangle
        /// \param    r2 Second rectangle
        /// \returns  TRUE if 'r1' contains 'r2'.
        ///
        ///////////////////////////////////////////////////////////
        inline bool contains(const RectI &r1, const RectI &r2)
        {
            int x1 = r1.x(), x2 = r2.x();
            int y1 = r1.y(), y2 = r2.y();
            int w1 = r1.width(), w2 = r2.width();
            int h1 = r1.height(), h2 = r2.height();

            // Bounds check
            if (x2 < x1 || y2 < y1)
                return false;

            int ox = w1 + x1;
            int ow = w2 + x2;
            int oy = h1 + y1;
            int oh = h2 + y2;

            // Overflow check
            if (ow <= x2)
                if (ox >= x1 || ow > ox)
                    return false;
            else
                if (ox >= x1 && ow > ox)
                    return false;
            if (oh <= y2)
                if (oy >= y1 || oh > oy)
                    return false;
            else
                if (oy >= y1 && oh > oy)
                    return false;

            return true;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     place
        /// \brief  Stores a rectangle in the atlas.
        /// \param  node Rectangle to place
        ///
        ///////////////////////////////////////////////////////////
        inline void place(const RectI &node)
        {
            // Inserts a rectangle in the free region
            QUInt32 rectsToProcess = m_Free.size();

            for (QUInt32 i = 0; i < rectsToProcess;)
            {
                if (split(m_Free.at(i), node))
                {
                    m_Free.erase(m_Free.begin() + i);
                    --rectsToProcess;
                }
                else
                {
                    ++i;
                }
            }

            // Reorder the list
            sort();
            m_Used.push_back(node);
        }

        ///////////////////////////////////////////////////////////
        /// \fn       score
        /// \brief    Gathers the best region for 'width' and 'height'.
        /// \param    width Width of the new region
        /// \param    height Height of the new region
        /// \returns  the best region or invalid on failure.
        ///
        ///////////////////////////////////////////////////////////
        inline RectI score(QInt32 width, QInt32 height)
        {
            RectI best(0, 0, width, height);
            QInt32 bssf = std::numeric_limits<int>::max();
            QInt32 blsf = std::numeric_limits<int>::max();
            QBool result = false;


            // Gathers free-space via "best short side fit"
            for (auto it = m_Free.begin(); it != m_Free.end(); ++it)
            {
                if (it->width() >= width && it->height() >= height)
                {
                    int hleft = abs(it->width() - width);
                    int vleft = abs(it->height() - height);
                    int ss = std::min(hleft, vleft);
                    int ls = std::max(hleft, vleft);

                    // Does rectangle fit the space?
                    if (ss < bssf || (ss == bssf && ls < blsf))
                    {
                        best.setX(it->x());
                        best.setY(it->y());
                        bssf = ss;
                        blsf = ls;
                        result = true;
                    }
                }
            }

            // Returns the rect or an invalid one
            if (result)
                return best;
            else
                return RectI(0, 0, 0, 0);
        }

        ///////////////////////////////////////////////////////////
        /// \fn       split
        /// \brief    Attempts to split the big free rectangle.
        /// \param    free A free region in the atlas
        /// \param    used The newly used region in the atlas
        /// \returns  TRUE if 'free' could be split by 'used'.
        ///
        ///////////////////////////////////////////////////////////
        inline bool split(const RectI &free, const RectI &used)
        {
            // Do rectangles even intersect?
            if (used.x() >= free.x() + free.width()  || used.x() + used.width()  <= free.x() ||
                used.y() >= free.y() + free.height() || used.y() + used.height() <= free.y())
                return false;

            // Is used inside free horizontally?
            if (used.x() < free.x() + free.width() && used.x() + used.width() > free.x())
            {
                if (used.y() > free.y() && used.y() < free.y() + free.height())
                {
                    RectI node = free;
                    node.setHeight(used.y() - free.y());
                    m_Free.push_back(node);
                }
                if (used.y() + used.height() < free.y() + free.height())
                {
                    RectI node = free;
                    node.setY(used.y() + used.height());
                    node.setHeight((free.y() + free.height()) - node.y());
                    m_Free.push_back(node);
                }
            }

            // Is used inside free vertically?
            if (used.y() < free.y() + free.height() && used.y() + used.height() > free.y())
            {
                if (used.x() > free.x() && used.x() < free.x() + free.width())
                {
                    RectI node = free;
                    node.setWidth(used.x() - free.x());
                    m_Free.push_back(node);
                }
                if (used.x() + used.width() < free.x() + free.width())
                {
                    RectI node = free;
                    node.setX(used.x() + used.width());
                    node.setWidth((free.x() + free.width()) - node.x());
                    m_Free.push_back(node);
                }
            }

            // The free rectangle was successfully split up to two ones
            return true;
        }

        ///////////////////////////////////////////////////////////
        /// \fn     sort
        /// \brief  Reorders the free rectangles to improve speed.
        ///
        ///////////////////////////////////////////////////////////
        inline void sort()
        {
            // Removes redundant rectangles
            for (QUInt32 i = 0; i < m_Free.size(); i++)
            {
                for (QUInt32 j = i+1; j < m_Free.size(); j++)
                {
                    if (contains(m_Free.at(i), m_Free.at(j)))
                    {
                        m_Free.erase(m_Free.begin() + i);
                        --i;
                        break;
                    }
                    if (contains(m_Free.at(j), m_Free.at(i)))
                    {
                        m_Free.erase(m_Free.begin() + j);
                        --j;
                    }
                }
            }
        }


        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        std::vector<RectI> m_Used;      ///< Used rectangles
        std::vector<RectI> m_Free;      ///< Free rectangles

    };
}


#endif  // __Q2D_ATLAS_HPP__
