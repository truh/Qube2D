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
#include <Qube2D/Audio/System/AudioManager.hpp>
#include <Qube2D/Debug/ALCheck.hpp>
#include <string>
#include <iostream>
#include <al/al.h>
#include <al/alc.h>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      check
    ///
    ///////////////////////////////////////////////////////////
    void ALCheck::check(const char *file,
                        const long  line,
                        const char *expr)
    {
        QUInt32 error = alGetError();
        if (error == AL_NO_ERROR)
            return;


        std::string errorFile = file;
        std::string errorType = "Unknown error";
        std::string errorDesc = "Error could not be resolved.";
        errorFile = errorFile.substr(errorFile.find_last_of("\\/") + 1);

        // Determines the kind of the error
        if (error == AL_INVALID_NAME)
        {
            errorType = "Invalid name parameter";
            errorDesc = "Specified value is not a valid name for this function.";
        }
        else if (error == AL_INVALID_ENUM)
        {
            errorType = "Invalid enum value";
            errorDesc = "Specified value is not a valid ALenum for this function.";
        }
        else if (error == AL_INVALID_VALUE)
        {
            errorType = "Invalid value";
            errorDesc = "Specified value is not a legal one for this function.";
        }
        else if (error == AL_INVALID_OPERATION)
        {
            errorType = "Invalid operation";
            errorDesc = "This function did not succeed because the OpenAL states are errorneous.";
        }
        else if (error == AL_OUT_OF_MEMORY)
        {
            errorType = "Out of memory";
            errorDesc = "Requested memory size could not be allocated.";
        }


        // Outputs the error message
        std::cout << "The following OpenAL function threw an error"     << std::endl
                  << "\tin file: " << errorFile                         << std::endl
                  << "\tin line: " << line                              << std::endl
                  << "\tof type: " << errorType                         << std::endl
                  << "\tcall as: " << expr                              << std::endl
                  << "\tdetails: " << errorDesc                         << std::endl;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 19th, 2016
    /// \fn      checkAlc
    ///
    ///////////////////////////////////////////////////////////
    void ALCheck::checkAlc(const char *file,
                           const long  line,
                           const char *expr)
    {
        QUInt32 error = alcGetError(AudioManager::device());
        if (error == ALC_NO_ERROR)
            return;


        std::string errorFile = file;
        std::string errorType = "Unknown error";
        std::string errorDesc = "Error could not be resolved.";
        errorFile = errorFile.substr(errorFile.find_last_of("\\/") + 1);

        // Determines the kind of the error
        if (error == ALC_INVALID_DEVICE)
        {
            errorType = "No audio device";
            errorDesc = "No audio device connected to PC.";
        }
        else if (error == ALC_INVALID_ENUM)
        {
            errorType = "Invalid enum value";
            errorDesc = "Specified value is not a valid ALCenum for this function.";
        }
        else if (error == ALC_INVALID_VALUE)
        {
            errorType = "Invalid value";
            errorDesc = "Specified value is not a legal one for this function.";
        }
        else if (error == ALC_INVALID_CONTEXT)
        {
            errorType = "Invalid context";
            errorDesc = "This OpenAL context identifier does not exist.";
        }
        else if (error == ALC_OUT_OF_MEMORY)
        {
            errorType = "Out of memory";
            errorDesc = "Requested memory size could not be allocated.";
        }


        // Outputs the error message
        std::cout << "The following OpenAL context function threw an error" << std::endl
                  << "\tin file: " << errorFile                             << std::endl
                  << "\tin line: " << line                                  << std::endl
                  << "\tof type: " << errorType                             << std::endl
                  << "\tcall as: " << expr                                  << std::endl
                  << "\tdetails: " << errorDesc                             << std::endl;
    }
}
