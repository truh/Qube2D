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
#include <iostream>


///////////////////////////////////////////////////////////
// Function declarations
//
///////////////////////////////////////////////////////////
int main();
void init();
void exit();


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    August 16th, 2016
/// \fn      main
/// \brief   Defines the main entry point for this app.
///
///////////////////////////////////////////////////////////
int main()
{
    Qube2D::WindowSettings settings;
    Qube2D::Window window;

    // ----------------------------
    settings.setWindowPosRelative(Qube2D::WindowPosition::Center);
    settings.setClearColor(Qube2D::Color(100, 149, 237));
    settings.setWindowSize(Qube2D::SizeI(600, 400));
    settings.setDoubleBuffer(true);
    settings.setVerticalSync(true);
    settings.setFullscreen(false);
    settings.setTitle("00_WindowCreation");

    // ----------------------------
    window.setInitializeFunction(init);
    window.setExitFunction(exit);
    window.create(settings);
    window.start();
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    August 16th, 2016
/// \fn      init
/// \brief   Initialization callback
///
///////////////////////////////////////////////////////////
void init()
{
    std::cout << "Initialize callback called!" << std::endl;
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    August 16th, 2016
/// \fn      exit
/// \brief   Exit callback
///
///////////////////////////////////////////////////////////
void exit()
{
    std::cout << "Exit callback called!" << std::endl;
}
