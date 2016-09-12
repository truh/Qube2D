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
#include <Qube2D/Assets/Assets.hpp>
#include <Qube2D/Graphics/Animation.hpp>
#include <Qube2D/Graphics/System/GraphicsErrors.hpp>
#include <cstring>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      Default constructor
    ///
    ///////////////////////////////////////////////////////////
    Animation::Animation()
        : ISprite(),
          Object(),
          m_ElapsedTimeA(0.0),
          m_CurrentFrame(0),
          m_FrameCount(0)
    {
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      load
    ///
    ///////////////////////////////////////////////////////////
    bool Animation::load(const char *path)
    {
        assert(path);


        // Determines whether the given path is relative or absolute
        // and converts the relative to an absolute eventually.
        std::string filePath = path;
        if (Assets::isRelative(path))
            filePath = Assets::makePath(path);


        // Creates a new file handle
        File file;
        if (!file.open(path, FA_Read))
        {
            Q2DError(Q2D_ANIM_ERROR_0, filePath.c_str());
            return false;
        }

        QUInt8 *magic = file.readBytes(10);

        // Attempts to parse the header
        if (memcmp(magic, ANIMATION_MAGIC, 10))
        {
            Q2DError(Q2D_ANIM_ERROR_1, filePath.c_str());
            delete magic;
            return false;
        }

        delete magic;

        QUInt8 major = file.readByte();
        QUInt8 minor = file.readByte();
        m_FrameCount = file.readUInt32();
        m_FrameWidth = file.readUInt16();
        m_FrameHeight = file.readUInt16();

        // Attempts to parse the frame-table
        for (QUInt32 i = 0; i < m_FrameCount; i++)
        {
            if (major == 1 && minor == 0)
            {
                Frame frame;
                frame.disp_duration = file.readUInt16();
                frame.halt_duration = file.readUInt16();

                if (frame.disp_duration == 0)
                {
                    Q2DError(Q2D_ANIM_ERROR_2, filePath.c_str());
                    return false;
                }

                m_Frames.push_back(frame);
            }
        }


        // Attempts to read and load the PNG image
        QUInt32 size = file.size();
        QUInt32 pos = static_cast<QUInt32>(file.position());
        QUInt8 *png = file.readBytes(size - pos);

        if (!m_Texture.createFromMemory(png, size - pos))
        {
            Q2DError(Q2D_ANIM_ERROR_3, filePath.c_str());
            delete png;
            return false;
        }


        // Pre-calculates the UV coordinates for all frames
        QFloat imgWid = m_Texture.width();
        QFloat imgHei = m_Texture.height();
        QInt32 columns = static_cast<int>(imgWid / m_FrameWidth);
        QInt32 rows = static_cast<int>(imgHei / m_FrameHeight);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                m_FrameUV.push_back(
                {
                    (m_FrameWidth  * j) / imgWid,
                    (m_FrameHeight * i) / imgHei
                });
            }
        }

        m_FrameWidRel = m_FrameWidth / imgWid;
        m_FrameHeiRel = m_FrameHeight / imgHei;


        // Modifies the texture and pre-calculates vertex data
        m_Texture.bind();
        m_Texture.setMinFilter(InterpolationMode::NearestNeighbor);
        m_Texture.setMagFilter(InterpolationMode::NearestNeighbor);
        setRotationOrigin(m_Texture.width()/2, m_Texture.height()/2);
        setBlendColor(Color(255, 255, 255, 255));

        delete png;
        return true;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      startAnimation
    ///
    ///////////////////////////////////////////////////////////
    void Animation::startAnimation()
    {
        m_CurrentFrame = 0;
        m_ElapsedTimeA = 0.0;
        m_IsAnimating = true;
        m_UpdateInterval = m_Frames.at(0).disp_duration;

        // Modifies vertex data to match the first anim step
        float rel_x = m_FrameUV.at(0).x();
        float rel_y = m_FrameUV.at(0).y();
        float rel_w = rel_x + m_FrameWidRel;
        float rel_h = rel_y + m_FrameHeiRel;

        // Modifies the vertex-pos data
        m_Vertices.v0.xy(0.f, 0.f);
        m_Vertices.v1.xy(m_FrameWidth, 0.f);
        m_Vertices.v2.xy(m_FrameWidth, m_FrameHeight);
        m_Vertices.v3.xy(0.f, m_FrameHeight);

        // Modifies the tex-coord data
        m_Vertices.v0.uv(rel_x, rel_y);
        m_Vertices.v1.uv(rel_w, rel_y);
        m_Vertices.v2.uv(rel_w, rel_h);
        m_Vertices.v3.uv(rel_x, rel_h);
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      stopAnimation
    ///
    ///////////////////////////////////////////////////////////
    void Animation::stopAnimation()
    {
        m_IsAnimating = false;
    }


    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      update
    ///
    ///////////////////////////////////////////////////////////
    void Animation::update(double deltaTime)
    {
        ISprite::update(deltaTime);

        if (!m_IsAnimating)
            return;

        m_ElapsedTimeA += (deltaTime * 1000);

        if (m_ElapsedTimeA < m_UpdateInterval)
            return;

        m_ElapsedTimeA = 0.0;

        // Determines whether there is a halt-interval
        QUInt16 halt_int = m_Frames.at(m_CurrentFrame).halt_duration;

        if (!m_IsHalting && halt_int != 0)
        {
            m_IsHalting = true;
            m_UpdateInterval = static_cast<double>(halt_int);
        }
        else
        {
            if (++m_CurrentFrame == m_FrameCount)
                  m_CurrentFrame = 0;

            m_IsHalting = false;
            m_UpdateInterval = static_cast<double>(m_Frames.at(m_CurrentFrame).disp_duration);

            // Updates the UV data
            float rel_x = m_FrameUV.at(m_CurrentFrame).x();
            float rel_y = m_FrameUV.at(m_CurrentFrame).y();
            float rel_w = rel_x + m_FrameWidRel;
            float rel_h = rel_y + m_FrameHeiRel;

            m_Vertices.v0.uv(rel_x, rel_y);
            m_Vertices.v1.uv(rel_w, rel_y);
            m_Vertices.v2.uv(rel_w, rel_h);
            m_Vertices.v3.uv(rel_x, rel_h);
        }
    }

    ///////////////////////////////////////////////////////////
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    September 12th, 2016
    /// \fn      render
    ///
    ///////////////////////////////////////////////////////////
    void Animation::render()
    {
        if (!m_IsHalting)
            ISprite::render();
    }
}
