void CZIPIO::readZIPRecord(std::fstream &zipFileStream, CZIPIO::DataDescriptor &entry)
    {
        std::vector<std::uint8_t> buffer(entry.size);
        std::uint8_t *buffptr = &buffer[0];
        std::uint32_t signature;
        zipFileStream.read((char *)buffptr, sizeof(signature));
        buffptr = getField(signature, buffptr);
        if (signature == entry.signature)
        {
            zipFileStream.read((char *)buffptr, entry.size - sizeof(signature));
            buffptr = getField(entry.crc32, buffptr);
            buffptr = getField(entry.compressedSize, buffptr);
            buffptr = getField(entry.uncompressedSize, buffptr);
            if (zipFileStream.fail())
            {
                throw Exception("Error in reading Data Descriptor Record.");
            }
        }
        else
        {
            throw Exception("No Data Descriptor record found.");
        }
    }