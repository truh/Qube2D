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
//  GNU Lesser General Public License for more details->
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with  Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Game/Scene/SceneManager.hpp>
#include <Qube2D/Debug/Debug.hpp>
#include <algorithm>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    SceneManager::SceneManager()
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      addScene
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::addScene(Scene *scene)
    {
        assert(scene);

        m_Scenes.push_back(scene);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      removeScene
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::removeScene(Scene *scene)
    {
        assert(scene);

        auto it = std::find(m_Scenes.begin(), m_Scenes.end(), scene);
        if (it != m_Scenes.end())
            m_Scenes.erase(it);
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      update
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::update(double deltaTime)
    {
        for (Scene *s : m_Scenes)
            s->update(deltaTime);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      render
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::render()
    {
        for (Scene *s : m_Scenes)
            s->render();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      keyDown
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::keyDown()
    {
        for (Scene *s : m_Scenes)
            s->keyDown();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      keyUp
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::keyUp()
    {
        for (Scene *s : m_Scenes)
            s->keyUp();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      keyChar
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::keyChar(char32_t codepoint)
    {
        for (Scene *s : m_Scenes)
            s->keyChar(codepoint);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      mouseDown
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::mouseDown()
    {
        for (Scene *s : m_Scenes)
            s->mouseDown();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      mouseUp
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::mouseUp()
    {
        for (Scene *s : m_Scenes)
            s->mouseUp();
    }
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      mouseMove
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::mouseMove()
    {
        for (Scene *s : m_Scenes)
            s->mouseMove();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 28th, 2016
    /// \fn      mouseWheel
    ///
    ///////////////////////////////////////////////////////////
    void SceneManager::mouseWheel(double offset)
    {
        for (Scene *s : m_Scenes)
            s->mouseWheel(offset);
    }
}
