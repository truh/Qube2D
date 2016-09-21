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


#ifndef __Q2D_AUDIOMANAGER_HPP__
#define __Q2D_AUDIOMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Audio/System/AudioManager.hpp>
#include <Qube2D/Audio/IAudio.hpp>
#include <vector>


///////////////////////////////////////////////////////////
// Forward declarations
//
///////////////////////////////////////////////////////////
struct ALCdevice;
struct ALCcontext;


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    AudioManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \class   AudioManager
    /// \brief   Manages the OpenAL context and audio tracks.
    ///
    ///////////////////////////////////////////////////////////
    class AudioManager
    {

    // Everything in this class is not accessible outside Qube2D
    #ifdef __Q2D_LIBRARY__

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     initialize
        /// \brief  Initializes an OpenAL context and binds it.
        ///
        ///////////////////////////////////////////////////////////
        static bool initialize();

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Destroys the OpenAL context.
        ///
        ///////////////////////////////////////////////////////////
        static void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn     add
        /// \brief  Adds an audio track to the manager.
        /// \param  audio Valid Qube2D::Audio instance
        ///
        ///////////////////////////////////////////////////////////
        static void add(Audio *audio);

        ///////////////////////////////////////////////////////////
        /// \fn     remove
        /// \brief  Removes an audio track from the manager.
        /// \param  audio Valid Qube2D::Audio instance
        ///
        ///////////////////////////////////////////////////////////
        static void remove(Audio *audio);


        ///////////////////////////////////////////////////////////
        /// \fn     pause
        /// \brief  Pauses every OpenAL source in the manager.
        ///
        ///////////////////////////////////////////////////////////
        static void pause();

        ///////////////////////////////////////////////////////////
        /// \fn     resume
        /// \brief  Resumes every OpenAL source in the manager.
        ///
        ///////////////////////////////////////////////////////////
        static void resume();

    #endif


    private:

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        ALCdevice m_Device;             ///< OpenAL audio device
        ALCcontext m_Context;           ///< OpenAL context
        std::vector<IAudio *> m_Tracks; ///< Holds the audio tracks

    };
}


#endif  // __Q2D_AUDIOMANAGER_HPP__
