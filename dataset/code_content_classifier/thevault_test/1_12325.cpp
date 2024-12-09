void RotateManipulator::UpdateBoundingVolumes(MCommon::Camera* camera)
    {
        MCORE_UNUSED(camera);

        // adjust the m_size when in ortho mode
        m_size           = m_scalingFactor;
        m_innerRadius    = 0.15f * m_size;
        m_outerRadius    = 0.2f * m_size;
        m_arrowBaseRadius = m_innerRadius / 70.0f;
        m_aabbWidth      = m_innerRadius / 30.0f;// previous 70.0f
        m_axisSize       = m_size * 0.05f;
        m_textDistance   = m_size * 0.05f;
        m_innerQuadSize  = 0.45f * MCore::Math::Sqrt(2) * m_innerRadius;

        // set the bounding volumes of the axes selection
        m_xAxisAabb.SetMax(m_position + AZ::Vector3(m_aabbWidth, m_innerRadius, m_innerRadius));
        m_xAxisAabb.SetMin(m_position - AZ::Vector3(m_aabbWidth, m_innerRadius, m_innerRadius));
        m_yAxisAabb.SetMax(m_position + AZ::Vector3(m_innerRadius, m_aabbWidth, m_innerRadius));
        m_yAxisAabb.SetMin(m_position - AZ::Vector3(m_innerRadius, m_aabbWidth, m_innerRadius));
        m_zAxisAabb.SetMax(m_position + AZ::Vector3(m_innerRadius, m_innerRadius, m_aabbWidth));
        m_zAxisAabb.SetMin(m_position - AZ::Vector3(m_innerRadius, m_innerRadius, m_aabbWidth));
        m_xAxisInnerAabb.SetMax(m_position + AZ::Vector3(m_aabbWidth, m_innerQuadSize, m_innerQuadSize));
        m_xAxisInnerAabb.SetMin(m_position - AZ::Vector3(m_aabbWidth, m_innerQuadSize, m_innerQuadSize));
        m_yAxisInnerAabb.SetMax(m_position + AZ::Vector3(m_innerQuadSize, m_aabbWidth, m_innerQuadSize));
        m_yAxisInnerAabb.SetMin(m_position - AZ::Vector3(m_innerQuadSize, m_aabbWidth, m_innerQuadSize));
        m_zAxisInnerAabb.SetMax(m_position + AZ::Vector3(m_innerQuadSize, m_innerQuadSize, m_aabbWidth));
        m_zAxisInnerAabb.SetMin(m_position - AZ::Vector3(m_innerQuadSize, m_innerQuadSize, m_aabbWidth));

        // set the bounding spheres for inner and outer circle modifiers
        m_innerBoundingSphere.SetCenter(m_position);
        m_innerBoundingSphere.SetRadius(m_innerRadius);
        m_outerBoundingSphere.SetCenter(m_position);
        m_outerBoundingSphere.SetRadius(m_outerRadius);
    }