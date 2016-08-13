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
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    July 9th, 2016
/// \fn      initialize -> static
///
///////////////////////////////////////////////////////////
template <typename T> void Resources::initialize()
{
    // Assures that T is devired from Qube2D::Resource
    static_assert(std::is_base_of<Resource, T>::value,
                  "Given resource class is not a base of Qube2D::Resource!");

    // Retrieves the resource vector
    T *obj = new T;
    Resource *res = dynamic_cast<Resource *>(obj);
    std::vector<ResEntry *> vec = res->getResources();

    // Parses the resource vector to a map
    for (ResEntry *entry : vec)
    {
        PrivateRes priv { entry->type, entry->data };
        m_Resources.insert(std::make_pair(entry->name, priv));
    }
}

///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    June 27th, 2016
/// \fn      load -> static (specialization: utf8)
///
///////////////////////////////////////////////////////////
template <> const char *Resources::load
    <const char*>(const char *name)
{
    if (m_Resources.find(name) == m_Resources.end())
        return NULL;

    return reinterpret_cast<const char *>(m_Resources[name].data);
}

///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    June 27th, 2016
/// \fn      load -> static (specialization: utf16)
///
///////////////////////////////////////////////////////////
template <> const char16_t *Resources::load
    <const char16_t*>(const char *name)
{
    if (m_Resources.find(name) == m_Resources.end())
        return NULL;

    return (const char16_t *)(m_Resources[name].data);
}
