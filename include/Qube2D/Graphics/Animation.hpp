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


#ifndef __Q2D_ANIMATION_HPP__
#define __Q2D_ANIMATION_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Object.hpp>
#include <Qube2D/Graphics/System/Base/ISprite.hpp>
#include <Qube2D/Graphics/System/Structs/Frame.hpp>
#include <vector>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Animation.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 10th, 2016
    /// \class   Animation
    /// \brief   Defines an animated object.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Animation : public ISprite, public Object
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Animation.
        ///
        ///////////////////////////////////////////////////////////
        Animation();


        ///////////////////////////////////////////////////////////
        /// \fn     load
        /// \brief  Loads a Qube2D animation file.
        /// \param  path Absolute or relative path to the file
        ///
        ///////////////////////////////////////////////////////////
        bool load(const char *path);


        ///////////////////////////////////////////////////////////
        /// \fn     startAnimation
        /// \brief  Starts playing the animation of this object.
        ///
        ///////////////////////////////////////////////////////////
        void startAnimation();

        ///////////////////////////////////////////////////////////
        /// \fn     stopAnimation
        /// \brief  Stops playing the animation of this object.
        ///
        ///////////////////////////////////////////////////////////
        void stopAnimation();


        ///////////////////////////////////////////////////////////
        /// \fn     update
        /// \brief  Updates the animation frame.
        /// \param  deltaTime Time between last and current update.
        ///
        ///////////////////////////////////////////////////////////
        void update(double deltaTime);

        ///////////////////////////////////////////////////////////
        /// \fn     render
        /// \brief  Reimplements render for performance reasons.
        /// \note   Does absolutely nothing if in "Halt" mode.
        ///
        ///////////////////////////////////////////////////////////
        void render();


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QDouble m_ElapsedTimeA;        ///< Delta time counter for anim
        QDouble m_UpdateInterval;      ///< Frame duration in ms
        QUInt32 m_CurrentFrame;        ///< Current animation frame
        QUInt32 m_FrameCount;          ///< Maximum animation frames
        QFloat m_FrameWidth;           ///< Width of one frame
        QFloat m_FrameHeight;          ///< Height of one frame
        QFloat m_FrameWidRel;          ///< Width in OpenGL coords
        QFloat m_FrameHeiRel;          ///< Height in OpenGL coords
        QBool m_IsAnimating;           ///< Animation running?
        QBool m_IsHalting;             ///< Currently nothing displayed?
        std::vector<Frame> m_Frames;   ///< Actual frames
        std::vector<PointF> m_FrameUV; ///< Frame UV coordinates
    };


    #define ANIMATION_MAGIC "QUBE2DANIM"
}


#endif  // __Q2D_ANIMATION_HPP__
