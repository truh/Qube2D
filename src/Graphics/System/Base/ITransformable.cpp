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
#include <Qube2D/Debug/Debug.hpp>
#include <Qube2D/Graphics/System/Base/ITransformable.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    ITransformable::ITransformable()
        : m_Angle(0.f),
          m_Scale(1.f),
          m_ElapsedTimeR(0.0),
          m_ElapsedTimeS(0.0),
          m_IsRotating(false),
          m_IsScaling(false),
          m_SpeedRotation(2.f),
          m_SpeedScaling(0.1f),
          m_TargetRotation(0.f),
          m_TargetScaling(0.f),
          m_RotateDirection(0)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      angle
    ///
    ///////////////////////////////////////////////////////////
    QFloat ITransformable::angle() const
    {
        return m_Angle;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      scale
    ///
    ///////////////////////////////////////////////////////////
    QFloat ITransformable::scale() const
    {
        return m_Scale;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      isRotating
    ///
    ///////////////////////////////////////////////////////////
    QBool ITransformable::isRotating() const
    {
        return m_IsRotating;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      isScaling
    ///
    ///////////////////////////////////////////////////////////
    QBool ITransformable::isScaling() const
    {
        return m_IsScaling;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      setRotation
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::setRotation(QFloat angle)
    {
        m_Angle = angle;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      setScale
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::setScale(QFloat scale)
    {
        m_Scale = scale;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      setRotationSpeed
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::setRotationSpeed(QFloat speed)
    {
        m_SpeedRotation = speed;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      setScalingSpeed
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::setScalingSpeed(QFloat speed)
    {
        m_SpeedScaling = speed;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      setRotationOrigin
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::setRotationOrigin(QFloat x, QFloat y)
    {
        m_OriginX = x;
        m_OriginY = y;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      startRotation
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::startRotation(QFloat angle, RotateDirection dir)
    {
        if (dir == RotateDirection::Clockwise)
        {
            m_RotateDirection = ITRANSFORMABLE_ROTDIR_CW;
            m_TargetRotation = m_Angle + angle;
        }
        else
        {
            m_RotateDirection = ITRANSFORMABLE_ROTDIR_CCW;
            m_TargetRotation = m_Angle - angle;

            if (m_TargetRotation < 0.f)
                m_TargetRotation = 360 - (m_Angle - angle);
        }

        m_IsRotating = true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      startScaling
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::startScaling(QFloat factor)
    {
        if (m_Scale < factor)
            m_ScaleDirection = ITRANSFORMABLE_SCALEDIR_UP;
        else
            m_ScaleDirection = ITRANSFORMABLE_SCALEDIR_DN;

        m_TargetScaling = factor;
        m_IsScaling = true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      stopRotation
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::stopRotation()
    {
        m_IsRotating = false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      stopScaling
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::stopScaling()
    {
        m_IsScaling = false;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      updateRotation
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::updateRotation(double deltaTime)
    {
        if (!m_IsRotating)
            return;


        m_ElapsedTimeR += deltaTime;

        if (m_ElapsedTimeR > ITRANSFORMABLE_UPDATE_INTERVAL)
        {
            if (m_RotateDirection == ITRANSFORMABLE_ROTDIR_CW)
            {
                m_Angle += m_SpeedRotation;

                if (m_Angle >= m_TargetRotation)
                {
                    m_Angle = m_TargetRotation;
                    m_IsRotating = false;
                }
            }
            else
            {
                m_Angle -= m_SpeedRotation;

                if (m_Angle <= m_TargetRotation)
                {
                    m_Angle = m_TargetRotation;
                    m_IsRotating = false;
                }
            }


            m_ElapsedTimeR = 0.0;
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 7th, 2016
    /// \fn      updateScaling
    ///
    ///////////////////////////////////////////////////////////
    void ITransformable::updateScaling(double deltaTime)
    {
        if (!m_IsScaling)
            return;


        m_ElapsedTimeS += deltaTime;

        if (m_ElapsedTimeS >= ITRANSFORMABLE_UPDATE_INTERVAL)
        {
            if (m_ScaleDirection == ITRANSFORMABLE_SCALEDIR_UP)
            {
                m_Scale += m_SpeedScaling;

                if (m_Scale >= m_TargetScaling)
                {
                    m_Scale = m_TargetScaling;
                    m_IsScaling = false;
                }
            }
            else
            {
                m_Scale -= m_SpeedScaling;

                if (m_Scale <= m_TargetScaling)
                {
                    m_Scale = m_TargetScaling;
                    m_IsScaling = false;
                }
            }


            m_ElapsedTimeS = 0.0;
        }
    }
}
