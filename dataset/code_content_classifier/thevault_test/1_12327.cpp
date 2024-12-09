void RotateManipulator::UpdateAxisDirections(Camera* camera)
    {
        // check if the camera exists
        if (camera == nullptr)
        {
            return;
        }

        // get camera dimensions
        const uint32 screenWidth    = camera->GetScreenWidth();
        const uint32 screenHeight   = camera->GetScreenHeight();

        // shoot ray to the camera center
        MCore::Ray camRay = camera->Unproject(screenWidth / 2, screenHeight / 2);
        AZ::Vector3 camDir = camRay.GetDirection();

        m_signX = (MCore::Math::ACos(camDir.Dot(AZ::Vector3(1.0f, 0.0f, 0.0f))) >= MCore::Math::halfPi) ? 1.0f : -1.0f;
        m_signY = (MCore::Math::ACos(camDir.Dot(AZ::Vector3(0.0f, 1.0f, 0.0f))) >= MCore::Math::halfPi) ? 1.0f : -1.0f;
        m_signZ = (MCore::Math::ACos(camDir.Dot(AZ::Vector3(0.0f, 0.0f, 1.0f))) >= MCore::Math::halfPi) ? 1.0f : -1.0f;

        // determine the axis visibility, to disable movement for invisible axes
        m_xAxisVisible = (MCore::InRange(MCore::Math::Abs(camDir.Dot(AZ::Vector3(1.0f, 0.0f, 0.0f))) - 1.0f, -MCore::Math::epsilon, MCore::Math::epsilon) == false);
        m_yAxisVisible = (MCore::InRange(MCore::Math::Abs(camDir.Dot(AZ::Vector3(0.0f, 1.0f, 0.0f))) - 1.0f, -MCore::Math::epsilon, MCore::Math::epsilon) == false);
        m_zAxisVisible = (MCore::InRange(MCore::Math::Abs(camDir.Dot(AZ::Vector3(0.0f, 0.0f, 1.0f))) - 1.0f, -MCore::Math::epsilon, MCore::Math::epsilon) == false);

        // update the bounding volumes
        UpdateBoundingVolumes();
    }