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
#include <Qube2D/Graphics/Background.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Background::Background()
        : ISprite(),
          Object(),
          m_SpeedScrollingX(1.f),
          m_SpeedScrollingY(1.f),
          m_ScrollingDirection(0),
          m_IsScrolling(false),
          m_IsInfinite(false),
          m_ScrollTargetX(0.f),
          m_ScrollTargetY(0.f),
          m_RepeatCountX(0),
          m_RepeatCountY(0),
          m_ScrollPosX(0.f),
          m_ScrollPosY(0.f)
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      Destructor
    ///
    ///////////////////////////////////////////////////////////
    Background::~Background()
    {
        // Destroys ISprite and all class members
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      setScrollingSpeed
    ///
    ///////////////////////////////////////////////////////////
    void Background::setScrollingSpeed(QFloat speedX, QFloat speedY)
    {
        m_SpeedScrollingX = speedX;
        m_SpeedScrollingY = speedY;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      setScrollingDirection
    ///
    ///////////////////////////////////////////////////////////
    void Background::setScrollingDirection(ScrollDirection dir)
    {
        if (dir == ScrollDirection::Up)
            m_ScrollingDirection = BACKGROUND_DIR_UP;
        else if (dir == ScrollDirection::Down)
            m_ScrollingDirection = BACKGROUND_DIR_DOWN;
        else if (dir == ScrollDirection::Right)
            m_ScrollingDirection = BACKGROUND_DIR_RIGHT;
        else if (dir == ScrollDirection::Left)
            m_ScrollingDirection = BACKGROUND_DIR_LEFT;
        else if (dir == ScrollDirection::UpAndRight)
            m_ScrollingDirection = BACKGROUND_DIR_UP | BACKGROUND_DIR_RIGHT;
        else if (dir == ScrollDirection::UpAndLeft)
            m_ScrollingDirection = BACKGROUND_DIR_UP | BACKGROUND_DIR_LEFT;
        else if (dir == ScrollDirection::DownAndRight)
            m_ScrollingDirection = BACKGROUND_DIR_DOWN | BACKGROUND_DIR_RIGHT;
        else
            m_ScrollingDirection = BACKGROUND_DIR_DOWN | BACKGROUND_DIR_LEFT;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      startScrolling
    ///
    ///////////////////////////////////////////////////////////
    void Background::startScrolling(QFloat offsetX, QFloat offsetY)
    {
        initScrolling();
        m_ScrollPosX = 0.f;
        m_ScrollPosY = 0.f;


        // If both parameters are zero, BG will be scrolled forever
        if (static_cast<int>(offsetX) == 0 && static_cast<int>(offsetY) == 0)
        {
            m_IsInfinite = true;
            m_IsScrolling = true;
            return;
        }

        m_ScrollTargetX = m_PosX + offsetX;
        m_ScrollTargetY = m_PosY + offsetY;
        m_IsInfinite = false;
        m_IsScrolling = true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      stopScrolling
    ///
    ///////////////////////////////////////////////////////////
    void Background::stopScrolling()
    {
        m_IsInfinite = false;
        m_IsScrolling = false;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      initScrolling
    ///
    ///////////////////////////////////////////////////////////
    void Background::initScrolling()
    {
        // Repeats the texture on each 2D axis
        m_Texture.bind();
        m_Texture.setVerticalWrap(Qube2D::WrapMode::Repeat);
        m_Texture.setHorizontalWrap(Qube2D::WrapMode::Repeat);


        // Calculates the amount of repeated images on the screen
        m_RepeatCountX = m_WinW / m_Texture.width();
        m_RepeatCountY = m_WinH / m_Texture.height();


        // Modifies the vertex attributes to fill the entire window
        m_Vertices.v0.xy(0.f, 0.f);
        m_Vertices.v1.xy(m_WinW, 0.f);
        m_Vertices.v2.xy(m_WinW, m_WinH);
        m_Vertices.v3.xy(0.f, m_WinH);

        // Modifies the texture coordinates to repeat
        m_Vertices.v0.uv(0.f, 0.f);
        m_Vertices.v1.uv(m_RepeatCountX, 0.f);
        m_Vertices.v2.uv(m_RepeatCountX, m_RepeatCountY);
        m_Vertices.v3.uv(0.f, m_RepeatCountY);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 9th, 2016
    /// \fn      update
    ///
    ///////////////////////////////////////////////////////////
    void Background::update(double deltaTime)
    {
        // Do moving, fading and transforming
        ISprite::update(deltaTime);

        // Applies scrolling
        if (!m_IsScrolling)
            return;


        m_ElapsedTimeSC += deltaTime;

        if (m_ElapsedTimeSC >= BACKGROUND_UPDATE_INTERVAL)
        {
            if ((m_ScrollingDirection & BACKGROUND_DIR_LEFT) != 0)
            {
                m_ScrollPosX -= m_SpeedScrollingX;

                // If background reached end of window, reset to position ZERO
                if (m_ScrollPosX <= -m_Texture.width())
                    m_ScrollPosX = 0.f;
            }
            else if ((m_ScrollingDirection & BACKGROUND_DIR_RIGHT) != 0)
            {
                m_ScrollPosX += m_SpeedScrollingX;

                // If background reached end of window, reset to position ZERO
                if (m_ScrollPosX >= m_Texture.width())
                    m_ScrollPosX = 0.f;
            }
            if ((m_ScrollingDirection & BACKGROUND_DIR_UP) != 0)
            {
                m_ScrollPosY -= m_SpeedScrollingY;

                // If background reached end of window, reset to position ZERO
                if (m_ScrollPosY <= -m_Texture.height())
                    m_ScrollPosY = 0.f;
            }
            else
            {
                m_ScrollPosY += m_SpeedScrollingY;

                // If background reached end of window, reset to position ZERO
                if (m_ScrollPosY >= m_Texture.height())
                    m_ScrollPosY = 0.f;
            }


            m_ElapsedTimeSC = 0.0;

            // Calculates the texture coordinates from the scrolling position
            float coX = m_ScrollPosX / m_Texture.width();
            float coY = m_ScrollPosY / m_Texture.height();
            float coW = m_RepeatCountX - coX;
            float coH = m_RepeatCountY - coY;

            m_Vertices.v0.uv(-coX, -coY);
            m_Vertices.v1.uv( coW, -coY);
            m_Vertices.v2.uv( coW,  coH);
            m_Vertices.v3.uv(-coX,  coH);
        }
    }
}
