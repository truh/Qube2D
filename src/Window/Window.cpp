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
#include <Qube2D/System/Debug.hpp>
#include <Qube2D/Window/Window.hpp>
#include <Qube2D/Window/WindowErrors.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    // Static variable definitions
    //
    ///////////////////////////////////////////////////////////
    Window *Window::Current = NULL;
    RectF *Window::Viewport = NULL;


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 9th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Window::Window()
        : m_Window(NULL),
          m_IsActive(false)
    {
        // Sets all callbacks to a nullsub
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 9th, 2016
    /// \fn      Destructor
    ///
    ///////////////////////////////////////////////////////////
    Window::~Window()
    {
        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
            glfwTerminate();

            m_Window = NULL;
            Current = NULL;
        }


        delete Viewport;
        Viewport = NULL;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 9th, 2016
    /// \fn      create
    ///
    ///////////////////////////////////////////////////////////
    QBool Window::create(const WindowSettings &attr)
    {
        // Initializes the GLFW library
        if (!glfwInit())
        {
            Q2DError(Q2D_WINDOW_ERROR_0, 0);
            return false;
        }


        // Specifies the GLFW window hints, depending on the settings
        if (!attr.isDoubleBuffered())
            glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
        if (!(attr.windowFlags() & WindowFlags::Resizable))
            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        if (!(attr.windowFlags() & WindowFlags::Visible))
            glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
        if (!(attr.windowFlags() & WindowFlags::Focused))
            glfwWindowHint(GLFW_FOCUSED, GL_FALSE);
        if (!(attr.windowFlags() & WindowFlags::Decorated))
            glfwWindowHint(GLFW_DECORATED, GL_FALSE);


        // Sets the OpenGL context hints (for desktop)
    #   if !defined(Q2D_SYS_ANDROID) && !defined(Q2D_SYS_IOS)
            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #   endif


        // Attempts to retrieve the primary monitor's settings
        GLFWmonitor *monitor;
        const GLFWvidmode *video;
        if (!(monitor = glfwGetPrimaryMonitor()))
        {
            Q2DError(Q2D_WINDOW_ERROR_1, 0);
            return false;
        }
        if (!(video = glfwGetVideoMode(monitor)))
        {
            Q2DError(Q2D_WINDOW_ERROR_2, 0);
            return false;
        }


        // Extracts information about the window dimensions
        QInt32 width  = attr.windowSize().width();
        QInt32 height = attr.windowSize().height();
        QInt32 x = 0, y = 0;

        // Computes the desired window position
        if (attr.windowPosRelative() == WindowPosition::Custom)
        {
            x = attr.windowPos().x();
            y = attr.windowPos().y();
        }
        else
        {
            if (attr.windowPosRelative() == WindowPosition::TopRight)
            {
                x = (video->width - width);
            }
            else if (attr.windowPosRelative() == WindowPosition::BottomLeft)
            {
                y = (video->height - height);
            }
            else if (attr.windowPosRelative() == WindowPosition::BottomRight)
            {
                x = ( video->width  - width  );
                y = ( video->height - height );
            }
            else if (attr.windowPosRelative() == WindowPosition::Center)
            {
                x = ( video->width/2  ) - ( width/2  );
                y = ( video->height/2 ) - ( height/2 );
            }
        }


        // If we need a window in windowed mode, the monitor should be NULL.
        if (attr.isFullscreen())
        {
        }
        else
        {
            monitor = NULL;
        }


        // Creates the GLFW window and checks whether it is valid.
        if (!(m_Window = glfwCreateWindow(width, height, attr.title(), monitor, NULL)))
        {
            glfwTerminate();
            Q2DError(Q2D_WINDOW_ERROR_3, 0);
            return false;
        }


        // Sets the initial position and all the callbacks
        glfwSetWindowPos(m_Window, x, y);
        m_Settings = attr;
        Current = this;
        return true;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 10th, 2016
    /// \fn      destroy
    ///
    ///////////////////////////////////////////////////////////
    void Window::destroy(bool exit)
    {
        //Qube2D_Exit_Callback();
        glfwDestroyWindow(m_Window);
        glfwTerminate();

        if (exit)
            std::exit(0);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 10th, 2016
    /// \fn      start
    ///
    ///////////////////////////////////////////////////////////
    void Window::start()
    {
        // Assures that the window has been created beforehand
        if (!m_Window)
        {
            Q2DError(Q2D_WINDOW_ERROR_4, 0);
            return;
        }


        // Sets context current to this thread and loads extensions
        GLColor clear = m_Settings.clearColor();
        glfwMakeContextCurrent(m_Window);

    #   if defined(Q2D_SYS_ANDROID) || defined(Q2D_SYS_IOS)
            gladLoadGLES2Loader((GLADloadproc) glfwGetProcAddress);
    #   else
            gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    #   endif


        // Specifies the clear color and shows the window
        glClearColor(clear.r(), clear.g(), clear.b(), clear.a());
        glfwShowWindow(m_Window);


        // Enables vertical sync, if requested
        if (m_Settings.isVerticallySynced())
            glfwSwapInterval(GL_TRUE);
        else
            glfwSwapInterval(GL_FALSE);


        // Enables color blending for shaders etc.
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        m_IsActive = GL_TRUE;
        //Qube2D_Init_Callback();


        // Defines values for computing the delta time
        double elapsed = 0;
        double current = glfwGetTime();

        // Runs the main loop
        do
        {
            // Only performs updates and rendering if window is active
            if (m_IsActive)
            {
                // Updates the game (provides delta time)
                elapsed = glfwGetTime();
                //Qube2D_Update_Callback(elapsed-current);
                current = elapsed;

                // Renders the game
                glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
                //Qube2D_Render_Callback();
                glfwSwapBuffers(m_Window);

                // GLFW does not repeatedly send key-down events; we hack
                // this behaviour to provide multi-key-press features
                //Qube2D_KeyDown_Callback();
            }

            // Processes all pending GLFW events
            glfwPollEvents();

        } while (!glfwWindowShouldClose(m_Window));


        // Terminates the game and frees all resources
        //Qube2D_Exit_Callback();
        destroy();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 10th, 2016
    /// \fn      stop
    ///
    ///////////////////////////////////////////////////////////
    void Window::stop()
    {
        glfwSetWindowShouldClose(m_Window, GL_TRUE);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 10th, 2016
    /// \fn      setActive
    ///
    ///////////////////////////////////////////////////////////
    void Window::setActive(bool active)
    {
        m_IsActive = active;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 10th, 2016
    /// \fn      nativeWindow
    ///
    ///////////////////////////////////////////////////////////
    GLFWwindow *Window::nativeWindow() const
    {
        return m_Window;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 15th, 2016
    /// \fn      currentWindow -> static
    ///
    ///////////////////////////////////////////////////////////
    Window *Window::currentWindow()
    {
        return Current;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 15th, 2016
    /// \fn      viewport -> static
    ///
    ///////////////////////////////////////////////////////////
    RectF *Window::viewport()
    {
        return Viewport;
    }
}
