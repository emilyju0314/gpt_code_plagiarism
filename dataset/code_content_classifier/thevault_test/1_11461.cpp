void CSFTP::createLink(const std::string &targetPath, const std::string &linkPath)
    {
        if (sftp_symlink(m_sftp, targetPath.c_str(), linkPath.c_str()) < 0)
        {
            throw Exception(*this, __func__);
        }
    }