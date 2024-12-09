int CSSHSession::userAuthorizationWithPassword()
    {
        int returnCode = ssh_userauth_password(m_session, NULL, m_password.c_str());
        if (returnCode == SSH_AUTH_ERROR)
        {
            throw Exception(*this, __func__);
        }
        m_authorized = true;
        this->m_authorizarionType = UserAuthorizationType::Password;
        return (returnCode);
    }