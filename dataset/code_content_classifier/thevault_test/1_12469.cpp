int NestedArchive::UpdateFile(AZStd::string_view szRelativePath, const void* pUncompressed, uint64_t nSize, uint32_t nCompressionMethod, int nCompressionLevel, CompressionCodec::Codec codec)
    {
        if (m_nFlags & FLAGS_READ_ONLY)
        {
            return ZipDir::ZD_ERROR_INVALID_CALL;
        }

        AZ::IO::FixedMaxPathString fullPath = AdjustPath(szRelativePath);
        if (fullPath.empty())
        {
            return ZipDir::ZD_ERROR_INVALID_PATH;
        }
        return m_pCache->UpdateFile(fullPath, pUncompressed, nSize, nCompressionMethod, nCompressionLevel, codec);
    }