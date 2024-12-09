int CSSHSession::userAuthorizationWithPublicKeyAuto()
    {
        int returnCode = ssh_userauth_publickey_auto(m_session, NULL, NULL);
        if (returnCode == SSH_AUTH_ERROR)
        {
            throw Exception(*this, __func__);
        }
        m_authorized = true;
        this->m_authorizarionType = UserAuthorizationType::PublicKey;
        return (returnCode);
    }