void CSFTP::setFileAttributes(const std::string &filePath, const FileAttributes &fileAttributes)
    {
        if (sftp_setstat(m_sftp, filePath.c_str(), fileAttributes.get()) < 0)
        {
            throw Exception(*this, __func__);
        }
    }