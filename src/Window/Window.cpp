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
#include <Qube2D/Debug/Debug.hpp>
#include <Qube2D/Window/Window.hpp>
#include <Qube2D/Window/WindowErrors.hpp>
#include <Qube2D/Graphics/System/Base/ISprite.hpp>
#include <Qube2D/Graphics/System/Base/IPrimitive.hpp>
#include <Qube2D/Graphics/System/Base/IMovable.hpp>
#include <Qube2D/Graphics/Text.hpp>
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

    #ifdef Q2D_DEBUG
    const char *Qube2D_Window_Title;
    void Qube2D_Window_Draw_FPS(double);
    #endif


    ////////////////////////////////////////////////////////////////////
    // Callback definitions
    //
    ////////////////////////////////////////////////////////////////////
    PFNQUBEINIT         Qube2D_Init_Callback        = [] (  void  ) { };
    PFNQUBEEXIT         Qube2D_Exit_Callback        = [] (  void  ) { };
    PFNQUBEUPDATE       Qube2D_Update_Callback      = [] ( double ) { };
    PFNQUBERENDER       Qube2D_Render_Callback      = [] (  void  ) { };
    PFNQUBEKEYDOWN      Qube2D_KeyDown_Callback     = [] (  void  ) { };
    PFNQUBEKEYUP        Qube2D_KeyUp_Callback       = [] (  void  ) { };
    PFNQUBEKEYCHAR      Qube2D_KeyChar_Callback     = [] (unsigned) { };
    PFNQUBEMOUSEDOWN    Qube2D_MouseDown_Callback   = [] (  void  ) { };
    PFNQUBEMOUSEUP      Qube2D_MouseUp_Callback     = [] (  void  ) { };
    PFNQUBEMOUSEMOVE    Qube2D_MouseMove_Callback   = [] (  void  ) { };
    PFNQUBEMOUSEWHEEL   Qube2D_MouseWheel_Callback  = [] ( double ) { };


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
        // Initializes the viewport
        Viewport = new RectF;
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
            Q2DErrorNoArg(Q2D_WINDOW_ERROR_0);
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
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #   else // (for mobile devices)
            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); // OpenGLES 2.0
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    #   endif
    #   ifdef Q2D_DEBUG
            Qube2D_Window_Title = attr.title();
    #   endif


        // Attempts to retrieve the primary monitor's settings
        GLFWmonitor *monitor;
        const GLFWvidmode *video;
        if (!(monitor = glfwGetPrimaryMonitor()))
        {
            Q2DErrorNoArg(Q2D_WINDOW_ERROR_1);
            return false;
        }
        if (!(video = glfwGetVideoMode(monitor)))
        {
            Q2DErrorNoArg(Q2D_WINDOW_ERROR_2);
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
        // Also, the viewport is different for fullscreen windows.
        if (attr.isFullscreen())
        {
            Viewport->setX(0);
            Viewport->setY(0);
            Viewport->setWidth(video->width);
            Viewport->setHeight(video->height);
        }
        else
        {
            monitor = NULL;
            Viewport->setX(static_cast<float>(x));
            Viewport->setY(static_cast<float>(y));
            Viewport->setWidth(static_cast<float>(attr.windowSize().width()));
            Viewport->setHeight(static_cast<float>(attr.windowSize().height()));
        }


        // Creates the GLFW window and checks whether it is valid.
        if (!(m_Window = glfwCreateWindow(width, height, attr.title(), monitor, NULL)))
        {
            glfwTerminate();
            Q2DErrorNoArg(Q2D_WINDOW_ERROR_3);
            return false;
        }


        // Sets the initial position and all the callbacks
        glfwSetWindowPos(m_Window, x, y);
        glfwSetKeyCallback(m_Window, GLFW_Key_Callback);
        glfwSetCharModsCallback(m_Window, GLFW_Char_Callback);
        glfwSetScrollCallback(m_Window, GLFW_Scroll_Callback);
        glfwSetWindowFocusCallback(m_Window, GLFW_Focus_Callback);
        glfwSetCursorPosCallback(m_Window, GLFW_Cursor_Callback);
        glfwSetMouseButtonCallback(m_Window, GLFW_Mouse_Callback);
        glfwSetWindowSizeCallback(m_Window, GLFW_Resize_Callback);
        glfwSetWindowIconifyCallback(m_Window, GLFW_Minimize_Callback);


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
        ISprite::destroyGL();
        IPrimitive::destroyGL();
        Text::destroyGL();
        FontManager::destroyFT2();

        glfwDestroyWindow(m_Window);
        glfwTerminate();

        if (exit)
            std::exit(GL_NO_ERROR);
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
            Q2DErrorNoArg(Q2D_WINDOW_ERROR_4);
            return;
        }


        // Sets context current to this thread and loads extensions
        glfwMakeContextCurrent(m_Window);

    #   if defined(Q2D_SYS_ANDROID) || defined(Q2D_SYS_IOS)
            gladLoadGLES2Loader((GLADloadproc) glfwGetProcAddress);
    #   else
            gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    #   endif


        // Specifies the clear color and shows the window
        GLColor clear = m_Settings.clearColor();
        glClearColor(clear.r(), clear.g(), clear.b(), clear.a());
        glfwShowWindow(m_Window);


        // Enables vertical sync, if requested
        if (m_Settings.isVerticallySynced())
            glfwSwapInterval(GL_TRUE);
        else
            glfwSwapInterval(GL_FALSE);


        // Initializes global OpenGL objects
        ISprite::initializeGL();
        IPrimitive::initializeGL();
        IMovable::initializeView();
        Text::initializeGL();
        FontManager::initializeFT2();


        // Enables color blending for shaders etc.
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        m_IsActive = GL_TRUE;
        Qube2D_Init_Callback();


        // Defines values for computing the delta time
        double elapsed = 0;
        double current = glfwGetTime();

        // Runs the main loop
        do
        {
            while (!m_IsActive)
                glfwWaitEvents();


            // Updates the game (provides delta time)
            elapsed = glfwGetTime();
            Qube2D_Update_Callback(elapsed-current);

            // Renders the game
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            Qube2D_Render_Callback();
            glfwSwapBuffers(m_Window);

            // Sets the amount of FPS as window title, if debugging
        #ifdef Q2D_DEBUG
            Qube2D_Window_Draw_FPS(elapsed-current);
        #endif

            current = elapsed;

            // Processes all pending GLFW events
            glfwPollEvents();

        } while (!glfwWindowShouldClose(m_Window));


        // Terminates the game and frees all resources
        Qube2D_Exit_Callback();
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
    /// \date    August 16th, 2016
    /// \fn      setInitializeFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setInitializeFunction(PFNQUBEINIT func)
    {
        Qube2D_Init_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setExitFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setExitFunction(PFNQUBEEXIT func)
    {
        Qube2D_Exit_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setUpdateFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setUpdateFunction(PFNQUBEUPDATE func)
    {
        Qube2D_Update_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setRenderFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setRenderFunction(PFNQUBERENDER func)
    {
        Qube2D_Render_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setKeyDownFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setKeyDownFunction(PFNQUBEKEYDOWN func)
    {
        Qube2D_KeyDown_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setKeyUpFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setKeyUpFunction(PFNQUBEKEYUP func)
    {
        Qube2D_KeyUp_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setKeyCharFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setKeyCharFunction(PFNQUBEKEYCHAR func)
    {
        Qube2D_KeyChar_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setMouseDownFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setMouseDownFunction(PFNQUBEMOUSEDOWN func)
    {
        Qube2D_MouseDown_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setMouseUpFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setMouseUpFunction(PFNQUBEMOUSEUP func)
    {
        Qube2D_MouseUp_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setMouseWheelFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setMouseWheelFunction(PFNQUBEMOUSEWHEEL func)
    {
        Qube2D_MouseWheel_Callback = func;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 16th, 2016
    /// \fn      setMouseMoveFunction
    ///
    ///////////////////////////////////////////////////////////
    void Window::setMouseMoveFunction(PFNQUBEMOUSEMOVE func)
    {
        Qube2D_MouseMove_Callback = func;
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


    #ifdef Q2D_DEBUG
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      Qube2D_Window_Draw_FPS
    ///
    ///////////////////////////////////////////////////////////
    void Qube2D_Window_Draw_FPS(double deltaTime)
    {
        // Calculates the FPS
        double fps = (1000.0 / deltaTime) / 1000.0;

        // Generates a string out of it
        GLFWwindow *cwin = Window::currentWindow()->nativeWindow();
        std::string fstr = std::to_string(fps);
        fstr.insert(0u, " - FPS: ");
        fstr.insert(0u, Qube2D_Window_Title);

        // Sets the new title
        glfwSetWindowTitle(cwin, fstr.c_str());
    }
    #endif
}
