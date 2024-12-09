uint32_t CSFTP::currentFilePostion(const File &fileHandle)
    {
        int32_t position = sftp_tell(fileHandle.get());
        if (position == -1)
        {
            throw Exception(*this, __func__);
        }
        return (static_cast<uint32_t>(position));
    }