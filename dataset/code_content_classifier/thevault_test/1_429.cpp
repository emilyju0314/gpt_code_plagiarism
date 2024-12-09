CPrivKey ECKey::GetPrivKey() const
    {
        int nSize = i2d_ECPrivateKey(pkey, nullptr);
        if(!nSize)
            throw key_error("ECKey::GetPrivKey() : i2d_ECPrivateKey failed");

        CPrivKey vchPrivKey(nSize, 0);
        uint8_t* pbegin = &vchPrivKey[0];
        if(i2d_ECPrivateKey(pkey, &pbegin) != nSize)
            throw key_error("ECKey::GetPrivKey() : i2d_ECPrivateKey returned unexpected size");

        return vchPrivKey;
    }