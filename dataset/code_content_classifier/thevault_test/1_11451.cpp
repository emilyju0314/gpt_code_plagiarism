size_t CSFTP::writeFile(const File &fileHandle, void *writeBuffer, size_t bytesToWrite)
    {
        size_t bytesWritten = sftp_write(fileHandle.get(), writeBuffer, bytesToWrite);
        if (static_cast<int>(bytesWritten) < 0)
        {
            throw Exception(*this, __func__);
        }
        return (bytesWritten);
    }