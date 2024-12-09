void DualQuaternion::ToRotationTranslation(AZ::Quaternion* outRot, AZ::Vector3* outPos) const
    {
        const float invLength = 1.0f / m_real.GetLength();
        *outRot = m_real * invLength;
        outPos->Set(2.0f * (-m_dual.GetW() * m_real.GetX() + m_dual.GetX() * m_real.GetW() - m_dual.GetY() * m_real.GetZ() + m_dual.GetZ() * m_real.GetY()) * invLength,
            2.0f * (-m_dual.GetW() * m_real.GetY() + m_dual.GetX() * m_real.GetZ() + m_dual.GetY() * m_real.GetW() - m_dual.GetZ() * m_real.GetX()) * invLength,
            2.0f * (-m_dual.GetW() * m_real.GetZ() - m_dual.GetX() * m_real.GetY() + m_dual.GetY() * m_real.GetX() + m_dual.GetZ() * m_real.GetW()) * invLength);
    }