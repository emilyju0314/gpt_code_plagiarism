AZ::SceneAPI::Events::LoadingResult LoadingTrackingProcessor::LoadAsset(AZ::SceneAPI::Containers::Scene& /*scene*/,
        [[maybe_unused]] const AZStd::string& path, const AZ::Uuid& /*guid*/, RequestingApplication /*requester*/)
    {
        AZ_TracePrintf(AZ::SceneAPI::Utilities::LogWindow, "Loading scene from '%s'.", path.c_str());
        return AZ::SceneAPI::Events::LoadingResult::Ignored;
    }