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


#ifndef __Q2D_BACKGROUND_HPP__
#define __Q2D_BACKGROUND_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Object.hpp>
#include <Qube2D/Graphics/System/GraphicsEnums.hpp>
#include <Qube2D/Graphics/System/Base/ISprite.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Background.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 8th, 2016
    /// \class   Background
    /// \brief   Defines a scrollable background.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Background : public ISprite, public Object
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Background.
        ///
        ///////////////////////////////////////////////////////////
        Background();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor
        /// \brief  Destructs the Qube2D::Object.
        ///
        ///////////////////////////////////////////////////////////
        ~Background();


        ///////////////////////////////////////////////////////////
        /// \fn     setScrollingSpeed
        /// \brief  Specifies the background scrolling speed.
        /// \param  speedX Amount of pixels to move per update (X)
        /// \param  speedY Amount of pixels to move per update (Y)
        ///
        ///////////////////////////////////////////////////////////
        void setScrollingSpeed(QFloat speedX, QFloat speedY);

        ///////////////////////////////////////////////////////////
        /// \fn     setScrollingDirection
        /// \brief  Specifies the background scrolling direction.
        /// \param  dir Direction to scroll background in
        ///
        ///////////////////////////////////////////////////////////
        void setScrollingDirection(ScrollDirection dir);


        ///////////////////////////////////////////////////////////
        /// \fn     startScrolling
        /// \brief  Begins scrolling the background.
        /// \param  offsetX Amount of pixels to scroll the BG horiz.
        /// \param  offsetY Amount of pixels to scroll the BG vert.
        /// \note   If both parameters are zero, the background
        ///         will instead be moved infinitely.
        ///
        ///////////////////////////////////////////////////////////
        void startScrolling(QFloat offsetX, QFloat offsetY);

        ///////////////////////////////////////////////////////////
        /// \fn     stopScrolling
        /// \brief  Stops scrolling the background.
        /// \note   This should only be necessary in case the
        ///         movement is infinite or the scene switches.
        ///
        ///////////////////////////////////////////////////////////
        void stopScrolling();

        ///////////////////////////////////////////////////////////
        /// \fn     update
        /// \brief  Overrides update to add the scrolling effect.
        /// \param  deltaTime Time between current and last update.
        ///
        ///////////////////////////////////////////////////////////
        void update(double deltaTime);


    private:

        ///////////////////////////////////////////////////////////
        /// \fn     initScrolling
        /// \brief  Prepares the texture etc. for scrolling.
        ///
        ///////////////////////////////////////////////////////////
        void initScrolling();


        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QDouble m_ElapsedTimeSC;        ///< Elapsed time for scrolling
        QFloat m_SpeedScrollingX;       ///< Scrolling speed in X (px)
        QFloat m_SpeedScrollingY;       ///< Scrolling speed in Y (px)
        QUInt32 m_ScrollingDirection;   ///< Scrolling direction
        QBool m_IsScrolling;            ///< Currently scrolling?
        QBool m_IsInfinite;             ///< Is scrolling infinite?
        QFloat m_ScrollTargetX;         ///< Target X-position
        QFloat m_ScrollTargetY;         ///< Target Y-position
        QFloat m_RepeatCountX;          ///< Amount of textures in X-dir
        QFloat m_RepeatCountY;          ///< Amount of textures in Y-dir
        QFloat m_ScrollPosX;            ///< Scroll X-position
        QFloat m_ScrollPosY;            ///< Scroll Y-position

    };


    #define BACKGROUND_UPDATE_INTERVAL 0.010
    #define BACKGROUND_DIR_UP     1
    #define BACKGROUND_DIR_DOWN   2
    #define BACKGROUND_DIR_RIGHT  4
    #define BACKGROUND_DIR_LEFT   8
}


#endif  // __Q2D_BACKGROUND_HPP__
