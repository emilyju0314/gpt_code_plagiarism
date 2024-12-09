void CSFTP::changeFileModificationAccessTimes(const std::string &filePath, const Time *newTimeValues)
    {
        if (sftp_utimes(m_sftp, filePath.c_str(), newTimeValues) < 0)
        {
            throw Exception(*this, __func__);
        }
    }