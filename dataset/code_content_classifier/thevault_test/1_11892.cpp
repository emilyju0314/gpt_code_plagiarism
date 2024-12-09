QImage GetSubImagePreview(IImageObjectPtr image, uint32_t mip)
    {
        AZ::u8* imageBuf;
        AZ::u32 pitch;
        image->GetImagePointer(mip, imageBuf, pitch);
        const AZ::u32 width = image->GetWidth(mip);
        const AZ::u32 height = image->GetHeight(mip);
        return QImage(imageBuf, width, height, pitch, QImage::Format_RGBA8888);
    }