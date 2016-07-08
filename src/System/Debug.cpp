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
#include <Qube2D/System/Debug.hpp>
#include <algorithm>
#include <cstdarg>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    June 25th, 2016
    /// \fn      printError
    ///
    ///////////////////////////////////////////////////////////
    void Debug::printError
    (
            int n,
            const char *msg,
            const char *file,
            const char *func,
            int line,
            ...
    )
    {
        // If there are arguments in the error message string,
        // replace them with the given variadic values.
        std::string strMsg(msg);

        /* Variadic argument list */
        va_list argList;
        va_start(argList, line);
        for (int i = 0; i < n; i++)
        {
            std::string strArg("%");
            strArg.append(std::to_string(i));
            size_t index = strMsg.find(strArg);
            strMsg.replace(index, strArg.length(), va_arg(argList, char *));
        }
        va_end(argList);


        // Prints the detailed error message
        std::cout << "Error thrown in function '" << func
                  << "', in line " << line
                  << ", located at file\n'" << file
                  << "':\n\n    " << strMsg << "\n\n\n";
    }
}
