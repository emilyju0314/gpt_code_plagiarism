std::vector<CZIP::FileDetail> CZIP::contents(void)
    {
        std::vector<FileDetail> fileDetailList;
        if (!m_open)
        {
            throw Exception("ZIP archive has not been opened.");
        }
        for (auto &directoryEntry : m_zipCentralDirectory)
        {
            FileDetail fileEntry;
            fileEntry.fileName = directoryEntry.fileName;
            fileEntry.fileComment = directoryEntry.fileComment;
            fileEntry.uncompressedSize = directoryEntry.uncompressedSize;
            fileEntry.compressedSize = directoryEntry.compressedSize;
            fileEntry.compression = directoryEntry.compression;
            fileEntry.externalFileAttrib = directoryEntry.externalFileAttrib;
            fileEntry.creatorVersion = directoryEntry.creatorVersion;
            fileEntry.extraField = directoryEntry.extraField;
            fileEntry.modificationDateTime =
                convertModificationDateTime(directoryEntry.modificationDate,
                                            directoryEntry.modificationTime);
            // File size information stored in Extended information.
            if (fieldOverflow(directoryEntry.compressedSize) ||
                fieldOverflow(directoryEntry.uncompressedSize) ||
                fieldOverflow(directoryEntry.fileHeaderOffset))
            {
                Zip64ExtendedInfoExtraField extra;
                extra.compressedSize = directoryEntry.compressedSize;
                extra.fileHeaderOffset = directoryEntry.fileHeaderOffset;
                extra.originalSize = directoryEntry.uncompressedSize;
                getZip64ExtendedInfoExtraField(extra, fileEntry.extraField);
                fileEntry.uncompressedSize = extra.originalSize;
                fileEntry.compressedSize = extra.compressedSize;
                fileEntry.bZIP64 = true;
            }
            fileDetailList.push_back(fileEntry);
        }
        return (fileDetailList);
    }