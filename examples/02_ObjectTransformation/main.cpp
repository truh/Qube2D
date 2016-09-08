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
#include <Qube2D/Graphics/Base/ISprite.hpp>


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
Qube2D::ISprite image;


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

    // ----------------------------
    settings.setWindowPosRelative(Qube2D::WindowPosition::Center);
    settings.setClearColor(Qube2D::Color(100, 149, 237));
    settings.setWindowSize(Qube2D::SizeI(600, 400));
    settings.setDoubleBuffer(true);
    settings.setVerticalSync(true);
    settings.setFullscreen(false);
    settings.setTitle("02_ObjectTransformation");

    // ----------------------------
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
    image.create();
    image.load("Qube2D.png");
    image.setScale(1.f);
    image.startScaling(0.5f);
    image.setScalingSpeed(0.002f);
    image.setRotationSpeed(1.f);
    image.startRotation(360.f, Qube2D::RotateDirection::Clockwise);
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
    image.destroy();
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
    image.update(deltaTime);

    // Upon scaling, image size changes; therefore update
    // rotation origin to the center of the object.
    image.setRotationOrigin(180.f*image.scale(), 180.f*image.scale());
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
    image.render();
}
