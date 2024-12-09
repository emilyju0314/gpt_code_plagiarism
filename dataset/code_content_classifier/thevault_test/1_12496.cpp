ErrorEnum FileEntryTree::Add(AZ::IO::PathView szPath, const FileEntryBase& file)
    {
        FileEntry* pFile = Add(szPath);
        if (!pFile)
        {
            return ZD_ERROR_INVALID_PATH;
        }
        if (pFile->IsInitialized())
        {
            return ZD_ERROR_FILE_ALREADY_EXISTS;
        }
        static_cast<FileEntryBase&>(*pFile) = file;
        return ZD_ERROR_SUCCESS;
    }