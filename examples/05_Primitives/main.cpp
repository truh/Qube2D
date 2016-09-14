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
#include <Qube2D/Graphics/Shapes/Line.hpp>
#include <Qube2D/Graphics/Shapes/Triangle.hpp>
#include <Qube2D/Graphics/Shapes/Rectangle.hpp>
#include <Qube2D/Graphics/Shapes/Polygon.hpp>
#include <Qube2D/Graphics/Shapes/Circle.hpp>
#include <Qube2D/Graphics/Shapes/Ellipse.hpp>
#include <Qube2D/Graphics/Shapes/Arc.hpp>
#include <cmath>


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
Qube2D::Line line;
Qube2D::Triangle triangle;
Qube2D::Rectangle rectangle;
Qube2D::Rectangle spinrect;
Qube2D::Polygon hexagon;
Qube2D::Polygon nonagon;
Qube2D::Circle circle;
Qube2D::Ellipse ellipse;
Qube2D::Arc arc;
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
    settings.setTitle("05_Primitives");

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
    Qube2D::Color white(0xFF, 0xFF, 0xFF);
    Qube2D::Color red(0xFF, 0x0, 0x0);
    Qube2D::Color grn(0x0, 0xFF, 0x0);
    Qube2D::Color blu(0x0, 0x0, 0xFF);

    blendColor.setR(255);
    blendColor.setG(0);
    blendColor.setB(0);


    line.create();
    line.setLine({ 0.f, 0.f }, { 100.f, 100.f });
    line.setColor(Qube2D::Color(0xFF, 0x0, 0x0), Qube2D::Color(0x0, 0xFF, 0xFF));

    triangle.create();
    triangle.setPosition(200.f, 0.f);
    triangle.setTriangle({ 100.f, 0.0f }, { 0.f, 200.f }, { 200.f, 200.f });
    triangle.setColor(white, white, white);
    triangle.setFilled(true);

    rectangle.create();
    rectangle.setRect({ 0.f, 0.f, 100.f, 100.f });
    rectangle.setPosition(50.f, 200.f);
    rectangle.setColor(white, red, grn, blu);

    spinrect.create();
    spinrect.setRect({ 0.f, 0.f, 100.f, 100.f });
    spinrect.setPosition(200.f, 250.f);
    spinrect.setColor(white, red, grn, blu);
    spinrect.setFilled(true);
    spinrect.startRotation(360, Qube2D::RotateDirection::Clockwise);

    hexagon.create();
    hexagon.generateRegular(200.f, 6);
    hexagon.setColor({ red });
    hexagon.setPosition(400.f, 40.f);
    hexagon.startScaling(0.2f);
    hexagon.setScalingSpeed(0.02f);

    nonagon.create();
    nonagon.generateRegular(100.f, 9);
    nonagon.setColor({ blu });
    nonagon.setPosition(400.f, 250.f);
    nonagon.startRotation(360.f, Qube2D::RotateDirection::CounterClockwise);
    nonagon.startFading(Qube2D::FadeMode::Pulse);
    nonagon.setRotationSpeed(5.f);
    nonagon.setFadingSpeed(0.05f);
    nonagon.setFilled(true);

    circle.create();
    circle.setRadius(50.f);
    circle.setColor(grn);
    circle.setFilled(true);
    circle.setPosition(250.f, 80.f);

    ellipse.create();
    ellipse.setRadii(80.f, 50.f);
    ellipse.setColor(white);
    ellipse.setPosition(80.f, 0.f);

    // note: start angle is always counter-clockwise. 0° = right
    arc.create();
    arc.setArc(0.f, 0.f, 60.f);
    arc.setColor(red);
    arc.setPosition(70.f, 110.f);
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
    line.destroy();
    triangle.destroy();
    rectangle.destroy();
    spinrect.destroy();
    hexagon.destroy();
    nonagon.destroy();
    circle.destroy();
    ellipse.destroy();
    arc.destroy();
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
    line.update(deltaTime);
    triangle.update(deltaTime);
    rectangle.update(deltaTime);
    spinrect.update(deltaTime);
    hexagon.update(deltaTime);
    nonagon.update(deltaTime);
    circle.update(deltaTime);
    ellipse.update(deltaTime);
    arc.update(deltaTime);

    // If rotation stopped, start another one
    if (!spinrect.isRotating())
        spinrect.startRotation(360, Qube2D::RotateDirection::Clockwise);
    if (!nonagon.isRotating())
        nonagon.startRotation(360, Qube2D::RotateDirection::CounterClockwise);

    // If scaling stopped, start another one
    static int scale_dir = 0;
    if (!hexagon.isScaling() && scale_dir == 0)
    {
        hexagon.startScaling(1.f);
        scale_dir = 1;
    }
    else if (!hexagon.isScaling())
    {
        hexagon.startScaling(0.2f);
        scale_dir = 0;
    }

    // Change color from red to green to blue to red
    if (state == STATE_RED)
    {
        blendColor.setR(blendColor.r() - 5);
        blendColor.setG(blendColor.g() + 5);

        if (blendColor.r() == 0)
            state = STATE_GRN;
    }
    else if (state == STATE_GRN)
    {
        blendColor.setG(blendColor.g() - 5);
        blendColor.setB(blendColor.b() + 5);

        if (blendColor.g() == 0)
            state = STATE_BLU;
    }
    else if (state == STATE_BLU)
    {
        blendColor.setB(blendColor.b() - 5);
        blendColor.setR(blendColor.r() + 5);

        if (blendColor.b() == 0)
            state = STATE_RED;
    }

    circle.setColor(blendColor);

    // Modify the arc to build up a circle
    static bool arc_ccw = true;
    static float arc_ang = 0;
    static double arc_int = 0.0;

    arc_int += deltaTime;
    if (arc_int >= 0.020)
    {
        arc_int = 0.0;

        if (arc_ccw)
        {
            arc_ang += 4.f;
            if (arc_ang >= 360.f)
            {
                arc_ccw = false;
                arc_ang = 362.f;
            }
        }
        else
        {
            arc_ang -= 4.f;
            if (arc_ang <= 0.f)
            {
                arc_ccw = true;
                arc_ang = 0.f;
            }
        }

        arc.setArc(0.f, arc_ang, 60.f);
    }
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
    line.render();
    triangle.render();
    rectangle.render();
    spinrect.render();
    hexagon.render();
    nonagon.render();
    circle.render();
    ellipse.render();
    arc.render();
}
