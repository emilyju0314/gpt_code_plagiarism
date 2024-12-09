bool ECKey::SetCompactSignature(uint256_t hash, const std::vector<uint8_t>& vchSig)
    {
        if(vchSig.size() != 145)
            return false;

        int nV = vchSig[0];
        if(nV<27 || nV>=35)
            return false;

        ECDSA_SIG* sig = ECDSA_SIG_new();
        if(nullptr == sig)
            return false;

        #if OPENSSL_VERSION_NUMBER > 0x10100000L
            // sig_r and sig_s will be deallocated by ECDSA_SIG_free(sig)
            BIGNUM* sig_r = BN_bin2bn(&vchSig[1], 72, BN_new());
            BIGNUM* sig_s = BN_bin2bn(&vchSig[73], 72, BN_new());

            if((sig_r == nullptr) || (sig_s == nullptr))
            {
                ECDSA_SIG_free(sig);
                throw key_error("CKey::VerifyCompact() : r or s can't be null");
            }

            // set r and s values, this transfers ownership to the ECDSA_SIG object
            ECDSA_SIG_set0(sig, sig_r, sig_s);
        #else
            BN_bin2bn(&vchSig[1], 72, sig->r);
            BN_bin2bn(&vchSig[73], 72, sig->s);
        #endif

        EC_KEY_free(pkey);
        pkey = EC_KEY_new_by_curve_name(NID_sect571r1);
        if(nV >= 31)
        {
            SetCompressedPubKey();
            nV -= 4;
        }

        #if OPENSSL_VERSION_NUMBER > 0x10100000L
        if(ECDSA_SIG_recover_key_GFp(pkey, sig_r, sig_s, (unsigned char*)&hash, sizeof(hash), nV - 27, 0) == 1)
        {
            fSet = true;
            ECDSA_SIG_free(sig);
            return true;
        }
        #else
        if(ECDSA_SIG_recover_key_GFp(pkey, sig->r, sig->s, (unsigned char*)&hash, sizeof(hash), nV - 27, 0) == 1)
        {
            fSet = true;
            ECDSA_SIG_free(sig);
            return true;
        }
        #endif

        ECDSA_SIG_free(sig);
        return false;
    }