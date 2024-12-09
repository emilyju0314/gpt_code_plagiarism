void ConstraintTransformRotationAngles::Execute()
    {
        AZ::Quaternion q = m_transform.m_rotation;

        // Always keep w positive.
        if (q.GetW() < 0.0f)
        {
            q = -q;
        }

        // Get the axes indices for swing
        uint32 swingX;
        uint32 swingY;
        switch (m_twistAxis)
        {
            // Twist is the X-axis.
            case AXIS_X:
                swingX = 2;
                swingY = 1;
                break;

            // Twist is the Y-axis.
            case AXIS_Y:
                swingX = 2;
                swingY = 0;
                break;

            // Twist is the Z-axis.
            case AXIS_Z:
                swingX = 1;
                swingY = 0;
                break;

            default:
                MCORE_ASSERT(false);
                swingX = 2;
                swingY = 0;
        }

        // Calculate the twist quaternion, based on over which axis we assume there is twist.
        AZ::Quaternion twist;
        const float twistAngle = q.GetElement(m_twistAxis);
        const float s = twistAngle * twistAngle + q.GetW() * q.GetW();
        if (!MCore::Math::IsFloatZero(s))
        {
            const float r = MCore::Math::InvSqrt(s);
            twist.SetElement(swingX, 0.0f);
            twist.SetElement(swingY, 0.0f);
            twist.SetElement(m_twistAxis, MCore::Clamp(twistAngle * r, m_minTwist, m_maxTwist));
            twist.SetW(MCore::Math::Sqrt(MCore::Max<float>(0.0f, 1.0f - twist.GetElement(m_twistAxis) * twist.GetElement(m_twistAxis))));
        }
        else
        {
            twist = AZ::Quaternion::CreateIdentity();
        }

        // Remove the twist from the input rotation so that we are left with a swing and then limit the swing.
        AZ::Quaternion swing = q * twist.GetConjugate();
        swing.SetElement(swingX, MCore::Clamp(static_cast<float>(swing.GetElement(swingX)), m_minRotationAngles.GetX(), m_maxRotationAngles.GetX()));
        swing.SetElement(swingY, MCore::Clamp(static_cast<float>(swing.GetElement(swingY)), m_minRotationAngles.GetY(), m_maxRotationAngles.GetY()));
        swing.SetElement(m_twistAxis, 0.0f);
        swing.SetW(MCore::Math::Sqrt(MCore::Max<float>(0.0f, 1.0f - swing.GetElement(swingX) * swing.GetElement(swingX) - swing.GetElement(swingY) * swing.GetElement(swingY))));

        // Combine the limited swing and twist again into a final rotation.
        m_transform.m_rotation = swing * twist;
    }