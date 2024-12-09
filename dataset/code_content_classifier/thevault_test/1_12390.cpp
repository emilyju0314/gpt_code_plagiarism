Importer::EFileType Importer::CheckFileType(MCore::File* file)
    {
        MCore::Endian::EEndianType  endianType = MCore::Endian::ENDIAN_LITTLE;

        // verify if this is a valid actor file or not
        file->Seek(0);
        if (CheckIfIsValidActorFile(file, &endianType))
        {
            file->Close();
            return FILETYPE_ACTOR;
        }

        // verify if this is a valid skeletal motion file or not
        file->Seek(0);
        if (CheckIfIsValidMotionFile(file, &endianType))
        {
            file->Close();
            return FILETYPE_MOTION;
        }

        // check for node map
        file->Seek(0);
        if (CheckIfIsValidNodeMapFile(file, &endianType))
        {
            file->Close();
            return FILETYPE_NODEMAP;
        }

        // close the file again
        file->Close();

        return FILETYPE_UNKNOWN;
    }