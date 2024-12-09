void CZIPIO::writeZIPRecord(std::fstream &zipFileStream, CZIPIO::Zip64EOCentDirRecordLocator &entry)
    {
        std::vector<std::uint8_t> buffer;
        putField(entry.signature, buffer);
        putField(entry.startDiskNumber, buffer);
        putField(entry.offset, buffer);
        putField(entry.numberOfDisks, buffer);
        zipFileStream.write((char *)&buffer[0], entry.size);
        if (zipFileStream.fail())
        {
            throw Exception("Error in writing ZIP64 End Of Central Directory record locator.");
        }
    }