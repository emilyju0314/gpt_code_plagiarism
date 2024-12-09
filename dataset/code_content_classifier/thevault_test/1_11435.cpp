Antik::SSH::CSSHSession::Key CSSHSession::getPublicKey()
    {
        Key serverPublicKey;
        ssh_key key;
        if (ssh_get_server_publickey(m_session, &key) != SSH_OK)
        {
            return (serverPublicKey);
        }
        serverPublicKey.reset(key);
        return (serverPublicKey);
    }