void LoadingTrackingProcessor::Reflect(AZ::ReflectContext* context)
    {
        AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(context);
        if (serializeContext)
        {
            serializeContext->Class<LoadingTrackingProcessor, AZ::SceneAPI::SceneCore::LoadingComponent>()->Version(1);
        }
    }