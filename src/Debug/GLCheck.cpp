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
#include <Qube2D/Debug/GLCheck.hpp>
#include <glad/glad.h>
#include <iostream>
#include <string>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 18th, 2016
    /// \fn      check
    ///
    ///////////////////////////////////////////////////////////
    void GLCheck::check(const char *file,
                        const long line,
                        const char *expr)
    {
        QUInt32 error = glGetError();
        if (error == GL_NO_ERROR)
            return;
        
        
        std::string errorFile = file;
        std::string errorType = "Unknown error";
        std::string errorDesc = "Error could not be resolved.";
        errorFile = errorFile.substr(errorFile.find_last_of("\\/") + 1);
        
        // Determines the kind of the error
        if (error == GL_INVALID_ENUM)
        {
            errorType = "Invalid enum value";
            errorDesc = "Specified value is not a valid GLenum for this function.";
        }
        else if (error == GL_INVALID_VALUE)
        {
            errorType = "Invalid value";
            errorDesc = "Specified value is not a legal value for this function.";
        }
        else if (error == GL_INVALID_OPERATION)
        {
            errorType = "Invalid operation";
            errorDesc = "The current OpenGL states do not allow this function to succeed.";
        }
        else if (error == GL_STACK_OVERFLOW)
        {
            errorType = "Stack overflow";
            errorDesc = "Pushing not possible; exceeded limit of stack size.";
        }
        else if (error == GL_STACK_UNDERFLOW)
        {
            errorType = "Stack underflow";
            errorDesc = "Popping not possible; stack is at its lowest point.";
        }
        else if (error == GL_OUT_OF_MEMORY)
        {
            errorType = "Out of memory";
            errorDesc = "Requested memory size could not be allocated.";
        }
        else if (error == GL_INVALID_FRAMEBUFFER_OPERATION)
        {
            errorType = "Invalid FBO operation";
            errorDesc = "Read/write to framebuffer failed.";
        }
        
        
        // Outputs the error message
        std::cout << "The following OpenGL function threw an error"     << std::endl
                  << "\tin file: " << errorFile                         << std::endl
                  << "\tin line: " << line                              << std::endl
                  << "\tof type: " << errorType                         << std::endl
                  << "\tcall as: " << expr                              << std::endl
                  << "\tdetails: " << errorDesc                         << std::endl;
    }
}
