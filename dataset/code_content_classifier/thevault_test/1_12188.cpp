void FirstPersonCamera::Update(float timeDelta)
    {
        MCORE_UNUSED(timeDelta);

        // lock pitching to [-90.0°, 90.0°]
        if (m_pitch < -90.0f + 0.1f)
        {
            m_pitch = -90.0f + 0.1f;
        }
        if (m_pitch >  90.0f - 0.1f)
        {
            m_pitch =  90.0f - 0.1f;
        }

        // calculate the camera direction vector based on the yaw and pitch
        AZ::Vector3 direction = (AZ::Matrix4x4::CreateRotationX(MCore::Math::DegreesToRadians(m_pitch)) * AZ::Matrix4x4::CreateRotationY(MCore::Math::DegreesToRadians(m_yaw))) * (AZ::Vector3(0.0f, 0.0f, 1.0f)).GetNormalized();

        // look from the camera position into the newly calculated direction
        MCore::LookAt(m_viewMatrix, m_position, m_position + direction * 10.0f, AZ::Vector3(0.0f, 1.0f, 0.0f));

        // update our base camera
        Camera::Update();
    }