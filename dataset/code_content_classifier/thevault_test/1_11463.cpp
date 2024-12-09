void CSFTP::seekFile64(const File &fileHandle, uint64_t offset)
    {
        if (sftp_seek64(fileHandle.get(), offset) < 0)
        {
            throw Exception(*this, __func__);
        }
    }