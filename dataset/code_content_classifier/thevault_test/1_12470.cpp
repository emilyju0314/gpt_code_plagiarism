int NestedArchive::StartContinuousFileUpdate(AZStd::string_view szRelativePath, uint64_t nSize)
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
        return m_pCache->StartContinuousFileUpdate(fullPath, nSize);
    }