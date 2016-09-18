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
#include <Qube2D/Graphics/Text.hpp>


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
Qube2D::Font *font = NULL;
Qube2D::Font *jfont = NULL;
Qube2D::Text latinText;
Qube2D::Text greekText;
Qube2D::Text russianText;
Qube2D::Text arabicText;
Qube2D::Text japaneseText;
Qube2D::Text rotText;
Qube2D::Color color;
Qube2D::Color incolor;


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 15th, 2016
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
    settings.setTitle("06_Text");

    window.setInitializeFunction(init);
    window.setExitFunction(exit);
    window.setUpdateFunction(update);
    window.setRenderFunction(render);
    window.create(settings);
    window.start();
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 15th, 2016
/// \fn      init
/// \brief   Initialization callback
///
///////////////////////////////////////////////////////////
void init()
{
    font = Qube2D::FontManager::loadFont("Arial.ttf");
    jfont = Qube2D::FontManager::loadFont("TakaoGothic.ttf");
    color = Qube2D::Color(0, 0, 0);
    incolor = Qube2D::Color(255, 255, 255);

    latinText.create();
    latinText.setFont(font);
    latinText.setTextSize(32);
    latinText.setOutlineWidth(2.f);
    latinText.setText(U"Je suis un texte français!", Qube2D::TextStyle::Outline);
    latinText.setPosition(10.f, 10.f);
    latinText.setColor(color);
    latinText.setOutlineColor(incolor);

    greekText.create();
    greekText.setFont(font);
    greekText.setTextSize(32);
    greekText.setLineWidth(2.f);
    greekText.setText(U"Αυτό είναι Έλληνες", Qube2D::TextStyle::Underline);
    greekText.setPosition(10.f, 52.f);
    greekText.setColor(color);

    russianText.create();
    russianText.setFont(font);
    russianText.setTextSize(32);
    russianText.setLineWidth(2.f);
    russianText.setText(U"Это русский", Qube2D::TextStyle::Strikethrough);
    russianText.setPosition(10.f, 94.f);
    russianText.setColor(color);

    arabicText.create();
    arabicText.setFont(font);
    arabicText.setTextSize(32);
    arabicText.setOutlineWidth(2.f);
    arabicText.setShadowOffset(4, 4);
    arabicText.setText(U"وهي اللcغة العربية", Qube2D::TextStyle::DropShadow);
    arabicText.setPosition(10.f, 136.f);
    arabicText.setColor(color);

    japaneseText.create();
    japaneseText.setFont(jfont);
    japaneseText.setTextSize(32);
    japaneseText.setText(U"それが日本です");
    japaneseText.setPosition(10.f, 178.f);
    japaneseText.setColor(color);

    rotText.create();
    rotText.setFont(font);
    rotText.setTextSize(20);
    rotText.setText(U"Rotated\nText", Qube2D::TextStyle::Bold);
    rotText.setPosition(10.f, 240.f);

    // Measure rotText to specify origin
    Qube2D::SizeF s = font->measureString(U"Rotated\nText", Qube2D::TextStyle::Bold, 20);
    rotText.setOrigin(s.width() / 2.f, s.height() / 2.f);
    rotText.startRotation(360, Qube2D::RotateDirection::Clockwise);
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 15th, 2016
/// \fn      exit
/// \brief   Exit callback
///
///////////////////////////////////////////////////////////
void exit()
{
    latinText.destroy();
    greekText.destroy();
    russianText.destroy();
    arabicText.destroy();
    japaneseText.destroy();
    rotText.destroy();
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 15th, 2016
/// \fn      update
/// \brief   Update callback
///
///////////////////////////////////////////////////////////
void update(double deltaTime)
{
    latinText.update(deltaTime);
    greekText.update(deltaTime);
    russianText.update(deltaTime);
    arabicText.update(deltaTime);
    japaneseText.update(deltaTime);
    rotText.update(deltaTime);

    if (!rotText.isRotating())
        rotText.startRotation(360, Qube2D::RotateDirection::Clockwise);
}


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    September 15th, 2016
/// \fn      render
/// \brief   Render callback
///
///////////////////////////////////////////////////////////
void render()
{
    latinText.render();
    greekText.render();
    russianText.render();
    arabicText.render();
    japaneseText.render();
    rotText.render();
}
