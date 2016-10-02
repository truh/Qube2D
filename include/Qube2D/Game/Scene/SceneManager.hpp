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


#ifndef __Q2D_SCENEMANAGER_HPP__
#define __Q2D_SCENEMANAGER_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Game/Scene/Scene.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    SceneManager.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \class   SceneManager
    /// \brief   Manages all scenes in the game.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API SceneManager
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of SceneManager.
        ///
        ///////////////////////////////////////////////////////////
        SceneManager();


        ///////////////////////////////////////////////////////////
        /// \fn     addScene
        /// \brief  Adds a new scene and receives events for it.
        /// \param  scene Class devired from Qube2D::Scene
        ///
        ///////////////////////////////////////////////////////////
        void addScene(Scene *scene);

        ///////////////////////////////////////////////////////////
        /// \fn     removeScene
        /// \brief  Removes the scene from the manager.
        /// \param  scene Scene to remove
        ///
        ///////////////////////////////////////////////////////////
        void removeScene(Scene *scene);


        ///////////////////////////////////////////////////////////
        /// \fn     update
        /// \brief  Updates the scene.
        /// \param  deltaTime Time between current and last update
        ///
        ///////////////////////////////////////////////////////////
        void update(double deltaTime);

        ///////////////////////////////////////////////////////////
        /// \fn     render
        /// \brief  Renders the scene.
        ///
        ///////////////////////////////////////////////////////////
        void render();

        ///////////////////////////////////////////////////////////
        /// \fn     keyDown
        /// \brief  Receives a key-down event.
        ///
        ///////////////////////////////////////////////////////////
        void keyDown();

        ///////////////////////////////////////////////////////////
        /// \fn     keyUp
        /// \brief  Receives a key-up event.
        ///
        ///////////////////////////////////////////////////////////
        void keyUp();

        ///////////////////////////////////////////////////////////
        /// \fn     keyChar
        /// \brief  Receives a key-char event.
        /// \param  codepoint UTF-32 pressed character
        ///
        ///////////////////////////////////////////////////////////
        void keyChar(char32_t codepoint);

        ///////////////////////////////////////////////////////////
        /// \fn     mouseDown
        /// \brief  Receives a mouse-down event.
        ///
        ///////////////////////////////////////////////////////////
        void mouseDown();

        ///////////////////////////////////////////////////////////
        /// \fn     mouseUp
        /// \brief  Receives a mouse-up event.
        ///
        ///////////////////////////////////////////////////////////
        void mouseUp();

        ///////////////////////////////////////////////////////////
        /// \fn     mouseMove
        /// \brief  Receives a mouse-move event.
        ///
        ///////////////////////////////////////////////////////////
        void mouseMove();

        ///////////////////////////////////////////////////////////
        /// \fn     mouseWheel
        /// \brief  Receives a mouse-wheel event.
        /// \param  offset Vertical scrolling position
        ///
        ///////////////////////////////////////////////////////////
        void mouseWheel(double offset);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        std::vector<Scene *> m_Scenes;

    };
}


#endif  // __Q2D_SCENEMANAGER_HPP__
