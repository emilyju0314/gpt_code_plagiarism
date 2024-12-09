void CSSHSession::getPublicKeyHash(Antik::SSH::CSSHSession::Key &serverPublicKey, std::vector<unsigned char> &keyHash)
    {
        unsigned char *hash = NULL;
        size_t hlen;
        if (ssh_get_publickey_hash(serverPublicKey.get(), SSH_PUBLICKEY_HASH_SHA1, &hash, &hlen) != SSH_OK)
        {
            throw Exception(*this, __func__);
        }
        keyHash.assign(&hash[0], &hash[hlen]);
        ssh_clean_pubkey_hash(&hash);
    }