void BoundingSphere::Encapsulate(const AZ::Vector3& v)
    {
        // calculate the squared distance from the center to the point
        const AZ::Vector3 diff = v - m_center;
        const float dist = diff.Dot(diff);

        // if the current sphere doesn't contain the point, grow the sphere so that it contains the point
        if (dist > m_radiusSq)
        {
            const AZ::Vector3 diff2 = diff.GetNormalized() * m_radius;
            const AZ::Vector3 delta = 0.5f * (diff - diff2);
            m_center             += delta;
            // TODO: KB- Was a 'safe' function, is there an AZ equivalent?
            float length = delta.GetLengthSq();
            if (length >= FLT_EPSILON)
            {
                m_radius += sqrtf(length);
            }
            else
            {
                m_radius = 0.0f;
            }
            m_radiusSq = m_radius * m_radius;
        }
    }