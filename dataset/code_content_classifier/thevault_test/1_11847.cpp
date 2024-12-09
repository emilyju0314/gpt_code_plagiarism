void TextureAtlasImpl::OverwriteMappings(TextureAtlasImpl* source)
    {
        m_data.clear();
        m_data = source->m_data;
        m_width = source->m_width;
        m_height = source->m_height;
    }