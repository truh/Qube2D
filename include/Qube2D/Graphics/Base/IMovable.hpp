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


#ifndef __Q2D_IMOVABLE_HPP__
#define __Q2D_IMOVABLE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Graphics/Base/BaseEnums.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    IMovable.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \class   IMovable
    /// \brief   Allows moving an object.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API IMovable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::IMovable.
        ///
        ///////////////////////////////////////////////////////////
        IMovable();


        ///////////////////////////////////////////////////////////
        /// \fn       x -> const
        /// \brief    Retrieves the X-coordinate of this object.
        /// \returns  the X-coordinate, in pixels.
        ///
        ///////////////////////////////////////////////////////////
        QFloat x() const;

        ///////////////////////////////////////////////////////////
        /// \fn       y -> const
        /// \brief    Retrieves the Y-coordinate of this object.
        /// \returns  the Y-coordinate, in pixels.
        ///
        ///////////////////////////////////////////////////////////
        QFloat y() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isMoving -> const
        /// \brief    Determines whether the object is moving.
        /// \returns  TRUE if the object is moving.
        ///
        ///////////////////////////////////////////////////////////
        QBool isMoving() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isMovingHorizontally -> const
        /// \brief    Determines whether the object is moving horiz.
        /// \returns  TRUE if the object is still moving horizontally.
        ///
        ///////////////////////////////////////////////////////////
        QBool isMovingHorizontally() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isMovingVertically -> const
        /// \brief    Determines whether the object is moving vert.
        /// \returns  TRUE if the object is still moving vertically.
        ///
        ///////////////////////////////////////////////////////////
        QBool isMovingVertically() const;


        ///////////////////////////////////////////////////////////
        /// \fn     setPosition
        /// \brief  Specifies the position of the object.
        /// \param  x New X-position of the object, in pixels
        /// \param  y New Y-position of the object, in pixels
        ///
        ///////////////////////////////////////////////////////////
        void setPosition(QFloat x, QFloat y);

        ///////////////////////////////////////////////////////////
        /// \fn     setHorizontalMovingSpeed
        /// \brief  Specifies the horizontal moving speed.
        /// \param  speed The moving speed, in pixels
        /// \note   This can also be set to a decimal value.
        ///
        ///////////////////////////////////////////////////////////
        void setHorizontalMovingSpeed(QFloat speed);

        ///////////////////////////////////////////////////////////
        /// \fn     setVerticalMovingSpeed
        /// \brief  Specifies the vertical moving speed.
        /// \param  speed The moving speed, in pixels
        /// \note   This can also be set to a decimal value.
        ///
        ///////////////////////////////////////////////////////////
        void setVerticalMovingSpeed(QFloat speed);

        ///////////////////////////////////////////////////////////
        /// \fn     setMovingDirection
        /// \brief  Specifies the moving direction.
        /// \param  md The direction(s) to move the object in
        ///
        ///////////////////////////////////////////////////////////
        void setMovingDirection(MoveDirection md);


        ///////////////////////////////////////////////////////////
        /// \fn     startMovement
        /// \brief  Starts moving the object.
        /// \param  offsetX Amount of pixels to move horizontally
        /// \param  offsetY Amount of pixels to move vertically
        ///
        ///////////////////////////////////////////////////////////
        void startMovement(QFloat offsetX, QFloat offsetY);

        ///////////////////////////////////////////////////////////
        /// \fn     stopMovement
        /// \brief  Stops moving the object manually.
        ///
        ///////////////////////////////////////////////////////////
        void stopMovement();


    #ifdef __Q2D_LIBRARY__

        ///////////////////////////////////////////////////////////
        /// \fn     initializeMatrix
        /// \brief  Initializes the projection matrix.
        /// \note   Must be called everytime the window size changes.
        ///
        ///////////////////////////////////////////////////////////
        static void initializeMatrix();

    #endif


    protected:

        ///////////////////////////////////////////////////////////
        /// \fn     updateMovement
        /// \brief  Updates the object's position.
        /// \param  deltaTime Time between last and current update
        ///
        ///////////////////////////////////////////////////////////
        void updateMovement(double deltaTime);

        ///////////////////////////////////////////////////////////
        // Static class members
        //
        ///////////////////////////////////////////////////////////
        static glm::mat4 m_ProjMatrix;       ///< Projection matrix


        ///////////////////////////////////////////////////////////
        // Protected class members
        //
        ///////////////////////////////////////////////////////////
        QFloat m_PosX;              ///< Current X-position
        QFloat m_PosY;              ///< Current Y-position


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QDouble m_ElapsedTime;          ///< Delta time counter
        QBool m_IsMovingHoriz;          ///< Moving horizontally?
        QBool m_IsMovingVert;           ///< Moving vertically?
        QUInt32 m_Direction;            ///< Direction flags
        QFloat m_SpeedHoriz;            ///< Horizontal speed
        QFloat m_SpeedVert;             ///< Vertical speed
        QFloat m_TargetX;               ///< X target position
        QFloat m_TargetY;               ///< Y target position

    };


    #define IMOVABLE_UPDATE_INTERVAL 0.010
    #define IMOVABLE_DIR_UP     1
    #define IMOVABLE_DIR_DOWN   2
    #define IMOVABLE_DIR_RIGHT  4
    #define IMOVABLE_DIR_LEFT   8
}


#endif  // __Q2D_IMOVABLE_HPP__
