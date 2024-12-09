void CZIPIO::readZIPRecord(std::fstream &zipFileStream, CZIPIO::Zip64EOCentDirRecordLocator &entry)
    {
        zipFileStream.seekg(0, std::ios_base::end);
        std::uint64_t fileLength = zipFileStream.tellg();
        int64_t filePosition = fileLength - 1;
        std::uint32_t signature = 0;
        // Read file in reverse looking for End Of Central Directory File Header signature
        while (filePosition)
        {
            char nextByte;
            zipFileStream.seekg(filePosition, std::ios_base::beg);
            zipFileStream.get(nextByte);
            signature <<= 8;
            signature |= nextByte;
            if (signature == entry.signature)
            {
                break;
            }
            filePosition--;
        }
        // If record found then get
        if (filePosition != -1)
        {
            std::vector<std::uint8_t> buffer(entry.size);
            std::uint8_t *buffptr = &buffer[0];
            zipFileStream.seekg(filePosition + sizeof(signature), std::ios_base::beg);
            zipFileStream.read((char *)buffptr, entry.size - sizeof(signature));
            buffptr = getField(entry.startDiskNumber, buffptr);
            buffptr = getField(entry.offset, buffptr);
            buffptr = getField(entry.numberOfDisks, buffptr);
            if (zipFileStream.fail())
            {
                throw Exception("Error in reading ZIP64 End Of Central Directory Locator records.");
            }
        }
        else
        {
            throw Exception("No ZIP64 End Of Central Directory Locator record found.");
        }
    }