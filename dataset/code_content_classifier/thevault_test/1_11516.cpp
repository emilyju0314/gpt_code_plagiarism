void CZIP::UpdateCentralDirectory(void)
    {
        if (m_modified)
        {
            EOCentralDirectoryRecord zipEOCentralDirectory;
            Zip64EOCentralDirectoryRecord zip64EOCentralDirectory;
            bool bZIP64 = false;
            // Position to end of local file headers
            positionInZIPFile(m_offsetToEndOfLocalFileHeaders);
            // Initialise central directory offset and size
            zip64EOCentralDirectory.numberOfCentralDirRecords = m_zipCentralDirectory.size();
            zip64EOCentralDirectory.totalCentralDirRecords = m_zipCentralDirectory.size();
            zip64EOCentralDirectory.offsetCentralDirRecords = currentPositionZIPFile();
            // Write Central Directory to ZIP archive
            for (auto &directoryEntry : m_zipCentralDirectory)
            {
                putZIPRecord(directoryEntry);
            }
            // Calculate Central Directory size in byes.
            zip64EOCentralDirectory.sizeOfCentralDirRecords = currentPositionZIPFile();
            zip64EOCentralDirectory.sizeOfCentralDirRecords -= zip64EOCentralDirectory.offsetCentralDirRecords;
            // Number of records 16 bit overflow so use ZIP64 ie. 32 bits
            if (fieldRequires32bits(zip64EOCentralDirectory.numberOfCentralDirRecords))
            {
                zipEOCentralDirectory.numberOfCentralDirRecords = static_cast<std::uint16_t>(~0);
                bZIP64 = true;
            }
            else
            {
                zipEOCentralDirectory.numberOfCentralDirRecords = zip64EOCentralDirectory.numberOfCentralDirRecords;
            }
            // Total number of records 16 bit overflow so use ZIP64 ie. 32 bits
            if (fieldRequires32bits(zip64EOCentralDirectory.totalCentralDirRecords))
            {
                zipEOCentralDirectory.totalCentralDirRecords = static_cast<std::uint16_t>(~0);
                bZIP64 = true;
            }
            else
            {
                zipEOCentralDirectory.totalCentralDirRecords = zip64EOCentralDirectory.totalCentralDirRecords;
            }
            // Offset 32 bit overflow so use ZIP64 ie. 64 bits
            if (fieldRequires64bits(zip64EOCentralDirectory.offsetCentralDirRecords))
            {
                zipEOCentralDirectory.offsetCentralDirRecords = static_cast<std::uint32_t>(~0);
                bZIP64 = true;
            }
            else
            {
                zipEOCentralDirectory.offsetCentralDirRecords = zip64EOCentralDirectory.offsetCentralDirRecords;
            }
            // Central Directory size 32 bit overflow so use ZIP64 ie. 64 bits
            if (fieldRequires64bits(zip64EOCentralDirectory.sizeOfCentralDirRecords))
            {
                zipEOCentralDirectory.sizeOfCentralDirRecords = static_cast<std::uint32_t>(~0);
                bZIP64 = true;
            }
            else
            {
                zipEOCentralDirectory.sizeOfCentralDirRecords = zip64EOCentralDirectory.sizeOfCentralDirRecords;
            }
            // Central Directory start disk 16 bit overflow so use ZIP64 ie. 32 bits
            if (fieldRequires32bits(zip64EOCentralDirectory.startDiskNumber))
            {
                zipEOCentralDirectory.startDiskNumber = static_cast<std::uint16_t>(~0);
                bZIP64 = true;
            }
            else
            {
                zipEOCentralDirectory.startDiskNumber = zip64EOCentralDirectory.startDiskNumber;
            }
            // Central Directory number of disks 16 bit overflow so use ZIP64 ie. 32 bits
            if (fieldRequires32bits(zip64EOCentralDirectory.diskNumber))
            {
                zipEOCentralDirectory.diskNumber = static_cast<std::uint16_t>(~0);
                bZIP64 = true;
            }
            else
            {
                zipEOCentralDirectory.diskNumber = zip64EOCentralDirectory.diskNumber;
            }
            // ZIP64 so write extension records
            if (bZIP64)
            {
                Zip64EOCentDirRecordLocator locator;
                locator.offset = currentPositionZIPFile();
                putZIPRecord(zip64EOCentralDirectory);
                putZIPRecord(locator);
            }
            // Write End Of Central Directory record
            putZIPRecord(zipEOCentralDirectory);
        }
    }