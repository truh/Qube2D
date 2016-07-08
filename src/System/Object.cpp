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
#include <Qube2D/System/Object.hpp>
#include <algorithm>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Object::Object(Object *parent)
        : m_Parent(parent)
    {
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      Destructor -> virtual
    ///
    ///////////////////////////////////////////////////////////
    Object::~Object()
    {
        // Destroys all children
        for (Object *obj : m_Children)
            delete obj;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      parent -> const
    ///
    ///////////////////////////////////////////////////////////
    Object *Object::parent() const
    {
        return m_Parent;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      children -> const
    ///
    ///////////////////////////////////////////////////////////
    const std::vector<Object *> &Object::children() const
    {
        return m_Children;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      name -> const
    ///
    ///////////////////////////////////////////////////////////
    const char *Object::name() const
    {
        return m_Name.c_str();
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      childrenOfName -> const
    ///
    ///////////////////////////////////////////////////////////
    const std::vector<Object *> Object
        ::childrenOfName(const char *name) const
    {
        std::vector<Object *> matches;
        std::string prefix = name;

        for (Object *obj : m_Children)
            if (obj->m_Name.substr(0, prefix.size()) == prefix)
                matches.push_back(obj);

        return matches;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      property -> const
    ///
    ///////////////////////////////////////////////////////////
    const Variant &Object::property(const char *name) const
    {
        if (m_Properties.find(name) == m_Properties.end())
            return m_InvalidProp; // property does not exist

        return m_Properties.at(name);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      setParent
    ///
    ///////////////////////////////////////////////////////////
    void Object::setParent(Object *parent)
    {
        m_Parent = parent;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      addChild
    ///
    ///////////////////////////////////////////////////////////
    void Object::addChild(Object *child)
    {
        m_Children.push_back(child);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      addChildren
    ///
    ///////////////////////////////////////////////////////////
    void Object::addChildren(const std::vector<Object *> &children)
    {
        m_Children.insert(m_Children.end(), children.begin(), children.end());
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      removeChild
    ///
    ///////////////////////////////////////////////////////////
    void Object::removeChild(const Object *child)
    {
        for (QUInt32 i = 0; i < m_Children.size(); i++)
            if (m_Children.at(i) == child)
                m_Children.erase(m_Children.begin()+i);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      removeChild -> overload #1
    ///
    ///////////////////////////////////////////////////////////
    void Object::removeChild(QUInt32 index)
    {
        m_Children.erase(m_Children.begin()+index);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      removeChildren
    ///
    ///////////////////////////////////////////////////////////
    void Object::removeChildren(const std::vector<Object *> &children)
    {
        for (QUInt32 i = 0; i < children.size(); i++)
            removeChild(children.at(i));
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      setName
    ///
    ///////////////////////////////////////////////////////////
    void Object::setName(const char *name)
    {
        m_Name = name;
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 8th, 2016
    /// \fn      setProperty
    ///
    ///////////////////////////////////////////////////////////
    void Object::setProperty(const char *name, const Variant &variant)
    {
        if (m_Properties.find(name) != m_Properties.end())
        {
            // Property already exists
            m_Properties[name] = variant;
        }
        else
        {
            // Create new property
            m_Properties.insert(std::make_pair(name, variant));
        }
    }
}
