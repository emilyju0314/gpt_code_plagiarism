void CSFTP::getFileAttributes(const File &fileHandle, FileAttributes &fileAttributes)
    {
        sftp_attributes file{sftp_fstat(fileHandle.get())};
        if (file == NULL)
        {
            throw Exception(*this, __func__);
        }
        fileAttributes.reset(file);
    }