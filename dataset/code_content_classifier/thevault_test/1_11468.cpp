void CSFTP::getFileSystemInfo(const std::string &fileSystemName, FileSystemInfo &fileSystem)
    {
        sftp_statvfs_t file{sftp_statvfs(m_sftp, fileSystemName.c_str())};
        if (file == NULL)
        {
            throw Exception(*this, __func__);
        }
        fileSystem.reset(file);
    }