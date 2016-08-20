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
#include <Qube2D/Window/Window.hpp>
#include <Qube2D/Input/Keyboard.hpp>
#include <Qube2D/Input/Mouse.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Key_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Key_Callback(GLFWwindow */*window*/,
                           QInt32 key,
                           QInt32 /*scan*/,
                           QInt32 action,
                           QInt32 mods)
    {
        if (key == QUBE_KEY_UNKNOWN)
            return;


        // Specifies the modifiers
        Keyboard::setMod(mods);

        // Specifies the held/released key
        if (action == GLFW_PRESS)
        {
            Keyboard::addKey(key);
            Qube2D_KeyDown_Callback();
        }
        else if (action == GLFW_RELEASE)
        {
            Keyboard::remKey(key);
            Qube2D_KeyUp_Callback();
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Char_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Char_Callback(GLFWwindow */*window*/,
                            QUInt32 utf32,
                            QInt32 mods)
    {
        Keyboard::setMod(mods);
        Qube2D_KeyChar_Callback(utf32);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Cursor_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Cursor_Callback(GLFWwindow */*window*/,
                              QDouble x_pos,
                              QDouble y_pos)
    {
        Mouse::setPos(x_pos, y_pos);
        Qube2D_MouseMove_Callback();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Mouse_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Mouse_Callback(GLFWwindow */*window*/,
                             QInt32 button,
                             QInt32 action,
                             QInt32 mods)
    {
        // Specifies the modifiers
        Keyboard::setMod(mods);

        // Specifies the held/released buttons
        if (action == GLFW_PRESS)
        {
            Mouse::addButton(button);
            Qube2D_MouseDown_Callback();
        }
        else if (action == GLFW_RELEASE)
        {
            Mouse::remButton(button);
            Qube2D_MouseUp_Callback();
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Scroll_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Scroll_Callback(GLFWwindow */*window*/,
                              QDouble /*x_off*/,
                              QDouble y_off)
    {
        Qube2D_MouseWheel_Callback(y_off);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Focus_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Focus_Callback(GLFWwindow *, QInt32 is_focus)
    {
        if (is_focus)
        {
            Window::currentWindow()->setActive(true);
            // TODO: audio resuming
        }
        else
        {
            Window::currentWindow()->setActive(false);
            // TODO: audio pausing
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Resize_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Resize_Callback(GLFWwindow */*window*/,
                              QInt32 wid,
                              QInt32 hei)
    {
        // Updates the OpenGL viewport
        glViewport(0, 0, wid, hei);

        // Clears the rest of the screen and performs post-rendering
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        Qube2D_Render_Callback();
        glfwSwapBuffers(Window::currentWindow()->nativeWindow());
    }
    
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \fn      GLFW_Minimize_Callback
    ///
    ///////////////////////////////////////////////////////////
    void GLFW_Minimize_Callback(GLFWwindow *w, QInt32 minimize)
    {
        // Practically does the same as GLFW_Focus_Callback.
        GLFW_Focus_Callback(w, !minimize);
    }
}
