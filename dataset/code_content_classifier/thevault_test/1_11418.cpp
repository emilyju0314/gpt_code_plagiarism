void CZIPIO::writeZIPRecord(std::fstream &zipFileStream, CZIPIO::EOCentralDirectoryRecord &entry)
    {
        std::vector<std::uint8_t> buffer;
        putField(entry.signature, buffer);
        putField(entry.diskNumber, buffer);
        putField(entry.startDiskNumber, buffer);
        putField(entry.numberOfCentralDirRecords, buffer);
        putField(entry.totalCentralDirRecords, buffer);
        putField(entry.sizeOfCentralDirRecords, buffer);
        putField(entry.offsetCentralDirRecords, buffer);
        putField(entry.commentLength, buffer);
        zipFileStream.write((char *)&buffer[0], entry.size);
        if (entry.commentLength)
        {
            zipFileStream.write((char *)&entry.comment[0], entry.commentLength);
        }
        if (zipFileStream.fail())
        {
            throw Exception("Error in writing End Of Central Directory Local File Header record.");
        }
    }