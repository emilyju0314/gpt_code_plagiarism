void CZIPIO::readZIPRecord(std::fstream &zipFileStream, CZIPIO::EOCentralDirectoryRecord &entry)
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
            buffptr = getField(entry.diskNumber, buffptr);
            buffptr = getField(entry.startDiskNumber, buffptr);
            buffptr = getField(entry.numberOfCentralDirRecords, buffptr);
            buffptr = getField(entry.totalCentralDirRecords, buffptr);
            buffptr = getField(entry.sizeOfCentralDirRecords, buffptr);
            buffptr = getField(entry.offsetCentralDirRecords, buffptr);
            buffptr = getField(entry.commentLength, buffptr);
            if (entry.commentLength != 0)
            {
                if (entry.commentLength > buffer.size())
                {
                    buffer.resize(entry.commentLength);
                }
                zipFileStream.read((char *)&buffer[0], entry.commentLength);
                entry.comment.resize(entry.commentLength);
                entry.comment.append((char *)&buffer[0], entry.commentLength);
            }
            if (zipFileStream.fail())
            {
                throw Exception("Error in reading End Of Central Directory record.");
            }
        }
        else
        {
            throw Exception("No End Of Central Directory record found.");
        }
    }