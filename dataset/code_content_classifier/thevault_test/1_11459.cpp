void CSFTP::getLinkAttributes(const std::string &linkPath, FileAttributes &fileAttributes)
    {
        sftp_attributes file = sftp_lstat(m_sftp, linkPath.c_str());
        if (file == NULL)
        {
            throw Exception(*this, __func__);
        }
        fileAttributes.reset(file);
    }