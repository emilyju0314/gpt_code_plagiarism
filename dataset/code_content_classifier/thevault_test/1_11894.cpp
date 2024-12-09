void GetImageInfoString(const AZ::Data::Asset<AZ::RPI::StreamingImageAsset>& imageAsset, AZStd::string& output)
    {
        if (!imageAsset.IsReady())
        {
            return;
        }

        AZ::RHI::ImageDescriptor descriptor = imageAsset->GetImageDescriptor();

        output += AZStd::string("\r\nOverall image data...\r\n");

        output += AZStd::string::format("Dimensions: %dx%d\r\n", descriptor.m_size.m_width, descriptor.m_size.m_height);

        AZStd::string memSizeString;
        if (imageAsset->GetTotalImageDataSize() > 0)
        {
            memSizeString = ImageProcessingAtomEditor::EditorHelper::GetFileSizeString(imageAsset->GetTotalImageDataSize());
        }
        else
        {
            memSizeString = "Unknown";
        }
        output += AZStd::string::format("Size: %s\r\n", memSizeString.c_str());

        uint32_t totalMipCount = descriptor.m_mipLevels;
        output += AZStd::string::format("Mips: %d\r\n", totalMipCount);

        output += AZStd::string::format("Format: %s\r\n", AZ::RHI::ToString(descriptor.m_format));

        //[GFX TODO] Put this back in, pending in my other CL
        //output += AZStd::string::format("Color Space: %s\r\n", AZ::RHI::ToString(descriptor.m_colorSpace));

        if (descriptor.m_isCubemap)
        {
            output += AZStd::string::format("Cubemap: true\r\n");
        }


        output += AZStd::string("\r\nBuilt-in mip chain...\r\n");

        uint32_t builtInMipCount = imageAsset->GetTailMipChain().GetMipLevelCount();
        output += AZStd::string::format("Mips: %d\r\n", builtInMipCount);

        memSizeString = ImageProcessingAtomEditor::EditorHelper::GetFileSizeString(imageAsset->GetTailMipChain().GetImageDataSize());
        output += AZStd::string::format("Size: %s\r\n", memSizeString.c_str());

        AZ::RHI::Size builtInMipSizeA = imageAsset->GetTailMipChain().GetSubImageLayout(0).m_size;
        AZStd::string mipChainDimensionString;
        if (builtInMipCount == 1)
        {
            mipChainDimensionString = AZStd::string::format("%dx%d", builtInMipSizeA.m_width, builtInMipSizeA.m_height);
        }
        else
        {
            AZ::RHI::Size builtInMipSizeB = imageAsset->GetTailMipChain().GetSubImageLayout(builtInMipCount - 1).m_size;
            mipChainDimensionString = AZStd::string::format("%dx%d .. %dx%d", builtInMipSizeA.m_width, builtInMipSizeA.m_height, builtInMipSizeB.m_width, builtInMipSizeB.m_height);
        }
        output += AZStd::string::format("Dimensions: %s\r\n", mipChainDimensionString.c_str());

        output += AZStd::string("\r\n");

        size_t additionalMipChainCount = imageAsset->GetMipChainCount() - 1;
        output += AZStd::string::format("Additional Mip Chains: %zu\r\n", additionalMipChainCount);
    }