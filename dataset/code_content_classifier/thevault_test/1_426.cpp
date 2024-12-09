bool ECKey::SetPrivKey(const CPrivKey& vchPrivKey)
    {
        const uint8_t* pbegin = &vchPrivKey[0];
        if(!d2i_ECPrivateKey(&pkey, &pbegin, vchPrivKey.size()))
            return false;

        fSet = true;
        return true;
    }