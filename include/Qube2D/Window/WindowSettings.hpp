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


#ifndef __Q2D_WINDOWSETTINGS_HPP__
#define __Q2D_WINDOWSETTINGS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Structs/Size.hpp>
#include <Qube2D/System/Structs/Point.hpp>
#include <Qube2D/System/Structs/Color.hpp>
#include <Qube2D/System/Structs/GLColor.hpp>
#include <Qube2D/Window/WindowEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    WindowSettings.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 2nd, 2016
    /// \class   WindowSettings
    /// \brief   Specifies game and window settings.
    ///
    /// In order to define an absolute spawning position,
    /// the relative window position must be set to 'Custom'.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API WindowSettings
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes all settings to default.
        ///
        ///////////////////////////////////////////////////////////
        WindowSettings();


        ///////////////////////////////////////////////////////////
        /// \fn       title -> const
        /// \brief    Retrieves the window title text.
        /// \returns  the UTF-8 window title.
        ///
        ///////////////////////////////////////////////////////////
        const char *title() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isFullscreen -> const
        /// \brief    Determines whether window is in FS mode.
        /// \returns  true if fullscreen is used.
        ///
        ///////////////////////////////////////////////////////////
        bool isFullscreen() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isVerticalSync -> const
        /// \brief    Determines whether blitting is VSynced.
        /// \returns  true if rendering is vertically synced.
        ///
        ///////////////////////////////////////////////////////////
        bool isVerticallySynced() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isDoubleBuffer -> const
        /// \brief    Determines whether a double buffer is used.
        /// \returns  true if using a front- and backbuffer.
        ///
        ///////////////////////////////////////////////////////////
        bool isDoubleBuffered() const;

        ///////////////////////////////////////////////////////////
        /// \fn       windowSize -> const
        /// \brief    Retrieves the window size in pixels.
        /// \returns  the absolute window size in pixel units.
        ///
        ///////////////////////////////////////////////////////////
        const SizeI &windowSize() const;

        ///////////////////////////////////////////////////////////
        /// \fn       windowPos -> const
        /// \brief    Retrieves the window position in pixels.
        /// \returns  the absolute window pos in pixel units.
        ///
        ///////////////////////////////////////////////////////////
        const PointI &windowPos() const;

        ///////////////////////////////////////////////////////////
        /// \fn       windowPosRelative -> const
        /// \brief    Retrieves the relative window position.
        /// \returns  one of the Qube2D::WindowPosition enum values.
        ///
        ///////////////////////////////////////////////////////////
        WindowPosition windowPosRelative() const;

        ///////////////////////////////////////////////////////////
        /// \fn       windowFlags -> const
        /// \brief    Retrieves the window style flags.
        /// \returns  one or a combination of Qube2D::WindowFlags.
        ///
        ///////////////////////////////////////////////////////////
        WindowFlags windowFlags() const;

        ///////////////////////////////////////////////////////////
        /// \fn       clearColor -> const
        /// \brief    Retrieves the OpenGL clear color.
        /// \returns  the clear color as GL color value.
        ///
        ///////////////////////////////////////////////////////////
        GLColor clearColor() const;


        ///////////////////////////////////////////////////////////
        /// \fn      setTitle
        /// \brief   Specifies the window title text.
        /// \param   title UTF-8 title
        ///
        ///////////////////////////////////////////////////////////
        void setTitle(const char *title);

        ///////////////////////////////////////////////////////////
        /// \fn     setFullscreen
        /// \brief  Specifies whether to use a fullscreen window.
        /// \param  fullscreen True to use fullscreen mode
        ///
        ///////////////////////////////////////////////////////////
        void setFullscreen(bool fullscreen);

        ///////////////////////////////////////////////////////////
        /// \fn     setVerticalSync
        /// \brief  Specifies whether to use vertical sync.
        /// \param  vsync True to vertically sync rendering
        ///
        ///////////////////////////////////////////////////////////
        void setVerticalSync(bool vsync);

        ///////////////////////////////////////////////////////////
        /// \fn     setDoubleBuffer
        /// \brief  Specifies whether to use a double buffer.
        /// \param  buffer True to use a secondary buffer
        ///
        ///////////////////////////////////////////////////////////
        void setDoubleBuffer(bool buffer);

        ///////////////////////////////////////////////////////////
        /// \fn     setWindowSize
        /// \brief  Specifies the initial window size.
        /// \param  size Size to use, in pixels
        ///
        ///////////////////////////////////////////////////////////
        void setWindowSize(const SizeI &size);

        ///////////////////////////////////////////////////////////
        /// \fn     setWindowPos
        /// \brief  Specifies the initial window position.
        /// \param  pos Position to use, in pixels
        /// \note   This operation sets 'windowPosRelative' to
        ///         WindowPosition::Custom.
        ///
        ///////////////////////////////////////////////////////////
        void setWindowPos(const PointI &pos);

        ///////////////////////////////////////////////////////////
        /// \fn     setWindowPosRelative
        /// \brief  Specifies the initial relative window position.
        /// \param  pos Relative point to use, WindowPosition value
        /// \note   This function makes 'windowPos' to be ignored
        ///         unless WindowPosition::Custom is specified.
        ///
        ///////////////////////////////////////////////////////////
        void setWindowPosRelative(WindowPosition pos);

        ///////////////////////////////////////////////////////////
        /// \fn     setWindowFlags
        /// \brief  Specifies the window creation flags.
        /// \param  flags One or a combination of window flags.
        ///
        ///////////////////////////////////////////////////////////
        void setWindowFlags(WindowFlags flags);

        ///////////////////////////////////////////////////////////
        /// \fn     setClearColor
        /// \brief  Specifies the RGBA clear color.
        /// \param  color Color to clear the screen with
        /// \note   This will be converted to a Qube2D::GLColor.
        ///
        ///////////////////////////////////////////////////////////
        void setClearColor(const Color &color);


    private:

        /////////////////////////////////////////////////////////////////////
        // Class members
        //
        /////////////////////////////////////////////////////////////////////
        const char *m_Title;            ///< The UTF-8 window title
        bool m_Fullscreen;              ///< Use fullscreen window?
        bool m_VerticalSync;            ///< Use VSync for rendering?
        bool m_DoubleBuffer;            ///< Use double buffer for rendering?
        SizeI m_WindowSize;             ///< Window size, in pixel units
        PointI m_WindowPos;             ///< Window pos, in pixel units
        WindowPosition m_WinPosRel;     ///< Relative window position
        WindowFlags m_WindowFlags;      ///< Window creation style flags
        GLColor m_ClearColor;           ///< OpenGL clear color

    };
}


#endif  // __Q2D_WINDOWSETTINGS_HPP__
