void CZIPIO::writeZIPRecord(std::fstream &zipFileStream, CZIPIO::DataDescriptor &entry)
    {
        std::vector<std::uint8_t> buffer;
        putField(entry.signature, buffer);
        putField(entry.crc32, buffer);
        putField(entry.compressedSize, buffer);
        putField(entry.uncompressedSize, buffer);
        zipFileStream.write((char *)&buffer[0], entry.size);
        if (zipFileStream.fail())
        {
            throw Exception("Error in writing Data Descriptor Record.");
        }
    }