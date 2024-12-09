void TextureAtlasImpl::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->ClassDeprecate("SimpleAssetReference_TextureAtlasAsset", "{6F612FE6-A054-4E49-830C-0288F3C79A52}",
                [](AZ::SerializeContext& context, AZ::SerializeContext::DataElementNode& rootElement)
            {
                AZStd::vector<AZ::SerializeContext::DataElementNode> childNodeElements;
                for (int index = 0; index < rootElement.GetNumSubElements(); ++index)
                {
                    childNodeElements.push_back(rootElement.GetSubElement(index));
                }
                // Convert the rootElement now, the existing child DataElmentNodes are now removed
                rootElement.Convert<AzFramework::SimpleAssetReference<TextureAtlasAsset>>(context);
                for (AZ::SerializeContext::DataElementNode& childNodeElement : childNodeElements)
                {
                    rootElement.AddElement(AZStd::move(childNodeElement));
                }
                return true;
            });
            
            // Need to serialize the old AZStd::unordered_map<AZStd::string, AtlasCoordinates> type
            serialize->RegisterGenericType<AZStd::unordered_map<AZStd::string, AtlasCoordinates>>();
            serialize->Class<TextureAtlasImpl>()->Version(2, &TextureAtlasVersionConverter)
                ->Field(s_CoordinatePairsName, &TextureAtlasImpl::m_data)
                ->Field("Width", &TextureAtlasImpl::m_width)
                ->Field("Height", &TextureAtlasImpl::m_height);
            AzFramework::SimpleAssetReference<TextureAtlasAsset>::Register(*serialize);
        }
        AtlasCoordinates::Reflect(context);
    }