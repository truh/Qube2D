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


#ifndef __Q2D_ITRANSFORMABLE_HPP__
#define __Q2D_ITRANSFORMABLE_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/Graphics/System/Base/BaseEnums.hpp>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    ITransformable.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 5th, 2016
    /// \class   ITransformable
    /// \brief   Allows rotating and scaling an object.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API ITransformable
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of ITransformable.
        ///
        ///////////////////////////////////////////////////////////
        ITransformable();


        ///////////////////////////////////////////////////////////
        /// \fn       angle
        /// \brief    Retrieves the current angle of the object.
        /// \returns  the object's angle, in degrees.
        ///
        ///////////////////////////////////////////////////////////
        QFloat angle() const;

        ///////////////////////////////////////////////////////////
        /// \fn       scale
        /// \brief    Retrieves the scaling of the object.
        /// \returns  the object's scale, relatively.
        ///
        ///////////////////////////////////////////////////////////
        QFloat scale() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isRotating
        /// \brief    Determines whether the object is rotating.
        /// \returns  TRUE if the object is rotating.
        ///
        ///////////////////////////////////////////////////////////
        QBool isRotating() const;

        ///////////////////////////////////////////////////////////
        /// \fn       isScaling
        /// \brief    Determines whether the object is scaling.
        /// \returns  TRUE if the object is scaling.
        ///
        ///////////////////////////////////////////////////////////
        QBool isScaling() const;


        ///////////////////////////////////////////////////////////
        /// \fn     setRotation
        /// \brief  Specifies the rotation angle of the object.
        /// \param  angle Rotation angle, in degrees
        ///
        ///////////////////////////////////////////////////////////
        void setRotation(QFloat angle);

        ///////////////////////////////////////////////////////////
        /// \fn      setScale
        /// \brief   Specifies the scaling of the object.
        /// \param   scale The scale factor
        /// \default 1.0, does not scale the object
        ///
        ///////////////////////////////////////////////////////////
        void setScale(QFloat scale);

        ///////////////////////////////////////////////////////////
        /// \fn     setRotationSpeed
        /// \brief  Specifies the speed while rotating.
        /// \param  speed Amount of degrees to rotate per update
        ///
        ///////////////////////////////////////////////////////////
        void setRotationSpeed(QFloat speed);

        ///////////////////////////////////////////////////////////
        /// \fn     setScalingSpeed
        /// \brief  Specifies the speed while scaling.
        /// \param  speed Factor to add per update
        ///
        ///////////////////////////////////////////////////////////
        void setScalingSpeed(QFloat speed);

        ///////////////////////////////////////////////////////////
        /// \fn     setOrigin
        /// \brief  Specifies the point to rotate/scale the object.
        /// \param  x Origin X-position
        /// \parama y Origin Y-position
        ///
        ///////////////////////////////////////////////////////////
        void setOrigin(QFloat x, QFloat y);


        ///////////////////////////////////////////////////////////
        /// \fn     startRotation
        /// \brief  Rotates the object by the given angle.
        /// \param  angle Amount of degrees to rotate object
        /// \param  dir Direction to rotate in
        ///
        ///////////////////////////////////////////////////////////
        void startRotation(QFloat angle, RotateDirection dir);

        ///////////////////////////////////////////////////////////
        /// \fn     startScaling
        /// \brief  Scales the object to the given scaling factor.
        /// \param  factor Target scaling factor
        ///
        ///////////////////////////////////////////////////////////
        void startScaling(QFloat factor);

        ///////////////////////////////////////////////////////////
        /// \fn     stopRotation
        /// \brief  Stops rotating the object.
        ///
        ///////////////////////////////////////////////////////////
        void stopRotation();

        ///////////////////////////////////////////////////////////
        /// \fn     stopScaling
        /// \brief  Stops scaling the object.
        ///
        ///////////////////////////////////////////////////////////
        void stopScaling();


    protected:

        ///////////////////////////////////////////////////////////
        /// \fn     updateRotation
        /// \brief  Updates the object's rotation angle.
        /// \param  deltaTime Time between last and current update
        ///
        ///////////////////////////////////////////////////////////
        void updateRotation(double deltaTime);

        ///////////////////////////////////////////////////////////
        /// \fn     updateScaling
        /// \brief  Updates the object's scaling factor.
        /// \param  deltaTime Time between last and current update
        ///
        ///////////////////////////////////////////////////////////
        void updateScaling(double deltaTime);


        ///////////////////////////////////////////////////////////
        // Protected class members
        //
        ///////////////////////////////////////////////////////////
        QFloat m_Angle;             ///< Current rotation angle
        QFloat m_Scale;             ///< Current scaling factor
        QFloat m_OriginX;           ///< Origin X-position
        QFloat m_OriginY;           ///< Origin Y-position


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QDouble m_ElapsedTimeR;     ///< Delta time counter (rot)
        QDouble m_ElapsedTimeS;     ///< Delta time counter (scale)
        QBool m_IsRotating;         ///< Is currently rotating?
        QBool m_IsScaling;          ///< Is currently scaling?
        QFloat m_SpeedRotation;     ///< Rotation speed
        QFloat m_SpeedScaling;      ///< Scaling speed
        QFloat m_TargetRotation;    ///< Desired rotation angle
        QFloat m_TargetScaling;     ///< Desired scaling factor
        QUInt32 m_RotateDirection;  ///< Rotation direction
        QUInt32 m_ScaleDirection;   ///< Scaling direction

    };


    #define ITRANSFORMABLE_UPDATE_INTERVAL 0.010
    #define ITRANSFORMABLE_ROTDIR_CW    0
    #define ITRANSFORMABLE_ROTDIR_CCW   1
    #define ITRANSFORMABLE_SCALEDIR_UP  0
    #define ITRANSFORMABLE_SCALEDIR_DN  1
}


#endif  // __Q2D_ITRANSFORMABLE_HPP__
