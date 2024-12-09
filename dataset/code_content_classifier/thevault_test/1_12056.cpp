void LoadingTrackingProcessor::Activate()
    {
        AZ::SceneAPI::Events::AssetImportRequestBus::Handler::BusConnect();
        
        // Forward the call to the LoadingComponent so that the call bindings get activated.
        AZ::SceneAPI::SceneCore::LoadingComponent::Activate();
    }