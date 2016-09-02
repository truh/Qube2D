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


#ifndef __Q2D_ASSETS_INL_HPP__
#define __Q2D_ASSETS_INL_HPP__
#include <Qube2D/Assets/AssetErrors.hpp>


///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    June 28th, 2016
/// \fn      load<T> -> static
///
///////////////////////////////////////////////////////////
template <typename T> inline T Assets::load(const char* path)
{
    static_assert(true, "The given resource type is currently not supported.");
    auto nowarning = [](const char*) -> void {};
    nowarning(path);
}

///////////////////////////////////////////////////////////
/// \author  Nicolas Kogler (kogler.cml@hotmail.com)
/// \date    June 28th, 2016
/// \fn      load<const char *> -> static
///
///////////////////////////////////////////////////////////
template <> inline const char* Assets::load(const char* path)
{
    assert(path);

    // Determines whether the given path is absolute or relative
    std::string filePath;
    if (isRelative(path))
        filePath = makePath(path);
    else
        filePath = path;

    // Attempts to open the file in READ mode
    File file;
    if (!file.open(filePath.c_str(), FA_Read))
    {
        Q2DError(Q2D_ASSETS_ERROR_0, path);
        return NULL;
    }

    // Reads all the file's string contents
    return file.readString(file.size());
}


#endif  // __Q2D_ASSETS_INL_HPP__
