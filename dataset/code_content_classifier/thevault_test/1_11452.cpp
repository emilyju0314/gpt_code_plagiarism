CSFTP::Directory CSFTP::openDirectory(const std::string &directoryPath)
    {
        Directory directory{sftp_opendir(m_sftp, directoryPath.c_str())};
        if (directory.get() == NULL)
        {
            throw Exception(*this, __func__);
        }
        return (directory);
    }