Importer::EFileType Importer::CheckFileType(const char* filename)
    {
        // check for a valid name
        if (AZStd::string(filename).empty())
        {
            return FILETYPE_UNKNOWN;
        }

        AZStd::string fileExtension;
        AZ::StringFunc::Path::GetExtension(filename, fileExtension);

        if (fileExtension == ".animgraph")
        {
            return FILETYPE_ANIMGRAPH;
        }
        if (fileExtension == ".motionset")
        {
            return FILETYPE_MOTIONSET;
        }

        // try to open the file from disk
        MCore::MemoryFile memoryFile;
        memoryFile.Open();
        memoryFile.SetPreAllocSize(262144); // 256kb
        if (memoryFile.LoadFromDiskFile(filename) == false)
        {
            return FILETYPE_UNKNOWN;
        }

        if (memoryFile.GetFileSize() == 0)
        {
            return FILETYPE_UNKNOWN;
        }

        // check the file type
        return CheckFileType(&memoryFile);
    }