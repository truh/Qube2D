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


#ifndef __Q2D_IAUDIO_HPP__
#define __Q2D_IAUDIO_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Audio/System/AudioEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    IAudio.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \class   IAudio
    /// \brief   Provides an interface for playing audio.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API IAudio
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::IAudio.
        ///
        ///////////////////////////////////////////////////////////
        IAudio();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor -> virtual
        /// \brief  Frees resources used by Qube2D::IAudio.
        ///
        ///////////////////////////////////////////////////////////
        virtual ~IAudio();


        ///////////////////////////////////////////////////////////
        /// \fn     create
        /// \brief  Creates the OpenAL source.
        ///
        ///////////////////////////////////////////////////////////
        bool create();

        ///////////////////////////////////////////////////////////
        /// \fn       loadFromFile -> virtual
        /// \brief    Loads an audio track from the given file path.
        /// \param    path Absolute or relative path to audio file
        /// \param    mode Determines whether to stream or not
        /// \returns  TRUE if the file was loaded successfully.
        ///
        /// \note Only OGG and WAV audio tracks are supported a.t.m.
        ///
        ///////////////////////////////////////////////////////////
        virtual bool loadFromFile(const char *path) = 0;

        ///////////////////////////////////////////////////////////
        /// \fn       loadFromMemory -> virtual
        /// \brief    Loads a raw audio track from memory.
        /// \param    data Raw audio data
        ///
        ///////////////////////////////////////////////////////////
        virtual void loadFromMemory(const QUInt8 *data) = 0;

        ///////////////////////////////////////////////////////////
        /// \fn     destroy -> virtual
        /// \brief  Frees all OpenAL resources.
        ///
        ///////////////////////////////////////////////////////////
        virtual void destroy();


        ///////////////////////////////////////////////////////////
        /// \fn     start -> virtual
        /// \brief  Starts playing the audio track.
        ///
        ///////////////////////////////////////////////////////////
        virtual void start() = 0;

        ///////////////////////////////////////////////////////////
        /// \fn     stop -> virtual
        /// \brief  Ends playing the audio track.
        ///
        ///////////////////////////////////////////////////////////
        virtual void stop() = 0;

        ///////////////////////////////////////////////////////////
        /// \fn     pause -> virtual
        /// \brief  Pauses the audio track, if still playing.
        ///
        ///////////////////////////////////////////////////////////
        virtual void pause() = 0;

        ///////////////////////////////////////////////////////////
        /// \fn     resume -> virtual
        /// \brief  Resumes the audio track, if it was playing before.
        ///
        ///////////////////////////////////////////////////////////
        virtual void resume() = 0;


        ///////////////////////////////////////////////////////////
        /// \fn       isPlaying -> const virtual
        /// \brief    Determines whether the audio track is playing.
        /// \returns  TRUE if it is playing.
        ///
        ///////////////////////////////////////////////////////////
        virtual bool isPlaying() const = 0;


        ///////////////////////////////////////////////////////////
        /// \fn     setPosition
        /// \brief  Sets the position of the source in 3D space.
        /// \param  x Position on X-axis
        /// \param  y Position on Y-axis
        /// \param  z Position on Z-axis
        ///
        ///////////////////////////////////////////////////////////
        void setPosition(QFloat x, QFloat y, QFloat z);

        ///////////////////////////////////////////////////////////
        /// \fn     setTime
        /// \brief  Sets the current position, in seconds.
        /// \param  seconds Position on time-line in seconds
        ///
        ///////////////////////////////////////////////////////////
        void setTime(QFloat seconds);

        ///////////////////////////////////////////////////////////
        /// \fn     setVolume
        /// \brief  Sets the volume of the audio track.
        /// \param  volume Volume between 0.0 and 100.0
        ///
        ///////////////////////////////////////////////////////////
        void setVolume(QFloat volume);

        ///////////////////////////////////////////////////////////
        /// \fn     setSpeed
        /// \brief  Sets the speed of the audio track.
        /// \param  speed Speed between 0.0 and 2.0
        ///
        /// \note Also increases pitch!
        ///
        ///////////////////////////////////////////////////////////
        void setSpeed(QFloat speed);

        ///////////////////////////////////////////////////////////
        /// \fn     setPitch
        /// \brief  Sets the pitch of the audio track.
        /// \param  pitch Pitch between 0.0 and 2.0
        ///
        ///////////////////////////////////////////////////////////
        void setPitch(QFloat pitch);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QUInt32 m_Source;               //< Source ID within OpenAL

    };
}


#endif  // __Q2D_IAUDIO_HPP__
