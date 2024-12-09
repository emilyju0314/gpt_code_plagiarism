std::string CSSHSession::getKeyExchangeAlgorithm()
    {
        std::string keyExchangeAlg;
        const char *keyexchange = ssh_get_kex_algo(m_session);
        if (keyexchange == NULL)
        {
            throw Exception(*this, __func__);
        }
        keyExchangeAlg.assign(&keyexchange[0], &keyexchange[std::strlen(keyexchange)]);
        return (keyExchangeAlg);
    }