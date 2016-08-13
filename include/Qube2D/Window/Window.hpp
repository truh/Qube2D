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


#ifndef __Q2D_WINDOW_HPP__
#define __Q2D_WINDOW_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Uncopyable.hpp>
#include <Qube2D/Window/WindowSettings.hpp>
#include <Qube2D/Window/WindowCallbacks.hpp>


///////////////////////////////////////////////////////////
// Forward declaration
//
///////////////////////////////////////////////////////////
struct GLFWwindow; ///< User does not have to link against GLFW


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Window.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 4th, 2016
    /// \class   Window : Uncopyable
    /// \brief   Handles window, OpenGL context and events.
    ///
    /// The Qube2D::Window basically wraps a GLFW window,
    /// receives and parses it's events and maintains the
    /// main-loop with all it's events.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Window : Uncopyable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Window.
        ///
        ///////////////////////////////////////////////////////////
        Window();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor
        /// \brief  Frees the GLFW window, if no already done so.
        ///
        /// Also disposes of resources used by Qube2D::Window.
        ///
        ///////////////////////////////////////////////////////////
        ~Window();


        ///////////////////////////////////////////////////////////
        /// \fn       create
        /// \brief    Creates a new platform-dependent window.
        /// \param    attr Game- and window settings
        /// \returns  true if the creation was successful.
        ///
        ///////////////////////////////////////////////////////////
        bool create(const WindowSettings &attr);

        ///////////////////////////////////////////////////////////
        /// \fn     destroy
        /// \brief  Terminates the window & disposes of resources.
        /// \param  exit True if program should exit afterwards.
        ///
        ///////////////////////////////////////////////////////////
        void destroy(bool exit = false);

        ///////////////////////////////////////////////////////////
        /// \fn     start
        /// \brief  Runs the main-loop of this window.
        ///
        /// This function does nothing if window not created yet.
        ///
        ///////////////////////////////////////////////////////////
        void start();

        ///////////////////////////////////////////////////////////
        /// \fn     stop
        /// \brief  Terminates the main-loop of this window.
        ///
        /// Hides the window and stops receiving events. In order
        /// to enable updates again, call 'start'.
        ///
        ///////////////////////////////////////////////////////////
        void stop();

        ///////////////////////////////////////////////////////////
        /// \fn     setActive
        /// \brief  Activates or deactivates updates of the window.
        /// \param  active True if activated, false if not
        ///
        ///////////////////////////////////////////////////////////
        void setActive(bool active);

        ///////////////////////////////////////////////////////////
        /// \fn       nativeWindow
        /// \brief    Returns the underlying GLFW window.
        ///
        /// Used to adapt GLFW functionality that is not directly
        /// supported by Qube2D. Using this function requires you
        /// to include GLFW headers and thus to link against GLFW.
        ///
        /// \returns  a pointer to the GLFWwindow structure.
        ///
        ///////////////////////////////////////////////////////////
        GLFWwindow *nativeWindow() const;


        ///////////////////////////////////////////////////////////
        /// \fn     setInitializeFunction
        /// \brief  Sets the initialization function.
        ///
        /// Specifies the function that is executed after the
        /// window was created.
        ///
        /// \param  func The initialization function to call
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setInitializeFunction(PFNQUBEINIT func);

        ///////////////////////////////////////////////////////////
        /// \fn     setExitFunction
        /// \brief  Sets the exit function.
        ///
        /// Specifies the function that is executed after the
        /// window was destroyed.
        ///
        /// \param  func The exit function to call
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setExitFunction(PFNQUBEEXIT func);

        ///////////////////////////////////////////////////////////
        /// \fn     setUpdateFunction
        /// \brief  Sets the updating function.
        ///
        /// Specifies the function that is executed every frame
        /// to update animations, movements and other things.
        ///
        /// \param  func The update function to call
        /// \note   sig: void func_name(double deltaTime);
        ///
        ///////////////////////////////////////////////////////////
        void setUpdateFunction(PFNQUBEUPDATE func);

        ///////////////////////////////////////////////////////////
        /// \fn     setRenderFunction
        /// \brief  Sets the rendering function.
        ///
        /// Specifies the function that is executed every frame
        /// to render primitives, images, text and other things.
        ///
        /// \param  func The render function to call
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setRenderFunction(PFNQUBERENDER func);

        ///////////////////////////////////////////////////////////
        /// \fn     setKeyDownFunction
        /// \brief  Sets the key-down function.
        ///
        /// Specifies the function that is executed after any
        /// key was pressed down.
        ///
        /// \param  func The function to call on key press.
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setKeyDownFunction(PFNQUBEKEYDOWN func);

        ///////////////////////////////////////////////////////////
        /// \fn     setKeyUpFunction
        /// \brief  Sets the key-up function.
        ///
        /// Specifies the function that is executed after any
        /// key was pressed up.
        ///
        /// \param  func The function to call on key release.
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setKeyUpFunction(PFNQUBEKEYUP func);

        ///////////////////////////////////////////////////////////
        /// \fn     setKeyCharFunction
        /// \brief  Sets the key-char function.
        ///
        /// Specifies the function that is executed after a
        /// printable character was pressed down.
        ///
        /// \param  func The function to call on character typing.
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setKeyCharFunction(PFNQUBEKEYCHAR func);


        ///////////////////////////////////////////////////////////
        /// \fn     setMouseDownFunction
        /// \brief  Sets the mouse-down function.
        ///
        /// Specifies the function that is executed after any
        /// mouse button was pressed down.
        ///
        /// \param  func The function to call on button press.
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setMouseDownFunction(PFNQUBEMOUSEDOWN func);

        ///////////////////////////////////////////////////////////
        /// \fn     setMouseUpFunction
        /// \brief  Sets the mouse-up function.
        ///
        /// Specifies the function that is executed after any
        ///  mouse button was pressed up.
        ///
        /// \param  func The function to call on button release.
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setMouseUpFunction(PFNQUBEMOUSEUP func);

        ///////////////////////////////////////////////////////////
        /// \fn     setMouseMoveFunction
        /// \brief  Sets the mouse-move function.
        ///
        /// Specifies the function that is executed after the
        /// mouse cursor changed it's position.
        ///
        /// \param  func The function to call on cursor move.
        /// \note   sig: void func_name();
        ///
        ///////////////////////////////////////////////////////////
        void setMouseMoveFunction(PFNQUBEMOUSEMOVE func);

        ///////////////////////////////////////////////////////////
        /// \fn     setMouseWheelFunction
        /// \brief  Sets the mouse-wheel function.
        ///
        /// Specifies the function that is executed after the
        /// mouse wheel was scrolled.
        ///
        /// \param  func The function to call on wheel scroll.
        /// \note   sig: void func_name(double scrollOffset);
        ///
        ///////////////////////////////////////////////////////////
        void setMouseWheelFunction(PFNQUBEMOUSEWHEEL func);


        ///////////////////////////////////////////////////////////
        /// \var    Qube2D::Window::Current
        /// \brief  Holds the currently active window.
        ///
        ///////////////////////////////////////////////////////////
        Window *Current = { 0 };


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QBool m_IsActive;           ///< Is window currently active?
        GLFWwindow *m_Window;       ///< Underlying GLFW window
        WindowSettings m_Settings;  ///< Game & window settings

    };
}


#endif  // __Q2D_WINDOW_HPP__
