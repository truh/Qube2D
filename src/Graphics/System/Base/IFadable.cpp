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
#include <Qube2D/Graphics/System/Base/IFadable.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    IFadable::IFadable()
        : m_Opacity(0.f),
          m_ElapsedTime(0.0),
          m_Speed(0.1f),
          m_BreakPoint(-1.f),
          m_Mode(0),
          m_InitialMode(0),
          m_IsFading(false)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      opacity -> const
    ///
    ///////////////////////////////////////////////////////////
    QFloat IFadable::opacity() const
    {
        return m_Opacity;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      isFading -> const
    ///
    ///////////////////////////////////////////////////////////
    QBool IFadable::isFading() const
    {
        return m_IsFading;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      setOpacity
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::setOpacity(QFloat opacity)
    {
        m_Opacity = opacity;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      setFadingSpeed
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::setFadingSpeed(QFloat speed)
    {
        m_Speed = speed;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      startFading
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::startFading(FadeMode mode)
    {
        m_Mode = m_InitialMode = static_cast<QUInt32>(mode);
        m_IsFading = true;

        if (mode != FadeMode::In)
            m_Opacity = 1.f;
        else
            m_Opacity = 0.f;

        if (mode == FadeMode::Pulse)
            m_Mode = IFADABLE_FADE_IN;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      setFadeBreakPoint
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::setFadeBreakPoint(QFloat opacity)
    {
        m_BreakPoint = opacity;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      removeFadeBreakPoint
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::removeFadeBreakPoint()
    {
        m_BreakPoint = -1.f;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      stopFading
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::stopFading()
    {
        m_IsFading = false;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \fn      updateFade
    ///
    ///////////////////////////////////////////////////////////
    void IFadable::updateFade(double deltaTime)
    {
        if (!m_IsFading)
            return;


        // Increases the elapsed time
        m_ElapsedTime += deltaTime;

        if (m_ElapsedTime >= IFADABLE_UPDATE_INTERVAL)
        {
            // Increase or decrease the value
            if (m_Mode == IFADABLE_FADE_IN)
            {
                m_Opacity += m_Speed;

                // Stops fading if value exceeded the maximum
                if (m_Opacity >= 1.f || (m_BreakPoint != -1 && m_Opacity >= m_BreakPoint))
                {
                    m_Opacity = 1.f;


                    // Checks whether the object should pulse
                    if (m_InitialMode == IFADABLE_FADE_PULSE)
                    {
                        m_IsFading = true;
                        m_Mode = IFADABLE_FADE_OUT;
                    }
                    else
                    {
                        m_IsFading = false;
                    }
                }
            }
            else
            {
                m_Opacity -= m_Speed;

                // Stops fading if value exceeded the minimum
                if (m_Opacity <= 0.f || (m_BreakPoint != -1 && m_Opacity <= m_BreakPoint))
                {
                    m_Opacity = 0.f;


                    // Checks whether the object should pulse
                    if (m_InitialMode == IFADABLE_FADE_PULSE)
                    {
                        m_IsFading = true;
                        m_Mode = IFADABLE_FADE_IN;
                    }
                    else
                    {
                        m_IsFading = false;
                    }
                }
            }


            m_ElapsedTime = 0.0;
        }
    }
}
