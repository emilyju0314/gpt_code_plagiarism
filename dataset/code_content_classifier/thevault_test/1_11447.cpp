void CSFTP::open()
    {
        if (sftp_init(m_sftp) != SSH_OK)
        {
            sftp_free(m_sftp);
            m_sftp = NULL;
            throw Exception(*this, __func__);
        }
    }