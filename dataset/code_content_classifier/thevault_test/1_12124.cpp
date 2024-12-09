AZ::Quaternion GetQuaternionFromRotation(Rotation rotation)
    {
        static const AZ::Quaternion qXAxis = AZ::Quaternion::CreateFromAxisAngle(AZ::Vector3::CreateAxisX(), 45);
        static const AZ::Quaternion qZAxis = AZ::Quaternion::CreateFromAxisAngle(AZ::Vector3::CreateAxisZ(), 45);
        static const AZ::Quaternion qXZAxis = qXAxis + qZAxis;

        switch (rotation)
        {
        case Rotation::Identity:
            return AZ::Quaternion::CreateIdentity();
        case Rotation::XAxis:
            return qXAxis;
        case Rotation::ZAxis:
            return qZAxis;
        case Rotation::XZAxis:
            return qXZAxis;
        default:
            return AZ::Quaternion::CreateIdentity();
        }
    }