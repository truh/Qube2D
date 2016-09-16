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


#ifndef __Q2D_GLYPH_HPP__
#define __Q2D_GLYPH_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <map>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Glyph.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \struct  Glyph
    /// \brief   Specifies several properties for one glyph.
    ///
    ///////////////////////////////////////////////////////////
    struct Glyph
    {
        QFloat texture_x = 0;   ///< X-position within the GL texture
        QFloat texture_y = 0;   ///< Y-position within the GL texture
        QFloat texture_w = 0;   ///< Width relative to GL texture width
        QFloat texture_h = 0;   ///< Height relative to GL texture height

        QInt32 glyph_w = 0;     ///< Width of the glyph in pixels
        QInt32 glyph_h = 0;     ///< Height of the glyph in pixels
        QInt32 bearing_x = 0;   ///< Horizontal bearing
        QInt32 bearing_y = 0;   ///< Vertical bearing
        QFloat advance = 0;     ///< Distance to next glyph
    };

    ///////////////////////////////////////////////////////////
    /// \file    GlyphAtlas.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 14th, 2016
    /// \struct  GlyphAtlas
    /// \brief   Stores glyphs of various sizes and types.
    ///
    ///////////////////////////////////////////////////////////
    struct GlyphAtlas
    {
        std::map<QUInt32, Glyph> glyphs;    ///< Normal glyphs
        std::map<QUInt32, Glyph> glyphOut;  ///< Outlines glyphs
        std::map<QUInt32, Glyph> glyphBrd;  ///< Border glyphs
    };
}


#endif  // __Q2D_GLYPH_HPP__
