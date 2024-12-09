uint64_t CSFTP::currentFilePostion64(const File &fileHandle)
    {
        int64_t position = sftp_tell64(fileHandle.get());
        if (position == -1)
        {
            throw Exception(*this, __func__);
        }
        return (static_cast<uint64_t>(position));
    }