void GetImageInfoString(IImageObjectPtr image, AZStd::string& output)
    {
        if (!image)
        {
            return;
        }

        output += AZStd::string::format("Dimensions: %dx%d\r\n", image->GetWidth(0), image->GetHeight(0));

        AZ::u32 mipCount = image->GetMipCount();
        output += AZStd::string::format("Mips: %d\r\n", mipCount);

        AZ::u32 memSize = image->GetTextureMemory();
        AZStd::string memSizeString = ImageProcessingAtomEditor::EditorHelper::GetFileSizeString(memSize);
        output += AZStd::string::format("Size: %s\r\n", memSizeString.c_str());

        CPixelFormats& pixelFormats = CPixelFormats::GetInstance();
        EPixelFormat format = image->GetPixelFormat();
        const PixelFormatInfo* info = pixelFormats.GetPixelFormatInfo(format);
        if (info)
        {
            output += AZStd::string::format("Format: %s\r\n", info->szName);
        }

        AZStd::string colorSpaceString;
        if (image->HasImageFlags(EIF_SRGBRead))
        {
            colorSpaceString = "sRGB";
        }
        else
        {
            // If the flag isn't set, then we don't know whether it's linear, or it's sRGB and the file format doesn't support a color space flag.
            colorSpaceString = "Unknown";
        }

        output += AZStd::string::format("Color Space: %s\r\n", colorSpaceString.c_str());

        if (image->HasImageFlags(EIF_Cubemap))
        {
            output += AZStd::string::format("Cubemap\r\n");
        }
    }