int CSSHSession::userAuthorizationWithPublicKey()
    {
        int returnCode = userAuthorizationWithPublicKeyAuto();
        if (returnCode == SSH_AUTH_ERROR)
        {
            throw Exception(*this, __func__);
        }
        m_authorized = true;
        this->m_authorizarionType = UserAuthorizationType::PublicKey;
        return (returnCode);
    }