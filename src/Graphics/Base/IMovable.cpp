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
#include <Qube2D/Graphics/Base/IMovable.hpp>
#include <Qube2D/Window/Window.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Variables
    //
    ///////////////////////////////////////////////////////////
    glm::mat4 IMovable::m_ProjMatrix;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    IMovable::IMovable()
        : m_PosX(0),
          m_PosY(0),
          m_ElapsedTime(0.0),
          m_IsMovingHoriz(false),
          m_IsMovingVert(false),
          m_Direction(0),
          m_SpeedHoriz(1.f),
          m_SpeedVert(1.f),
          m_TargetX(0.f),
          m_TargetY(0.f)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      x -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat IMovable::x() const
    {
        return m_PosX;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      y -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat IMovable::y() const
    {
        return m_PosY;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      isMoving -> const
    ///
    ///////////////////////////////////////////////////////////
    QBool IMovable::isMoving() const
    {
        return isMovingHorizontally() || isMovingVertically();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      isMovingHorizontally -> const
    ///
    ///////////////////////////////////////////////////////////
    QBool IMovable::isMovingHorizontally() const
    {
        return m_IsMovingHoriz;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      isMovingVertically -> const
    ///
    ///////////////////////////////////////////////////////////
    QBool IMovable::isMovingVertically() const
    {
        return m_IsMovingVert;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      setPosition
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::setPosition(QFloat x, QFloat y)
    {
        m_PosX = x;
        m_PosY = y;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      setHorizontalMovingSpeed
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::setHorizontalMovingSpeed(QFloat speed)
    {
        m_SpeedHoriz = speed;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      setVerticalMovingSpeed
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::setVerticalMovingSpeed(QFloat speed)
    {
        m_SpeedVert = speed;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      setMovingDirection
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::setMovingDirection(MoveDirection md)
    {
        if (md == MoveDirection::Up)
            m_Direction = IMOVABLE_DIR_UP;
        else if (md == MoveDirection::Down)
            m_Direction = IMOVABLE_DIR_DOWN;
        else if (md == MoveDirection::Right)
            m_Direction = IMOVABLE_DIR_RIGHT;
        else if (md == MoveDirection::Left)
            m_Direction = IMOVABLE_DIR_LEFT;
        else if (md == MoveDirection::UpAndRight)
            m_Direction = IMOVABLE_DIR_UP | IMOVABLE_DIR_RIGHT;
        else if (md == MoveDirection::UpAndLeft)
            m_Direction = IMOVABLE_DIR_UP | IMOVABLE_DIR_LEFT;
        else if (md == MoveDirection::DownAndRight)
            m_Direction = IMOVABLE_DIR_DOWN | IMOVABLE_DIR_RIGHT;
        else
            m_Direction = IMOVABLE_DIR_DOWN | IMOVABLE_DIR_LEFT;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      startMovement
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::startMovement(QFloat offsetX, QFloat offsetY)
    {
        // Resets variables that are used in updateMovement
        m_IsMovingHoriz = m_IsMovingVert = false;
        m_ElapsedTime = 0.0;


        // Determines the target location
        if ((m_Direction & IMOVABLE_DIR_UP) != 0)
        {
            m_IsMovingHoriz = true;
            m_TargetY = m_PosY - offsetY;
        }
        else if ((m_Direction & IMOVABLE_DIR_DOWN) != 0)
        {
            m_IsMovingHoriz = true;
            m_TargetY = m_PosY + offsetY;
        }
        if ((m_Direction & IMOVABLE_DIR_LEFT) != 0)
        {
            m_IsMovingVert = true;
            m_TargetX = m_PosX - offsetX;
        }
        else if ((m_Direction & IMOVABLE_DIR_RIGHT) != 0)
        {
            m_IsMovingVert = true;
            m_TargetX = m_PosX + offsetX;
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      stopMovement
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::stopMovement()
    {
        // Stops the movement manually (suppress update)
        m_IsMovingHoriz = m_IsMovingVert = false;
        m_ElapsedTime = 0.0;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      updateMovement
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::updateMovement(double deltaTime)
    {
        if (!m_IsMovingHoriz && !m_IsMovingVert)
            return;


        m_ElapsedTime += deltaTime;

        if (m_ElapsedTime >= IMOVABLE_UPDATE_INTERVAL)
        {
            m_ElapsedTime = 0.0;

            // Modifies the pos depending on the direction
            if ((m_Direction & IMOVABLE_DIR_UP) != 0)
            {
                m_PosY -= m_SpeedVert;

                // Stops vertical movement if condition is met
                if (m_PosY <= m_TargetY)
                {
                    m_IsMovingVert = false;
                    m_PosY = m_TargetY;
                }
            }
            else if ((m_Direction & IMOVABLE_DIR_DOWN) != 0)
            {
                m_PosY += m_SpeedVert;

                // Stops vertical movement if condition is met
                if (m_PosY >= m_TargetY)
                {
                    m_IsMovingVert = false;
                    m_PosY = m_TargetY;
                }
            }
            if ((m_Direction & IMOVABLE_DIR_LEFT) != 0)
            {
                m_PosX -= m_SpeedHoriz;

                // Stops horizontal movement if condition is mit
                if (m_PosX <= m_TargetX)
                {
                    m_IsMovingHoriz = false;
                    m_PosX = m_TargetX;
                }
            }
            else if ((m_Direction & IMOVABLE_DIR_RIGHT) != 0)
            {
                m_PosX += m_SpeedHoriz;

                // Stops horizontal movement if condition is mit
                if (m_PosX >= m_TargetX)
                {
                    m_IsMovingHoriz = false;
                    m_PosX = m_TargetX;
                }
            }
        }
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \fn      initializeMatrix
    ///
    ///////////////////////////////////////////////////////////
    void IMovable::initializeMatrix()
    {
        RectF *vp = Window::viewport();
        m_ProjMatrix = glm::ortho(0.f, vp->width(), vp->height(), 0.f);
    }
}
