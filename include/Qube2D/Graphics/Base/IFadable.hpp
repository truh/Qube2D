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


#ifndef __Q2D_IFADABLE_HPP__
#define __Q2D_IFADABLE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Graphics/Base/BaseEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    IFadable.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 3rd, 2016
    /// \class   IFadable
    /// \brief   Allows fading an object in and out.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API IFadable
    {
        
    public:
        
        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Fadable.
        /// 
        ///////////////////////////////////////////////////////////
        IFadable();
        
        
        ///////////////////////////////////////////////////////////
        /// \fn       opacity -> const
        /// \brief    Retrieves the current opacity.
        /// \returns  the opacity value between 0.0 and 1.0.
        /// 
        ///////////////////////////////////////////////////////////
        QFloat opacity() const;
        
        ///////////////////////////////////////////////////////////
        /// \fn       isFading -> const
        /// \brief    Determines whether the object is still fading.
        /// \returns  TRUE if the object is still fading.
        /// 
        ///////////////////////////////////////////////////////////
        QBool isFading() const;
        
        
        ///////////////////////////////////////////////////////////
        /// \fn     setInitialOpacity
        /// \brief  Specifies the initial opacity before fading.
        /// \param  opacity Initial opacity between 0.0 and 1.0
        /// 
        ///////////////////////////////////////////////////////////
        void setInitialOpacity(QFloat opacity);
        
        ///////////////////////////////////////////////////////////
        /// \fn     setFadingSpeed
        /// \brief  Specifies the speed of the fade.
        /// \param  speed Speed between 0.0 and 1.0.
        /// \note   The specified value will be added/substracted
        ///         to/from the opacity everytime the fade updates.
        /// 
        ///////////////////////////////////////////////////////////
        void setFadingSpeed(QFloat speed);
        
        
        ///////////////////////////////////////////////////////////
        /// \fn     startFading
        /// \brief  Starts fading the object.
        /// \param  mode Specifies the fading mode
        /// \note   Will fully fade to either 0.0 or 1.0, except
        ///         if a breakpoint was specified.
        /// 
        ///////////////////////////////////////////////////////////
        void startFading(FadeMode mode);
        
        ///////////////////////////////////////////////////////////
        /// \fn     setFadeBreakPoint
        /// \brief  Specifies a break point for the next fade.
        /// \param  opacity Opacity to stop fading at
        /// \note   Remove the breakpoint via removeFadeBreakPoint.
        /// 
        ///////////////////////////////////////////////////////////
        void setFadeBreakPoint(QFloat opacity);
        
        ///////////////////////////////////////////////////////////
        /// \fn     removeFadeBreakPoint
        /// \brief  Removes the break point previously specified.
        /// 
        ///////////////////////////////////////////////////////////
        void removeFadeBreakPoint();
        
        ///////////////////////////////////////////////////////////
        /// \fn     stopFading
        /// \brief  Stops fading the object manually.
        /// 
        ///////////////////////////////////////////////////////////
        void stopFading();
        
        
    protected:
        
        ///////////////////////////////////////////////////////////
        /// \fn     updateFade
        /// \brief  Updates the opacity value.
        /// \param  deltaTime Time between last and current update.
        /// 
        ///////////////////////////////////////////////////////////
        void updateFade(double deltaTime);
        
        ///////////////////////////////////////////////////////////
        // Protected class members
        //
        ///////////////////////////////////////////////////////////
        QFloat m_Opacity;           ///< Current object's opacity
        
        
    private:
        
        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QDouble m_ElapsedTime;      ///< Sums up the delta times
        QFloat m_Speed;             ///< Adding/removal speed
        QFloat m_BreakPoint;        ///< Opacity to break at
        QUInt32 m_Mode;             ///< Fading mode
        QUInt32 m_InitialMode;      ///< Initial fading mode (hack for 'pulse')
        QBool m_IsFading;           ///< Is object currently fading?
        
    };
    
    
    #define IFADABLE_UPDATE_INTERVAL 0.016666666666667
    #define IFADABLE_FADE_IN    0
    #define IFADABLE_FADE_OUT   1
    #define IFADABLE_FADE_PULSE 2
}


#endif  // __Q2D_IFADABLE_HPP__
