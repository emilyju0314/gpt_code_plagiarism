static AZ::Matrix3x4 ZYCoordinateSystemConversion()
    {
        // note: the below matrix is the result of these combined transformations
        //      pitch = AZ::Matrix4x4::CreateRotationX(AZ::DegToRad(-90.0f));
        //      yaw = AZ::Matrix4x4::CreateRotationZ(AZ::DegToRad(180.0f));
        //      conversion = pitch * yaw
        return AZ::Matrix3x4::CreateFromColumns(
            AZ::Vector3(-1.0f, 0.0f, 0.0f), AZ::Vector3(0.0f, 0.0f, 1.0f), AZ::Vector3(0.0f, 1.0f, 0.0f), AZ::Vector3(0.0f, 0.0f, 0.0f));
    }