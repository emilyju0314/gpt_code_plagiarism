bool BoundingSphere::Contains(const AABB& b) const
    {
        float distance = 0.0f;
        for (int32_t t = 0; t < 3; ++t)
        {
            const AZ::Vector3& maxVec = b.GetMax();
            if (m_center.GetElement(t) < maxVec.GetElement(t))
            {
                distance += (m_center.GetElement(t) - maxVec.GetElement(t)) * (m_center.GetElement(t) - maxVec.GetElement(t));
            }
            else
            {
                const AZ::Vector3& minVec = b.GetMin();
                if (m_center.GetElement(t) > minVec.GetElement(t))
                {
                    distance += (m_center.GetElement(t) - minVec.GetElement(t)) * (m_center.GetElement(t) - minVec.GetElement(t));
                }
            }

            if (distance > m_radiusSq)
            {
                return false;
            }
        }

        return true;
    }