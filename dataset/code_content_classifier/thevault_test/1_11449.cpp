CSFTP::File CSFTP::openFile(const std::string &fileName, int accessType, int mode)
    {
        File fileHandle{sftp_open(m_sftp, fileName.c_str(), accessType, mode)};
        if (fileHandle.get() == NULL)
        {
            throw Exception(*this, __func__);
        }
        return (fileHandle);
    }