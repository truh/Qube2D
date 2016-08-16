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


#ifndef __Q2D_WINDOWCALLBACKS_HPP__
#define __Q2D_WINDOWCALLBACKS_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>


///////////////////////////////////////////////////////////
// Forward declaration
//
///////////////////////////////////////////////////////////
struct GLFWwindow; ///< User does not have to link against GLFW


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    WindowCallbacks.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 5th, 2016
    /// \def     PFNQUBE
    /// \brief   Callback types for Qube2D::Window callbacks.
    ///
    ///////////////////////////////////////////////////////////
    ///
    typedef void ( *PFNQUBEINIT       )(  void  );
    typedef void ( *PFNQUBEEXIT       )(  void  );
    typedef void ( *PFNQUBEUPDATE     )( double );
    typedef void ( *PFNQUBERENDER     )(  void  );
    typedef void ( *PFNQUBEKEYDOWN    )(  void  );
    typedef void ( *PFNQUBEKEYUP      )(  void  );
    typedef void ( *PFNQUBEKEYCHAR    )(  void  );
    typedef void ( *PFNQUBEMOUSEDOWN  )(  void  );
    typedef void ( *PFNQUBEMOUSEUP    )(  void  );
    typedef void ( *PFNQUBEMOUSEMOVE  )(  void  );
    typedef void ( *PFNQUBEMOUSEWHEEL )( double );


    ///////////////////////////////////////////////////////////
    /// \file    WindowCallbacks.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \def     Qube2D_XYZW_Callback
    /// \brief   Delegates holding the callback functions.
    ///
    ///////////////////////////////////////////////////////////
    ///
    PFNQUBEINIT         Qube2D_Init_Callback;
    PFNQUBEEXIT         Qube2D_Exit_Callback;
    PFNQUBEUPDATE       Qube2D_Update_Callback;
    PFNQUBERENDER       Qube2D_Render_Callback;
    PFNQUBEKEYDOWN      Qube2D_KeyDown_Callback;
    PFNQUBEKEYUP        Qube2D_KeyUp_Callback;
    PFNQUBEKEYCHAR      Qube2D_KeyChar_Callback;
    PFNQUBEMOUSEDOWN    Qube2D_MouseDown_Callback;
    PFNQUBEMOUSEUP      Qube2D_MouseUp_Callback;
    PFNQUBEMOUSEMOVE    Qube2D_MouseMove_Callback;
    PFNQUBEMOUSEWHEEL   Qube2D_MouseWheel_Callback;


    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Key_Callback
    /// \brief  Translates the GLFW key event.
    ///
    /// Depending on 'action', calls the Qube_KeyUp_Callback
    /// or the Qube_KeyDown_Callback. Stores the given states
    /// in an array of keys in order to check for multiple
    /// key presses.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  key Portable GLFW key code
    /// \param  scan Ignored; Platform-specific key
    /// \param  action Press, release or repeat
    /// \param  mods Currently held modifier keys
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Key_Callback(GLFWwindow *window,
                                  QInt32 key,
                                  QInt32 scan,
                                  QInt32 action,
                                  QInt32 mods);


    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Char_Callback
    /// \brief  Translates the GLFW char event.
    ///
    /// Passes the unicode character that represents the latest
    /// key that was pressed by the user.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  utf32 UTF-32 encoded character representation
    /// \param  mods Currently held modifier keys
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Char_Callback(GLFWwindow *window,
                                   QUInt32 utf32,
                                   QInt32 mods);

    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Cursor_Callback
    /// \brief  Translates the GLFW curpos event.
    ///
    /// Stores the mouse position within the current window.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  x_pos X-position of cursor, relative to window
    /// \param  y_pos Y-position of cursor, relative to window
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Cursor_Callback(GLFWwindow *window,
                                     QDouble x_pos,
                                     QDouble y_pos);

    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Mouse_Callback
    /// \brief  Translates the GLFW mouse event.
    ///
    /// Depending on 'action', calls the Qube_MouseUp_Callback
    /// or the Qube_MouseDown_Callback. Stores the given states
    /// in an array of buttons in order to check for multiple
    /// button presses.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  button Held mouse button
    /// \param  action Press, release or repeat
    /// \param  mods Currently held modifier keys
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Mouse_Callback(GLFWwindow *window,
                                    QInt32 button,
                                    QInt32 action,
                                    QInt32 mods);

    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Scroll_Callback
    /// \brief  Translates the GLFW scroll event.
    ///
    /// Passes the vertical scroll to a Qube2D callback.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  x_off Horizontal scroll offset
    /// \param  y_off Vertical scroll offset
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Key_Callback(GLFWwindow *window,
                                  QDouble x_off,
                                  QDouble y_off);

    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Focus_Callback
    /// \brief  Translates the GLFW focus event.
    ///
    /// May deactivate the window in order to stop updating
    /// and rendering and music eventually.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  is_focus Determines whether it is focused
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Char_Callback(GLFWwindow *window,
                                   QBool is_focus);

    ///////////////////////////////////////////////////////////
    /// \fn     GLFW_Resize_Callback
    /// \brief  Translates the GLFW resize event.
    ///
    /// Changes the OpenGL viewport and performs post-rendering
    /// so the rest of the window does not appear transparent.
    ///
    /// \param  window Ignored; Window::Current used
    /// \param  wid New width of the window
    /// \param  hei New height of the window
    ///
    ///////////////////////////////////////////////////////////
    extern void GLFW_Cursor_Callback(GLFWwindow *window,
                                     QInt32 wid,
                                     QInt32 hei);
}


#endif  // __Q2D_WINDOWCALLBACKS_HPP__
