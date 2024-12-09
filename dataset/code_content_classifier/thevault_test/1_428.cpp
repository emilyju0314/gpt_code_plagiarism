CSecret ECKey::GetSecret(bool &fCompressed) const
    {
        CSecret vchRet;
        vchRet.resize(nKeySize);

        const BIGNUM *bn = EC_KEY_get0_private_key(pkey);
        int nBytes = BN_num_bytes(bn);
        if(bn == nullptr)
            throw key_error("ECKey::GetSecret() : EC_KEY_get0_private_key failed");

        int n = BN_bn2bin(bn, &vchRet[nKeySize - nBytes]);
        if(n != nBytes)
            throw key_error("ECKey::GetSecret(): BN_bn2bin failed");

        fCompressed = fCompressedPubKey;
        return vchRet;
    }