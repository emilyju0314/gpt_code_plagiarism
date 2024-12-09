void CSFTP::seekFile(const File &fileHandle, uint32_t offset)
    {
        if (sftp_seek(fileHandle.get(), offset) < 0)
        {
            throw Exception(*this, __func__);
        }
    }