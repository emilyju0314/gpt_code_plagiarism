void CZIPIO::readZIPRecord(std::fstream &zipFileStream, CZIPIO::CentralDirectoryFileHeader &entry)
    {
        std::vector<std::uint8_t> buffer(entry.size);
        std::uint8_t *buffptr = &buffer[0];
        std::uint32_t signature;
        zipFileStream.read((char *)buffptr, sizeof(signature));
        buffptr = getField(signature, buffptr);
        if (signature == entry.signature)
        {
            zipFileStream.read((char *)buffptr, entry.size - sizeof(signature));
            buffptr = getField(entry.creatorVersion, buffptr);
            buffptr = getField(entry.extractorVersion, buffptr);
            buffptr = getField(entry.bitFlag, buffptr);
            buffptr = getField(entry.compression, buffptr);
            buffptr = getField(entry.modificationTime, buffptr);
            buffptr = getField(entry.modificationDate, buffptr);
            buffptr = getField(entry.crc32, buffptr);
            buffptr = getField(entry.compressedSize, buffptr);
            buffptr = getField(entry.uncompressedSize, buffptr);
            buffptr = getField(entry.fileNameLength, buffptr);
            buffptr = getField(entry.extraFieldLength, buffptr);
            buffptr = getField(entry.fileCommentLength, buffptr);
            buffptr = getField(entry.diskNoStart, buffptr);
            buffptr = getField(entry.internalFileAttrib, buffptr);
            buffptr = getField(entry.externalFileAttrib, buffptr);
            buffptr = getField(entry.fileHeaderOffset, buffptr);
            if (static_cast<size_t>(entry.fileNameLength + entry.extraFieldLength + entry.fileCommentLength) > buffer.size())
            {
                buffer.resize(entry.fileNameLength + entry.extraFieldLength + entry.fileCommentLength);
            }
            zipFileStream.read((char *)&buffer[0], entry.fileNameLength + entry.extraFieldLength + entry.fileCommentLength);
            if (entry.fileNameLength)
            {
                entry.fileName.append((char *)&buffer[0], entry.fileNameLength);
            }
            if (entry.extraFieldLength)
            {
                entry.extraField.resize(entry.extraFieldLength);
                std::memcpy(&entry.extraField[0], &buffer[entry.fileNameLength], entry.extraFieldLength);
            }
            if (entry.fileCommentLength)
            {
                entry.fileName.append((char *)&buffer[entry.fileNameLength + entry.extraFieldLength], entry.fileCommentLength);
            }
            if (zipFileStream.fail())
            {
                throw Exception("Error in reading Central Directory Local File Header record.");
            }
        }
        else
        {
            throw Exception("No Central Directory File Header found.");
        }
    }