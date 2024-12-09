void CZIPIO::writeZIPRecord(std::fstream &zipFileStream, CZIPIO::CentralDirectoryFileHeader &entry)
    {
        std::vector<std::uint8_t> buffer;
        putField(entry.signature, buffer);
        putField(entry.creatorVersion, buffer);
        putField(entry.extractorVersion, buffer);
        putField(entry.bitFlag, buffer);
        putField(entry.compression, buffer);
        putField(entry.modificationTime, buffer);
        putField(entry.modificationDate, buffer);
        putField(entry.crc32, buffer);
        putField(entry.compressedSize, buffer);
        putField(entry.uncompressedSize, buffer);
        putField(entry.fileNameLength, buffer);
        putField(entry.extraFieldLength, buffer);
        putField(entry.fileCommentLength, buffer);
        putField(entry.diskNoStart, buffer);
        putField(entry.internalFileAttrib, buffer);
        putField(entry.externalFileAttrib, buffer);
        putField(entry.fileHeaderOffset, buffer);
        zipFileStream.write((char *)&buffer[0], entry.size);
        if (entry.fileNameLength)
        {
            zipFileStream.write((char *)&entry.fileName[0], entry.fileNameLength);
        }
        if (entry.extraFieldLength)
        {
            zipFileStream.write((char *)&entry.extraField[0], entry.extraFieldLength);
        }
        if (entry.fileCommentLength)
        {
            zipFileStream.write((char *)&entry.fileComment[0], entry.fileCommentLength);
        }
        if (zipFileStream.fail())
        {
            throw Exception("Error in writing Central Directory Local File Header record.");
        }
    }