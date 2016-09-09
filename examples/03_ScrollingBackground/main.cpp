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
#include <Qube2D/Graphics/Background.hpp>


#define STATE_RED 0
#define STATE_GRN 1
#define STATE_BLU 2


///////////////////////////////////////////////////////////
// Function declarations
//
///////////////////////////////////////////////////////////
int main();
void init();
void exit();
void update(double deltaTime);
void render();


///////////////////////////////////////////////////////////
// Qube2D objects
//
///////////////////////////////////////////////////////////
Qube2D::Background bg;
Qube2D::Color blendColor;
QUInt32 state = STATE_RED;


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 8th, 2016
/// \fn      main
/// \brief   Defines the main entry point for this app.
///
///////////////////////////////////////////////////////////
int main()
{
    Qube2D::WindowSettings settings;
    Qube2D::Window window;

    settings.setWindowPosRelative(Qube2D::WindowPosition::Center);
    settings.setClearColor(Qube2D::Color(100, 149, 237));
    settings.setWindowSize(Qube2D::SizeI(600, 400));
    settings.setDoubleBuffer(true);
    settings.setVerticalSync(true);
    settings.setFullscreen(false);
    settings.setTitle("03_ScrollingBackground");

    window.setInitializeFunction(init);
    window.setExitFunction(exit);
    window.setUpdateFunction(update);
    window.setRenderFunction(render);
    window.create(settings);
    window.start();
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 8th, 2016
/// \fn      init
/// \brief   Initialization callback
///
///////////////////////////////////////////////////////////
void init()
{
    blendColor.setR(200);
    blendColor.setG(100);
    blendColor.setB(100);

    bg.create();
    bg.load("Qube2D.png");
    bg.setScrollingDirection(Qube2D::ScrollDirection::DownAndRight);
    bg.setBlendColor(blendColor);
    bg.startScrolling(0.f, 0.f);    // infinite
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 8th, 2016
/// \fn      exit
/// \brief   Exit callback
///
///////////////////////////////////////////////////////////
void exit()
{
    bg.destroy();
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 8th, 2016
/// \fn      update
/// \brief   Update callback
///
///////////////////////////////////////////////////////////
void update(double deltaTime)
{
    if (state == STATE_RED)
    {
        blendColor.setR(blendColor.r() - 1);
        blendColor.setG(blendColor.g() + 1);

        if (blendColor.r() == 100)
            state = STATE_GRN;
    }
    else if (state == STATE_GRN)
    {
        blendColor.setG(blendColor.g() - 1);
        blendColor.setB(blendColor.b() + 1);

        if (blendColor.g() == 100)
            state = STATE_BLU;
    }
    else if (state == STATE_BLU)
    {
        blendColor.setB(blendColor.b() - 1);
        blendColor.setR(blendColor.r() + 1);

        if (blendColor.b() == 100)
            state = STATE_RED;
    }

    bg.setBlendColor(blendColor);
    bg.update(deltaTime);
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 8th, 2016
/// \fn      render
/// \brief   Render callback
///
///////////////////////////////////////////////////////////
void render()
{
    bg.render();
}
