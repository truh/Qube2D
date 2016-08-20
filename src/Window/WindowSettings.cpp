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
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Window/WindowSettings.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      Constructor
    ///
    ///////////////////////////////////////////////////////////
    WindowSettings::WindowSettings()
        : m_Title("Qube2D Window"),
          m_Fullscreen(false),
          m_VerticalSync(true),
          m_DoubleBuffer(true),
          m_WindowSize({ 800, 600 }),
          m_WinPosRel(WindowPosition::Center),
          m_WindowFlags(WindowFlags::Resizable|
                        WindowFlags::Decorated|
                        WindowFlags::Visible|
                        WindowFlags::Focused)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      title -> const
    ///
    ///////////////////////////////////////////////////////////
    const char *WindowSettings::title() const
    {
        return m_Title;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      isFullscreen -> const
    ///
    ///////////////////////////////////////////////////////////
    bool WindowSettings::isFullscreen() const
    {
        return m_Fullscreen;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      isVerticalSync -> const
    ///
    ///////////////////////////////////////////////////////////
    bool WindowSettings::isVerticallySynced() const
    {
        return m_VerticalSync;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      isDoubleBuffer -> const
    ///
    ///////////////////////////////////////////////////////////
    bool WindowSettings::isDoubleBuffered() const
    {
        return m_DoubleBuffer;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      windowSize -> const
    ///
    ///////////////////////////////////////////////////////////
    const SizeI &WindowSettings::windowSize() const
    {
        return m_WindowSize;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      windowPos -> const
    ///
    ///////////////////////////////////////////////////////////
    const PointI &WindowSettings::windowPos() const
    {
        return m_WindowPos;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      windowPosRelative -> const
    ///
    ///////////////////////////////////////////////////////////
    WindowPosition WindowSettings::windowPosRelative() const
    {
        return m_WinPosRel;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      windowFlags -> const
    ///
    ///////////////////////////////////////////////////////////
    WindowFlags WindowSettings::windowFlags() const
    {
        return m_WindowFlags;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      clearColor -> const
    ///
    ///////////////////////////////////////////////////////////
    GLColor WindowSettings::clearColor() const
    {
        return m_ClearColor;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      setTitle
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setTitle(const char *title)
    {
        m_Title = title;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      setFullscreen
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setFullscreen(bool fullscreen)
    {
        m_Fullscreen = fullscreen;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      setVerticalSync
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setVerticalSync(bool vsync)
    {
        m_VerticalSync = vsync;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      setDoubleBuffer
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setDoubleBuffer(bool buffer)
    {
        m_DoubleBuffer = buffer;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \fn      setWindowSize
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setWindowSize(const SizeI &size)
    {
        m_WindowSize = size;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 3rd, 2016
    /// \fn      setWindowPos
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setWindowPos(const PointI &pos)
    {
        m_WindowPos = pos;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 3rd, 2016
    /// \fn      setWindowPosRelative
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setWindowPosRelative(WindowPosition pos)
    {
        m_WinPosRel = pos;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 3rd, 2016
    /// \fn      setWindowFlags
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setWindowFlags(WindowFlags flags)
    {
        m_WindowFlags = flags;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 3rd, 2016
    /// \fn      setClearColor
    ///
    ///////////////////////////////////////////////////////////
    void WindowSettings::setClearColor(const Color &color)
    {
        m_ClearColor = color.toGL();
    }
}
