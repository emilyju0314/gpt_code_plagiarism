void CSFTP::close()
    {
        if (m_sftp)
        {
            sftp_free(m_sftp);
            m_sftp = NULL;
        }
        // Free IO Buffer
        m_ioBuffer.reset();
    }