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
#include <Qube2D/Audio/IAudio.hpp>
#include <Qube2D/Debug/ALCheck.hpp>
#include <al/al.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    IAudio::IAudio()
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      Destructor -> virtual
    ///
    ///////////////////////////////////////////////////////////
    IAudio::~IAudio()
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    bool IAudio::create()
    {
        alCheck(alGenSources(1, &m_Source));
        return (m_Source != 0);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void IAudio::destroy()
    {
        alCheck(alDeleteSources(1, &m_Source));
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      setPosition
    ///
    ///////////////////////////////////////////////////////////
    void IAudio::setPosition(QFloat x, QFloat y, QFloat z)
    {
        alCheck(alSource3f(m_Source, AL_POSITION, x, y, z));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      setTime
    ///
    ///////////////////////////////////////////////////////////
    void IAudio::setTime(QFloat seconds)
    {
        alCheck(alSourcef(m_Source, AL_SEC_OFFSET, seconds));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      setVolume
    ///
    ///////////////////////////////////////////////////////////
    void IAudio::setVolume(QFloat volume)
    {
        alCheck(alSourcef(m_Source, AL_GAIN, volume));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      setSpeed
    ///
    ///////////////////////////////////////////////////////////
    void IAudio::setSpeed(QFloat speed)
    {
        alCheck(alSourcef(m_Source, AL_SPEED_OF_SOUND, speed));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 20th, 2016
    /// \fn      setPitch
    ///
    ///////////////////////////////////////////////////////////
    void IAudio::setPitch(QFloat pitch)
    {
        alCheck(alSourcef(m_Source, AL_PITCH, pitch));
    }
}
