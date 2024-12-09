void FeatureProcessorDescriptor::Reflect(AZ::ReflectContext* context)
        {
            if (auto* serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
            {
                serializeContext->Class<FeatureProcessorDescriptor>()
                    ->Version(0)
                    ->Field("MaxRenderGraphLatency", &FeatureProcessorDescriptor::m_maxRenderGraphLatency)
                ;
            }
        }