size_t CSFTP::readFile(const File &fileHandle, void *readBuffer, size_t bytesToRead)
    {
        size_t bytesRead = sftp_read(fileHandle.get(), readBuffer, bytesToRead);
        if (static_cast<int>(bytesRead) < 0)
        {
            throw Exception(*this, __func__);
        }
        return (bytesRead);
    }