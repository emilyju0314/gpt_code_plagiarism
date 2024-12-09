AZ::Vector2 ScreenNdcToWorldToScreenNdc(const AZ::Vector2& ndcPoint, const AzFramework::CameraState& cameraState)
    {
        const auto worldResult =
            AzFramework::ScreenNdcToWorld(ndcPoint, InverseCameraView(cameraState), InverseCameraProjection(cameraState));
        const auto ndcResult = AzFramework::WorldToScreenNdc(worldResult, CameraView(cameraState), CameraProjection(cameraState));
        return AZ::Vector3ToVector2(ndcResult);
    }