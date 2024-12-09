std::string CSSHSession::getCipherOut()
    {
        std::string cipherOut;
        const char *cipher = ssh_get_cipher_in(m_session);
        if (cipher == NULL)
        {
            throw Exception(*this, __func__);
        }
        cipherOut.assign(&cipher[0], &cipher[std::strlen(cipher)]);
        return (cipherOut);
    }