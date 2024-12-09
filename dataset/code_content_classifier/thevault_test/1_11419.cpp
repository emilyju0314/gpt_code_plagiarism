void CZIPIO::writeZIPRecord(std::fstream &zipFileStream, CZIPIO::Zip64EOCentralDirectoryRecord &entry)
    {
        std::vector<std::uint8_t> buffer;
        entry.totalRecordSize = entry.size - 12 +
                                entry.extensibleDataSector.size();
        putField(entry.signature, buffer);
        putField(entry.totalRecordSize, buffer);
        putField(entry.creatorVersion, buffer);
        putField(entry.extractorVersion, buffer);
        putField(entry.diskNumber, buffer);
        putField(entry.startDiskNumber, buffer);
        putField(entry.numberOfCentralDirRecords, buffer);
        putField(entry.totalCentralDirRecords, buffer);
        putField(entry.sizeOfCentralDirRecords, buffer);
        putField(entry.offsetCentralDirRecords, buffer);
        zipFileStream.write((char *)&buffer[0], entry.size);
        if (!entry.extensibleDataSector.empty())
        {
            zipFileStream.write((char *)&entry.extensibleDataSector[0], entry.extensibleDataSector.size());
        }
        if (zipFileStream.fail())
        {
            throw Exception("Error in writing ZIP64 End Of Central Directory record.");
        }
    }