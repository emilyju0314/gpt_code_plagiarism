void OrthographicCamera::ViewCloseup(const MCore::AABB& boundingBox, float flightTime)
    {
        m_flightMaxTime          = flightTime;
        m_flightCurrentTime      = 0.0f;
        m_flightSourceDistance   = m_currentDistance;
        m_flightSourcePosition   = m_position;

        float boxWidth = 0.0f;
        float boxHeight = 0.0f;
        switch (m_mode)
        {
        case VIEWMODE_FRONT:
        {
            boxWidth = boundingBox.CalcWidth();
            boxHeight = boundingBox.CalcHeight();
            break;
        }
        case VIEWMODE_BACK:
        {
            boxWidth = boundingBox.CalcWidth();
            boxHeight = boundingBox.CalcHeight();
            break;
        }
        case VIEWMODE_LEFT:
        {
            boxWidth = boundingBox.CalcDepth();
            boxHeight = boundingBox.CalcHeight();
            break;
        }
        case VIEWMODE_RIGHT:
        {
            boxWidth = boundingBox.CalcDepth();
            boxHeight = boundingBox.CalcHeight();
            break;
        }
        case VIEWMODE_TOP:
        {
            boxWidth = boundingBox.CalcWidth();
            boxHeight = boundingBox.CalcDepth();
            break;
        }
        case VIEWMODE_BOTTOM:
        {
            boxWidth = boundingBox.CalcWidth();
            boxHeight = boundingBox.CalcDepth();
            break;
        }
        }
        ;

        const float orthoScale  = 0.001f;
        assert(m_screenWidth != 0 && m_screenHeight != 0);
        const float distanceX = (boxWidth) / (m_screenWidth * orthoScale);
        const float distanceY = (boxHeight) / (m_screenHeight * orthoScale);
        //LOG("box: x=%f y=%f, boxAspect=%f, orthoAspect=%f, distX=%f, distY=%f", boxWidth, boxHeight, boxAspect, orthoAspect, distanceX, distanceY);

        if (flightTime < MCore::Math::epsilon)
        {
            m_flightActive           = false;
            m_currentDistance        = MCore::Max(distanceX, distanceY) * 1.1f;
            m_position               = boundingBox.CalcMiddle();
        }
        else
        {
            m_flightActive           = true;
            m_flightTargetDistance = MCore::Max(distanceX, distanceY) * 1.1f;
            m_flightTargetPosition = boundingBox.CalcMiddle();
        }

        // make sure the target flight distance is in range
        if (m_flightTargetDistance < m_minDistance)
        {
            m_flightTargetDistance = m_minDistance;
        }
        if (m_flightTargetDistance > m_maxDistance)
        {
            m_flightTargetDistance = m_maxDistance;
        }
    }