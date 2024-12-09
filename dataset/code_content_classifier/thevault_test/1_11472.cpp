int CSFTP::getErrorCode() const
    {
        int errorCode = sftp_get_error(m_sftp);
        return (errorCode);
    }