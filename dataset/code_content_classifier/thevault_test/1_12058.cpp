AZ::SceneAPI::Events::ProcessingResult LoadingTrackingProcessor::PrepareForAssetLoading(AZ::SceneAPI::Containers::Scene& /*scene*/,
        RequestingApplication /*requester*/)
    {
        AZ_TracePrintf(AZ::SceneAPI::Utilities::LogWindow, "Preparing to load a scene.");
        // This function doesn't contribute anything to the loading, so let the SceneAPI know that it can ignore its contributions.
        return AZ::SceneAPI::Events::ProcessingResult::Ignored;
    }