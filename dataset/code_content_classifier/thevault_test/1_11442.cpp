std::string CSSHSession::getHMACOut()
    {
        std::string hmacOut;
        const char *hmac = ssh_get_hmac_out(m_session);
        if (hmac == NULL)
        {
            throw Exception(*this, __func__);
        }
        hmacOut.assign(&hmac[0], &hmac[std::strlen(hmac)]);
        return (hmacOut);
    }