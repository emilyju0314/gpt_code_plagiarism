int NestedArchive::ListAllFiles(AZStd::vector<AZ::IO::Path>& outFileEntries)
    {
        AZStd::vector<AZ::IO::Path> filesInArchive;

        ZipDir::FileEntryTree* tree = m_pCache->GetRoot();
        if (!tree)
        {
            return ZipDir::ZD_ERROR_UNEXPECTED;
        }

        EnumerateFilesRecursive(AZ::IO::Path{ AZ::IO::PosixPathSeparator }, tree, filesInArchive);

        AZStd::swap(outFileEntries, filesInArchive);
        return ZipDir::ZD_ERROR_SUCCESS;
    }