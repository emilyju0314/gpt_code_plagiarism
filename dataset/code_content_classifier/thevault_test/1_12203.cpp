void OrthographicCamera::Update(float timeDelta)
    {
        if (m_flightActive)
        {
            m_flightCurrentTime += timeDelta;

            const float normalizedTime      = m_flightCurrentTime / m_flightMaxTime;
            const float interpolatedTime    = MCore::CosineInterpolate<float>(0.0f, 1.0f, normalizedTime);

            m_position           = m_flightSourcePosition + (m_flightTargetPosition - m_flightSourcePosition) * interpolatedTime;
            m_currentDistance    = m_flightSourceDistance + (m_flightTargetDistance - m_flightSourceDistance) * interpolatedTime;

            if (m_flightCurrentTime >= m_flightMaxTime)
            {
                m_flightActive       = false;
                m_position           = m_flightTargetPosition;
                m_currentDistance    = m_flightTargetDistance;
            }
        }

        // HACK TODO REMOVEME !!!
        const float scale = 1.0f;
        m_currentDistance *= scale;

        if (m_currentDistance <= m_minDistance * scale)
        {
            m_currentDistance = m_minDistance * scale;
        }

        if (m_currentDistance >= m_maxDistance * scale)
        {
            m_currentDistance = m_maxDistance * scale;
        }

        // fake zoom the orthographic camera
        const float orthoScale  = scale * 0.001f;
        const float deltaX      = m_currentDistance * m_screenWidth * orthoScale;
        const float deltaY      = m_currentDistance * m_screenHeight * orthoScale;
        SetOrthoClipDimensions(AZ::Vector2(deltaX, deltaY));

        // adjust the mouse delta movement so that one pixel mouse movement is exactly one pixel on screen
        m_positionDelta.SetX(m_positionDelta.GetX() * m_currentDistance * orthoScale);
        m_positionDelta.SetY(m_positionDelta.GetY() * m_currentDistance * orthoScale);

        AZ::Vector3 xAxis, yAxis, zAxis;
        switch (m_mode)
        {
        case VIEWMODE_FRONT:
        {
            xAxis = AZ::Vector3(-1.0f, 0.0f, 0.0f);      // screen x axis
            yAxis = AZ::Vector3(0.0f, 0.0f, 1.0f);       // screen y axis
            zAxis = AZ::Vector3(0.0f, 1.0f, 0.0f);       // depth axis

            // translate the camera
            m_position += xAxis * -m_positionDelta.GetX();
            m_position += yAxis * m_positionDelta.GetY();

            // setup the view matrix
            MCore::LookAtRH(m_viewMatrix, m_position + zAxis * m_currentDistance, m_position, yAxis);
            break;
        }

        case VIEWMODE_BACK:
        {
            xAxis = AZ::Vector3(1.0f, 0.0f, 0.0f);       // screen x axis
            yAxis = AZ::Vector3(0.0f, 0.0f, 1.0f);       // screen y axis
            zAxis = AZ::Vector3(0.0f, -1.0f, 0.0f);      // depth axis

            // translate the camera
            m_position += xAxis * -m_positionDelta.GetX();
            m_position += yAxis * m_positionDelta.GetY();

            // setup the view matrix
            MCore::LookAtRH(m_viewMatrix, m_position + zAxis * m_currentDistance, m_position, yAxis);
            break;
        }


        case VIEWMODE_LEFT:
        {
            xAxis = AZ::Vector3(0.0f, 1.0f, 0.0f);       // screen x axis
            yAxis = AZ::Vector3(0.0f, 0.0f, 1.0f);       // screen y axis
            zAxis = AZ::Vector3(-1.0f, 0.0f, 0.0f);      // depth axis

            // translate the camera
            m_position += xAxis * m_positionDelta.GetX();
            m_position += yAxis * m_positionDelta.GetY();

            // setup the view matrix
            MCore::LookAtRH(m_viewMatrix, m_position + zAxis * m_currentDistance, m_position, yAxis);
            break;
        }

        case VIEWMODE_RIGHT:
        {
            xAxis = AZ::Vector3(0.0f, -1.0f, 0.0f);      // screen x axis
            yAxis = AZ::Vector3(0.0f, 0.0f, 1.0f);       // screen y axis
            zAxis = AZ::Vector3(1.0f, 0.0f, 0.0f);       // depth axis

            // translate the camera
            m_position += xAxis * m_positionDelta.GetX();
            m_position += yAxis * m_positionDelta.GetY();

            // setup the view matrix
            MCore::LookAtRH(m_viewMatrix, m_position + zAxis * m_currentDistance, m_position, yAxis);
            break;
        }

        case VIEWMODE_TOP:
        {
            xAxis = AZ::Vector3(1.0f, 0.0f, 0.0f);       // screen x axis
            yAxis = AZ::Vector3(0.0f, 1.0f, 0.0f);       // screen y axis
            zAxis = AZ::Vector3(0.0f, 0.0f, 1.0f);       // depth axis

            // translate the camera
            m_position += -xAxis* m_positionDelta.GetX();
            m_position += yAxis * m_positionDelta.GetY();

            // setup the view matrix
            MCore::LookAtRH(m_viewMatrix, m_position + zAxis * m_currentDistance, m_position, yAxis);
            break;
        }

        case VIEWMODE_BOTTOM:
        {
            xAxis = AZ::Vector3(-1.0f, 0.0f, 0.0f);       // screen x axis
            yAxis = AZ::Vector3(0.0f, 1.0f, 0.0f);        // screen y axis
            zAxis = AZ::Vector3(0.0f, 0.0f, -1.0f);       // depth axis

            // translate the camera
            m_position += -xAxis* m_positionDelta.GetX();
            m_position += yAxis * m_positionDelta.GetY();

            // setup the view matrix
            MCore::LookAtRH(m_viewMatrix, m_position + zAxis * m_currentDistance, m_position, yAxis);
            break;
        }
        }
        ;

        // reset the position delta
        m_positionDelta = AZ::Vector2(0.0f, 0.0f);

        // update our base camera
        Camera::Update();
    }