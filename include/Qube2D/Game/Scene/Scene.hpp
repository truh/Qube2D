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


#ifndef __Q2D_SCENE_HPP__
#define __Q2D_SCENE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/System/Object.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Scene.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \class   Scene
    /// \brief   Defines a game-scene with child scenes.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Scene : public Object
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Scene.
        ///
        ///////////////////////////////////////////////////////////
        Scene();

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor -> virtual
        /// \brief  Frees objects allocated by this scene.
        ///
        ///////////////////////////////////////////////////////////
        virtual ~Scene();


        ///////////////////////////////////////////////////////////
        /// \fn     update -> virtual
        /// \brief  Updates the scene.
        /// \param  deltaTime Time between current and last update
        ///
        ///////////////////////////////////////////////////////////
        virtual void update(double deltaTime);

        ///////////////////////////////////////////////////////////
        /// \fn     render -> virtual
        /// \brief  Renders the scene.
        ///
        ///////////////////////////////////////////////////////////
        virtual void render();

        ///////////////////////////////////////////////////////////
        /// \fn     keyDown -> virtual
        /// \brief  Receives a key-down event.
        ///
        ///////////////////////////////////////////////////////////
        virtual void keyDown();

        ///////////////////////////////////////////////////////////
        /// \fn     keyUp -> virtual
        /// \brief  Receives a key-up event.
        ///
        ///////////////////////////////////////////////////////////
        virtual void keyUp();

        ///////////////////////////////////////////////////////////
        /// \fn     keyChar -> virtual
        /// \brief  Receives a key-char event.
        /// \param  codepoint UTF-32 pressed character
        ///
        ///////////////////////////////////////////////////////////
        virtual void keyChar(char32_t codepoint);

        ///////////////////////////////////////////////////////////
        /// \fn     mouseDown -> virtual
        /// \brief  Receives a mouse-down event.
        ///
        ///////////////////////////////////////////////////////////
        virtual void mouseDown();

        ///////////////////////////////////////////////////////////
        /// \fn     mouseUp -> virtual
        /// \brief  Receives a mouse-up event.
        ///
        ///////////////////////////////////////////////////////////
        virtual void mouseUp();

        ///////////////////////////////////////////////////////////
        /// \fn     mouseMove -> virtual
        /// \brief  Receives a mouse-move event.
        ///
        ///////////////////////////////////////////////////////////
        virtual void mouseMove();

        ///////////////////////////////////////////////////////////
        /// \fn     mouseWheel -> virtual
        /// \brief  Receives a mouse-wheel event.
        /// \param  offset Vertical scrolling position
        ///
        ///////////////////////////////////////////////////////////
        virtual void mouseWheel(double offset);

    };
}


#endif  // __Q2D_SCENE_HPP__
