void CSSHSession::writeKnownHost()
    {
        if (ssh_session_update_known_hosts(m_session) != SSH_OK)
        {
            throw Exception(*this, __func__);
        }
    }