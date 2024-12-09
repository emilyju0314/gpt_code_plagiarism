AZ::Transform DualQuaternion::ToTransform() const
    {
        const float sqLen   = m_real.Dot(m_real);
        const float x       = m_real.GetX();
        const float y       = m_real.GetY();
        const float z       = m_real.GetZ();
        const float w       = m_real.GetW();
        const float t0      = m_dual.GetW();
        const float t1      = m_dual.GetX();
        const float t2      = m_dual.GetY();
        const float t3      = m_dual.GetZ();

        AZ::Matrix3x3 matrix3x3;
        matrix3x3.SetElement(0, 0, w * w + x * x - y * y - z * z);
        matrix3x3.SetElement(0, 1, 2.0f * x * y - 2.0f * w * z);
        matrix3x3.SetElement(0, 2, 2.0f * x * z + 2.0f * w * y);
        matrix3x3.SetElement(1, 0, 2.0f * x * y + 2.0f * w * z);
        matrix3x3.SetElement(1, 1, w * w + y * y - x * x - z * z);
        matrix3x3.SetElement(1, 2, 2.0f * y * z - 2.0f * w * x);
        matrix3x3.SetElement(2, 0, 2.0f * x * z - 2.0f * w * y);
        matrix3x3.SetElement(2, 1, 2.0f * y * z + 2.0f * w * x);
        matrix3x3.SetElement(2, 2, w * w + z * z - x * x - y * y);

        AZ::Vector3 translation;
        translation.SetElement(0, -2.0f * t0 * x + 2.0f * w * t1 - 2.0f * t2 * z + 2.0f * y * t3);
        translation.SetElement(1, -2.0f * t0 * y + 2.0f * t1 * z - 2.0f * x * t3 + 2.0f * w * t2);
        translation.SetElement(2, -2.0f * t0 * z + 2.0f * x * t2 + 2.0f * w * t3 - 2.0f * t1 * y);

        const float invSqLen = 1.0f / sqLen;

        return AZ::Transform::CreateFromMatrix3x3AndTranslation(invSqLen * matrix3x3, invSqLen * translation);
    }