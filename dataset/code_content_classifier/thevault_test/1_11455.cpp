void CSFTP::changeOwnerGroup(const std::string &filePath, const FileOwner &owner, const FileGroup &group)
    {
        if (sftp_chown(m_sftp, filePath.c_str(), owner, group) < 0)
        {
            throw Exception(*this, __func__);
        }
    }