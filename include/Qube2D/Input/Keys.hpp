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


#ifndef __Q2D_KEYS_HPP__
#define __Q2D_KEYS_HPP__


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Keys.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \def     QUBE_KEY_XYZW
    ///
    ///////////////////////////////////////////////////////////
    ///
    #define QUBE_KEY_UNKNOWN            -1
    #define QUBE_KEY_SPACE              32
    #define QUBE_KEY_APOSTROPHE         39
    #define QUBE_KEY_COMMA              44
    #define QUBE_KEY_MINUS              45
    #define QUBE_KEY_PERIOD             46
    #define QUBE_KEY_SLASH              47
    #define QUBE_KEY_0                  48
    #define QUBE_KEY_1                  49
    #define QUBE_KEY_2                  50
    #define QUBE_KEY_3                  51
    #define QUBE_KEY_4                  52
    #define QUBE_KEY_5                  53
    #define QUBE_KEY_6                  54
    #define QUBE_KEY_7                  55
    #define QUBE_KEY_8                  56
    #define QUBE_KEY_9                  57
    #define QUBE_KEY_SEMICOLON          59
    #define QUBE_KEY_EQUAL              61
    #define QUBE_KEY_A                  65
    #define QUBE_KEY_B                  66
    #define QUBE_KEY_C                  67
    #define QUBE_KEY_D                  68
    #define QUBE_KEY_E                  69
    #define QUBE_KEY_F                  70
    #define QUBE_KEY_G                  71
    #define QUBE_KEY_H                  72
    #define QUBE_KEY_I                  73
    #define QUBE_KEY_J                  74
    #define QUBE_KEY_K                  75
    #define QUBE_KEY_L                  76
    #define QUBE_KEY_M                  77
    #define QUBE_KEY_N                  78
    #define QUBE_KEY_O                  79
    #define QUBE_KEY_P                  80
    #define QUBE_KEY_Q                  81
    #define QUBE_KEY_R                  82
    #define QUBE_KEY_S                  83
    #define QUBE_KEY_T                  84
    #define QUBE_KEY_U                  85
    #define QUBE_KEY_V                  86
    #define QUBE_KEY_W                  87
    #define QUBE_KEY_X                  88
    #define QUBE_KEY_Y                  89
    #define QUBE_KEY_Z                  90
    #define QUBE_KEY_LEFT_BRACKET       91
    #define QUBE_KEY_BACKSLASH          92
    #define QUBE_KEY_RIGHT_BRACKET      93
    #define QUBE_KEY_GRAVE_ACCENT       96
    #define QUBE_KEY_WORLD_1            161
    #define QUBE_KEY_WORLD_2            162
    #define QUBE_KEY_ESCAPE             256
    #define QUBE_KEY_ENTER              257
    #define QUBE_KEY_TAB                258
    #define QUBE_KEY_BACKSPACE          259
    #define QUBE_KEY_INSERT             260
    #define QUBE_KEY_DELETE             261
    #define QUBE_KEY_RIGHT              262
    #define QUBE_KEY_LEFT               263
    #define QUBE_KEY_DOWN               264
    #define QUBE_KEY_UP                 265
    #define QUBE_KEY_PAGE_UP            266
    #define QUBE_KEY_PAGE_DOWN          267
    #define QUBE_KEY_HOME               268
    #define QUBE_KEY_END                269
    #define QUBE_KEY_CAPS_LOCK          280
    #define QUBE_KEY_SCROLL_LOCK        281
    #define QUBE_KEY_NUM_LOCK           282
    #define QUBE_KEY_PRINT_SCREEN       283
    #define QUBE_KEY_PAUSE              284
    #define QUBE_KEY_F1                 290
    #define QUBE_KEY_F2                 291
    #define QUBE_KEY_F3                 292
    #define QUBE_KEY_F4                 293
    #define QUBE_KEY_F5                 294
    #define QUBE_KEY_F6                 295
    #define QUBE_KEY_F7                 296
    #define QUBE_KEY_F8                 297
    #define QUBE_KEY_F9                 298
    #define QUBE_KEY_F10                299
    #define QUBE_KEY_F11                300
    #define QUBE_KEY_F12                301
    #define QUBE_KEY_F13                302
    #define QUBE_KEY_F14                303
    #define QUBE_KEY_F15                304
    #define QUBE_KEY_F16                305
    #define QUBE_KEY_F17                306
    #define QUBE_KEY_F18                307
    #define QUBE_KEY_F19                308
    #define QUBE_KEY_F20                309
    #define QUBE_KEY_F21                310
    #define QUBE_KEY_F22                311
    #define QUBE_KEY_F23                312
    #define QUBE_KEY_F24                313
    #define QUBE_KEY_F25                314
    #define QUBE_KEY_KP_0               320
    #define QUBE_KEY_KP_1               321
    #define QUBE_KEY_KP_2               322
    #define QUBE_KEY_KP_3               323
    #define QUBE_KEY_KP_4               324
    #define QUBE_KEY_KP_5               325
    #define QUBE_KEY_KP_6               326
    #define QUBE_KEY_KP_7               327
    #define QUBE_KEY_KP_8               328
    #define QUBE_KEY_KP_9               329
    #define QUBE_KEY_KP_DECIMAL         330
    #define QUBE_KEY_KP_DIVIDE          331
    #define QUBE_KEY_KP_MULTIPLY        332
    #define QUBE_KEY_KP_SUBTRACT        333
    #define QUBE_KEY_KP_ADD             334
    #define QUBE_KEY_KP_ENTER           335
    #define QUBE_KEY_KP_EQUAL           336
    #define QUBE_KEY_LEFT_SHIFT         340
    #define QUBE_KEY_LEFT_CONTROL       341
    #define QUBE_KEY_LEFT_ALT           342
    #define QUBE_KEY_LEFT_SUPER         343
    #define QUBE_KEY_RIGHT_SHIFT        344
    #define QUBE_KEY_RIGHT_CONTROL      345
    #define QUBE_KEY_RIGHT_ALT          346
    #define QUBE_KEY_RIGHT_SUPER        347
    #define QUBE_KEY_MENU               348
    #define QUBE_KEY_LAST               QUBE_KEY_MENU


    ///////////////////////////////////////////////////////////
    /// \file    Keys.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    August 17th, 2016
    /// \def     QUBE_MOD_XYZW
    ///
    ///////////////////////////////////////////////////////////
    ///
    #define QUBE_MOD_SHIFT              0x0001
    #define QUBE_MOD_CONTROL            0x0002
    #define QUBE_MOD_ALT                0x0004
    #define QUBE_MOD_SYS                0x0008
}


#endif  // __Q2D_KEYS_HPP__
