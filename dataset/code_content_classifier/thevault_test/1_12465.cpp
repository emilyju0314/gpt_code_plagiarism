int NestedArchive::RemoveFile(AZStd::string_view szRelativePath)
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
        return m_pCache->RemoveFile(fullPath);
    }