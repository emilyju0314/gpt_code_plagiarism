void TextureAtlasSystemComponent::UnloadAtlas(TextureAtlas* atlas)
    {
        // Check if the atlas is loaded
        for (auto iterator = m_atlases.begin(); iterator != m_atlases.end(); ++iterator)
        {
            if (iterator->second.m_atlas == atlas)
            {
                --iterator->second.m_refs;
                if (iterator->second.m_refs < 1 && iterator->second.m_atlas->GetTexture())
                {
                    AtlasInfo temp = iterator->second;
                    m_atlases.erase(iterator->first);
                    TextureAtlasNotificationBus::Broadcast(&TextureAtlasNotifications::OnAtlasUnloaded, temp.m_atlas);

                    // Tell the renderer to release the texture.
                    if (temp.m_atlas && temp.m_atlas->GetTexture())
                    {
                        temp.m_atlas->GetTexture().reset();
                    }
                    // Delete the atlas
                    if (temp.m_atlas)
                    {
                        delete temp.m_atlas;
                        temp.m_atlas = NULL;
                    }
                }
                return;
            }
        }
    }