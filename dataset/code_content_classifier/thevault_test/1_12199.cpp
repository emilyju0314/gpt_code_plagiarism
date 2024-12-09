AzFramework::ScreenPoint ScreenToWorldToScreen(const AzFramework::ScreenPoint& screenPoint, const AzFramework::CameraState& cameraState)
    {
        const auto worldResult = AzFramework::ScreenToWorld(screenPoint, cameraState);
        return AzFramework::WorldToScreen(worldResult, cameraState);
    }