Actor::EAxis Actor::FindBestMatchingMotionExtractionAxis() const
    {
        MCORE_ASSERT(m_motionExtractionNode != InvalidIndex);
        if (m_motionExtractionNode == InvalidIndex)
        {
            return AXIS_Y;
        }

        // Get the local space rotation matrix of the motion extraction node.
        const Transform& localTransform = GetBindPose()->GetLocalSpaceTransform(m_motionExtractionNode);
        const AZ::Matrix3x3 rotationMatrix = AZ::Matrix3x3::CreateFromQuaternion(localTransform.m_rotation);

        // Calculate angles between the up axis and each of the rotation's basis vectors.
        const AZ::Vector3 globalUpAxis(0.0f, 0.0f, 1.0f);
        const float dotX = rotationMatrix.GetRow(0).Dot(globalUpAxis);
        const float dotY = rotationMatrix.GetRow(1).Dot(globalUpAxis);
        const float dotZ = rotationMatrix.GetRow(2).Dot(globalUpAxis);

        const float difX = 1.0f - MCore::Clamp(MCore::Math::Abs(dotX), 0.0f, 1.0f);
        const float difY = 1.0f - MCore::Clamp(MCore::Math::Abs(dotY), 0.0f, 1.0f);
        const float difZ = 1.0f - MCore::Clamp(MCore::Math::Abs(dotZ), 0.0f, 1.0f);

        // Pick the axis which has the smallest angle difference.
        if (difX <= difY && difY <= difZ)
        {
            return AXIS_X;
        }
        else if (difY <= difX && difX <= difZ)
        {
            return AXIS_Y;
        }
        else
        {
            return AXIS_Z;
        }
    }