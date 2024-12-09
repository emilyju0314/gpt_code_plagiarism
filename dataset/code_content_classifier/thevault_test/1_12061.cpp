AZ::SceneAPI::Events::ProcessingResult LoadingTrackingProcessor::ContextCallback([[maybe_unused]] AZ::SceneAPI::Events::ICallContext& context)
    {
        AZ_TracePrintf(AZ::SceneAPI::Utilities::LogWindow, "LoadEvent: %s", context.RTTI_GetTypeName());
        return AZ::SceneAPI::Events::ProcessingResult::Ignored;
    }