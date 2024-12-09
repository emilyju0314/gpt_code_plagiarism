std::string CSSHSession::getCipherIn()
    {
        std::string cipherIn;
        const char *cipher = ssh_get_cipher_in(m_session);
        if (cipher == NULL)
        {
            throw Exception(*this, __func__);
        }
        cipherIn.assign(&cipher[0], &cipher[std::strlen(cipher)]);
        return (cipherIn);
    }