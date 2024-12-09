void CZIP::open(void)
    {
        if (m_open)
        {
            throw Exception("ZIP archive has already been opened.");
        }
        EOCentralDirectoryRecord zipEOCentralDirectory;
        Zip64EOCentralDirectoryRecord zip64EOCentralDirectory;
        openZIPFile(m_zipFileName, std::ios::binary | std::ios_base::in | std::ios_base::out);
        std::int64_t noOfFileRecords = 0;
        getZIPRecord(zipEOCentralDirectory);
        // If one of the central directory fields is to large to store so ZIP64
        if (fieldOverflow(zipEOCentralDirectory.totalCentralDirRecords) ||
            fieldOverflow(zipEOCentralDirectory.numberOfCentralDirRecords) ||
            fieldOverflow(zipEOCentralDirectory.sizeOfCentralDirRecords) ||
            fieldOverflow(zipEOCentralDirectory.totalCentralDirRecords) ||
            fieldOverflow(zipEOCentralDirectory.startDiskNumber) ||
            fieldOverflow(zipEOCentralDirectory.diskNumber) ||
            fieldOverflow(zipEOCentralDirectory.offsetCentralDirRecords))
        {
            m_ZIP64 = true;
            getZIPRecord(zip64EOCentralDirectory);
            positionInZIPFile(zip64EOCentralDirectory.offsetCentralDirRecords);
            noOfFileRecords = zip64EOCentralDirectory.numberOfCentralDirRecords;
            m_offsetToEndOfLocalFileHeaders = zip64EOCentralDirectory.offsetCentralDirRecords;
        }
        else
        {
            // Normal Archive
            positionInZIPFile(zipEOCentralDirectory.offsetCentralDirRecords);
            noOfFileRecords = zipEOCentralDirectory.numberOfCentralDirRecords;
            m_offsetToEndOfLocalFileHeaders = zipEOCentralDirectory.offsetCentralDirRecords;
        }
        // Read in Central Directory
        for (auto cnt01 = 0; cnt01 < noOfFileRecords; cnt01++)
        {
            CentralDirectoryFileHeader directoryEntry;
            getZIPRecord(directoryEntry);
            m_zipCentralDirectory.push_back(directoryEntry);
            m_ZIP64 = fieldOverflow(directoryEntry.compressedSize) ||
                      fieldOverflow(directoryEntry.uncompressedSize) ||
                      fieldOverflow(directoryEntry.fileHeaderOffset);
        }
        m_open = true;
    }