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


#ifndef __Q2D_MUSIC_HPP__
#define __Q2D_MUSIC_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Audio/IAudio.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Music.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \class   Music
    /// \brief   Streams a background music.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Music : public IAudio
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Music.
        ///
        ///////////////////////////////////////////////////////////
        Music();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor
        /// \brief  Frees the file handle, if not already.
        ///
        ///////////////////////////////////////////////////////////
        ~Music();


        ///////////////////////////////////////////////////////////
        /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
        /// \date    September 20th, 2016
        /// \fn      loadFromFile
        ///
        ///////////////////////////////////////////////////////////
        bool loadFromFile(const char *path);

        ///////////////////////////////////////////////////////////
        /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
        /// \date    September 20th, 2016
        /// \fn      loadFromMemory
        ///
        ///////////////////////////////////////////////////////////
        void loadFromMemory(const QUInt8 *data);

    };
}


#endif  // __Q2D_MUSIC_HPP__
