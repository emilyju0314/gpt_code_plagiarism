TEST(ViewportScreen, ScreenNdcToWorldReturnsPositionOnNearClipPlaneInWorldSpace)
    {
        using NdcPoint = AZ::Vector2;

        const auto screenDimensions = AZ::Vector2(800.0f, 600.0f);
        const auto cameraTransform =
            AZ::Transform::CreateTranslation(AZ::Vector3(10.0f, 0.0f, 0.0f)) * AZ::Transform::CreateRotationZ(AZ::DegToRad(-90.0f));

        const auto cameraState = AzFramework::CreateDefaultCamera(cameraTransform, screenDimensions);

        const auto worldResult =
            AzFramework::ScreenNdcToWorld(NdcPoint{ 0.5f, 0.5f }, InverseCameraView(cameraState), InverseCameraProjection(cameraState));
        EXPECT_THAT(worldResult, IsClose(AZ::Vector3(10.1f, 0.0f, 0.0f)));
    }