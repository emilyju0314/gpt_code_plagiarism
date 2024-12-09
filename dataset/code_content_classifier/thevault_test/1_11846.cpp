void TextureAtlasImpl::SetTexture(AZ::Data::Instance<AZ::RPI::Image> image)
    {
        // We don't need to delete the old value because the pointer is handled elsewhere
        m_image = image;
    }