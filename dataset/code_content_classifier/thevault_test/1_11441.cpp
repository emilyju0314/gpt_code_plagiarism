std::string CSSHSession::getHMACIn()
    {
        std::string hmacIn;
        const char *hmac = ssh_get_hmac_in(m_session);
        if (hmac == NULL)
        {
            throw Exception(*this, __func__);
        }
        hmacIn.assign(&hmac[0], &hmac[std::strlen(hmac)]);
        return (hmacIn);
    }