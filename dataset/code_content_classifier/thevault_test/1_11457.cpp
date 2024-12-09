void CSFTP::getFileAttributes(const std::string &filePath, FileAttributes &fileAttributes)
    {
        sftp_attributes file{sftp_stat(m_sftp, filePath.c_str())};
        if (file == NULL)
        {
            throw Exception(*this, __func__);
        }
        fileAttributes.reset(file);
    }