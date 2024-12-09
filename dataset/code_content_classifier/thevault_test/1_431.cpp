std::vector<uint8_t> ECKey::GetPubKey() const
    {
        int nSize = i2o_ECPublicKey(pkey, nullptr);
        if(!nSize)
            throw key_error("ECKey::GetPubKey() : i2o_ECPublicKey failed");

        std::vector<uint8_t> vchPubKey(nSize, 0);

        uint8_t* pbegin = &vchPubKey[0];
        if(i2o_ECPublicKey(pkey, &pbegin) != nSize)
            throw key_error("ECKey::GetPubKey() : i2o_ECPublicKey returned unexpected size");

        return vchPubKey;
    }