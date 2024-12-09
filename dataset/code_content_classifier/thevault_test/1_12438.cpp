TextureAtlas* TextureAtlasSystemComponent::LoadAtlas(const AZStd::string& filePath)
    {
        // Dont use an empty string as a path
        if (filePath.empty())
        {
            return nullptr;
        }
        
        // Normalize the file path
        AZStd::string path = filePath;
        AzFramework::ApplicationRequests::Bus::Broadcast(&AzFramework::ApplicationRequests::NormalizePath, path);

        // Check if the atlas is already loaded
        AZStd::string assetPath = path;
        AzFramework::StringFunc::Path::ReplaceExtension(assetPath, "texatlasidx");
        
        auto iterator = m_atlases.find(assetPath);
        if (iterator != m_atlases.end())
        {
            iterator->second.m_refs++;
            return iterator->second.m_atlas;
        }

        // If it isn't loaded, load it
        // Open the file
        AZ::IO::FileIOBase* input = AZ::IO::FileIOBase::GetInstance();
        AZ::IO::HandleType handle;
        input->Open(assetPath.c_str(), AZ::IO::OpenMode::ModeRead, handle);

        // Read the file
        AZ::u64 size;
        input->Size(handle, size);
        char* buffer = new char[size + 1];
        input->Read(handle, buffer, size);
        buffer[size] = 0;

        // Close the file
        input->Close(handle);

        TextureAtlas* loadedAtlas = AZ::Utils::LoadObjectFromBuffer<TextureAtlasImpl>(buffer, size);
        delete[] buffer;
        if (loadedAtlas)
        {
            // Convert to image path based on the atlas path
            AZStd::string imagePath = path;
            AzFramework::StringFunc::Path::ReplaceExtension(imagePath, "texatlas");
            AZ::Data::Instance<AZ::RPI::Image> texture = LoadAtlasImage(imagePath);
            if (!texture)
            {
                AZ_Error("TextureAtlasSystemComponent",
                    false,
                    "Failed to find or create an image instance for texture atlas '%s'"
                    "NOTE: File must be in current project or a gem.",
                    path.c_str());

                delete loadedAtlas;
                return nullptr;
            }
            else
            {
                // Add the atlas to the list
                AtlasInfo info(loadedAtlas, assetPath);
                ++info.m_refs;
                loadedAtlas->SetTexture(texture);
                AZ::Data::AssetCatalogRequestBus::BroadcastResult(info.m_atlasAssetId, &AZ::Data::AssetCatalogRequests::GetAssetIdByPath, assetPath.c_str(),
                    info.m_atlasAssetId.TYPEINFO_Uuid(), false);
                m_atlases[assetPath] = info;
                TextureAtlasNotificationBus::Broadcast(&TextureAtlasNotifications::OnAtlasLoaded, loadedAtlas);
            }
        }
        return loadedAtlas;
    }