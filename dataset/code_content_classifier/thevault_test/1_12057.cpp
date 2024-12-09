void LoadingTrackingProcessor::Deactivate()
    {
        AZ::SceneAPI::SceneCore::LoadingComponent::Deactivate();

        // Forward the call to the LoadingComponent so that the call bindings get deactivated.
        AZ::SceneAPI::Events::CallProcessorBus::Handler::BusDisconnect();

        AZ::SceneAPI::Events::AssetImportRequestBus::Handler::BusDisconnect();
    }