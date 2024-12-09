bool Importer::ExtractMotionFileInfo(FileInfo* outInfo, const char* filename) const
    {
        // open the file
        MCore::DiskFile file;
        if (file.Open(filename, MCore::DiskFile::READ) == false)
        {
            return false;
        }

        // read out the endian type
        MCore::Endian::EEndianType endianType = MCore::Endian::ENDIAN_LITTLE;
        if (!CheckIfIsValidMotionFile(&file, &endianType))
        {
            file.Close();
            return false;
        }
        outInfo->m_endianType = endianType;

        // as we seeked to the end of the header and we know the second chunk always is the time stamp, we can read this now
        FileFormat::FileChunk fileChunk;
        file.Read(&fileChunk, sizeof(FileFormat::FileChunk));
        FileFormat::FileTime timeChunk;
        file.Read(&timeChunk, sizeof(FileFormat::FileTime));

        // convert endian
        MCore::Endian::ConvertUnsignedInt32(&fileChunk.m_chunkId, endianType);
        MCore::Endian::ConvertUnsignedInt16(&timeChunk.m_year, endianType);

        return true;
    }