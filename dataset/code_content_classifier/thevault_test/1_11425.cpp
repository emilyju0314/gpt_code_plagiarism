void CZIPIO::readZIPRecord(std::fstream &zipFileStream, CZIPIO::Zip64EOCentralDirectoryRecord &entry)
    {
        std::vector<std::uint8_t> buffer(entry.size);
        std::uint8_t *buffptr = &buffer[0];
        std::uint32_t signature;
        std::uint64_t extensionSize;
        Zip64EOCentDirRecordLocator zip64EOCentralDirLocator;
        readZIPRecord(zipFileStream, zip64EOCentralDirLocator);
        zipFileStream.seekg(zip64EOCentralDirLocator.offset, std::ios::beg);
        zipFileStream.read((char *)buffptr, sizeof(signature));
        buffptr = getField(signature, buffptr);
        if (signature == entry.signature)
        {
            zipFileStream.read((char *)buffptr, entry.size - sizeof(signature));
            buffptr = getField(entry.totalRecordSize, buffptr);
            buffptr = getField(entry.creatorVersion, buffptr);
            buffptr = getField(entry.extractorVersion, buffptr);
            buffptr = getField(entry.diskNumber, buffptr);
            buffptr = getField(entry.startDiskNumber, buffptr);
            buffptr = getField(entry.numberOfCentralDirRecords, buffptr);
            buffptr = getField(entry.totalCentralDirRecords, buffptr);
            buffptr = getField(entry.sizeOfCentralDirRecords, buffptr);
            buffptr = getField(entry.offsetCentralDirRecords, buffptr);
            extensionSize = entry.totalRecordSize - entry.size + 12;
            if (extensionSize)
            {
                entry.extensibleDataSector.resize(extensionSize);
                zipFileStream.read((char *)&entry.extensibleDataSector[0], extensionSize);
            }
            if (zipFileStream.fail())
            {
                throw Exception("Error in reading ZIP64 End Of Central Directory record.");
            }
        }
        else
        {
            throw Exception("No ZIP64 End Of Central Directory record found.");
        }
    }