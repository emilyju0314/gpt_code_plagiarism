CSSHSession::~CSSHSession()
    {
        if (m_session)
        {
            ssh_free(m_session);
            m_session = NULL;
        }
    }