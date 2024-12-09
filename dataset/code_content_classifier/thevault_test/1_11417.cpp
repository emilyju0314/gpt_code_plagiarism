void CZIPIO::writeZIPRecord(std::fstream &zipFileStream, CZIPIO::LocalFileHeader &entry)
    {
        std::vector<std::uint8_t> buffer;
        putField(entry.signature, buffer);
        putField(entry.creatorVersion, buffer);
        putField(entry.bitFlag, buffer);
        putField(entry.compression, buffer);
        putField(entry.modificationTime, buffer);
        putField(entry.modificationDate, buffer);
        putField(entry.crc32, buffer);
        putField(entry.compressedSize, buffer);
        putField(entry.uncompressedSize, buffer);
        putField(entry.fileNameLength, buffer);
        putField(entry.extraFieldLength, buffer);
        zipFileStream.write((char *)&buffer[0], entry.size);
        if (entry.fileNameLength)
        {
            zipFileStream.write((char *)&entry.fileName[0], entry.fileNameLength);
        }
        if (entry.extraFieldLength)
        {
            zipFileStream.write((char *)&entry.extraField[0], entry.extraFieldLength);
        }
        if (zipFileStream.fail())
        {
            throw Exception("Error in writing Local File Header record.");
        }
    }