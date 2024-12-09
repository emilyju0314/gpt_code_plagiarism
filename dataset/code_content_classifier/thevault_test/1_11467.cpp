void CSFTP::getFileSystemInfo(const File &fileHandle, FileSystemInfo &fileSystem)
    {
        sftp_statvfs_t file{sftp_fstatvfs(fileHandle.get())};
        if (file == NULL)
        {
            throw Exception(*this, __func__);
        }
        fileSystem.reset(file);
    }