auto NestedArchive::FindFile(AZStd::string_view szRelativePath) -> Handle
    {
        AZ::IO::FixedMaxPathString fullPath = AdjustPath(szRelativePath);
        if (fullPath.empty())
        {
            return nullptr;
        }
        return m_pCache->FindFile(fullPath);
    }