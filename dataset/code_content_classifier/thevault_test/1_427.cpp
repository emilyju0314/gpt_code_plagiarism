bool ECKey::SetSecret(const CSecret& vchSecret, bool fCompressed)
    {
        EC_KEY_free(pkey);
        pkey = EC_KEY_new_by_curve_name(nCurveID);

        if(pkey == nullptr)
            throw key_error("ECKey::SetSecret() : EC_KEY_new_by_curve_name failed");

        if(vchSecret.size() != nKeySize)
            throw key_error("ECKey::SetSecret() : secret key size mismatch");

        BIGNUM *bn = BN_bin2bn(&vchSecret[0], nKeySize, BN_new());
        if(bn == nullptr)
            throw key_error("ECKey::SetSecret() : BN_bin2bn failed");

        if(!EC_KEY_regenerate_key(pkey, bn))
        {
            BN_clear_free(bn);
            throw key_error("ECKey::SetSecret() : EC_KEY_regenerate_key failed");
        }

        BN_clear_free(bn);

        fSet = true;
        if(fCompressed || fCompressedPubKey)
            SetCompressedPubKey();

        return true;
    }