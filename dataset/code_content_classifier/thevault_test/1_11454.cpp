void CSFTP::changePermissions(const std::string &filePath, const FilePermissions &filePermissions)
    {
        if (sftp_chmod(m_sftp, filePath.c_str(), filePermissions) < 0)
        {
            throw Exception(*this, __func__);
        }
    }