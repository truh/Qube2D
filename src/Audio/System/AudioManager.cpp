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
#include <Qube2D/Audio/System/AudioManager.hpp>
#include <Qube2D/Audio/System/AudioErrors.hpp>
#include <Qube2D/Debug/ALCheck.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <al/alc.h>
#include <algorithm>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Static class member definitions
    //
    ///////////////////////////////////////////////////////////
    ALCdevice  *AudioManager::m_Device  = NULL;
    ALCcontext *AudioManager::m_Context = NULL;
    std::vector<IAudio *> AudioManager::m_Tracks;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      initialize
    ///
    ///////////////////////////////////////////////////////////
    bool AudioManager::initialize()
    {
        // Attempts to open the audio device, create the context
        // and bind the context to the current thread.
        alcCheck(m_Device  = alcOpenDevice(NULL));
        alcCheck(m_Context = alcCreateContext(m_Device, NULL));
        alcCheck(alcMakeContextCurrent(m_Context));


        // Determines whether everything was created successfully
        if (!m_Device)
        {
            Q2DErrorNoArg(Q2D_AUDIOMGR_ERROR_0);
            return false;
        }
        else if (!m_Context)
        {
            Q2DErrorNoArg(Q2D_AUDIOMGR_ERROR_1);
            return false;
        }


        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void AudioManager::destroy()
    {
        // Destroys the OpenAL context
        alcCheck(alcMakeContextCurrent(NULL));
        alcCheck(alcDestroyContext(m_Context));
        alcCheck(alcCloseDevice(m_Device));
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      add
    ///
    ///////////////////////////////////////////////////////////
    void AudioManager::add(IAudio *audio)
    {
        m_Tracks.push_back(audio);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      remove
    ///
    ///////////////////////////////////////////////////////////
    void AudioManager::remove(IAudio *audio)
    {
        auto it = std::find(m_Tracks.begin(), m_Tracks.end(), audio);
        if (it == m_Tracks.end())
            m_Tracks.erase(it);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      pause
    ///
    ///////////////////////////////////////////////////////////
    void AudioManager::pause()
    {
        //for (auto it = m_Tracks.begin(); it != m_Tracks.end(); ++it)
            //it->pause();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      resume
    ///
    ///////////////////////////////////////////////////////////
    void AudioManager::resume()
    {
        //for (auto it = m_Tracks.begin(); it != m_Tracks.end(); ++it)
            //it->resume();
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    October 2nd, 2016
    /// \fn      device
    ///
    ///////////////////////////////////////////////////////////
    ALCdevice *AudioManager::device()
    {
        return m_Device;
    }
}
