AZ::SceneAPI::Events::ProcessingResult LoadingTrackingProcessor::UpdateManifest(AZ::SceneAPI::Containers::Scene& /*scene*/, ManifestAction action,
        RequestingApplication /*requester*/)
    {
        switch (action)
        {
        case ManifestAction::ConstructDefault:
            AZ_TracePrintf(AZ::SceneAPI::Utilities::LogWindow, "Constructing a new manifest.");
            break;
        case ManifestAction::Update:
            AZ_TracePrintf(AZ::SceneAPI::Utilities::LogWindow, "Updating the manifest.");
            break;
        default:
            AZ_TracePrintf(AZ::SceneAPI::Utilities::WarningWindow, "Unknown manifest update action.");
            break;
        }
        return AZ::SceneAPI::Events::ProcessingResult::Ignored;
    }