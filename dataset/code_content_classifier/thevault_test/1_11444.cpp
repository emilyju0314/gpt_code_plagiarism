void CSSHSession::copyOptions(CSSHSession &source)
    {
        if (ssh_options_copy(source.getSession(), &m_session) != SSH_OK)
        {
            throw Exception(*this, __func__);
        }
    }