bool ECKey::SignCompact(uint256_t hash, std::vector<uint8_t>& vchSig)
    {
        bool fOk = false;

        ECDSA_SIG *sig = ECDSA_do_sign((unsigned char*)&hash, sizeof(hash), pkey);
        if(sig == nullptr)
            throw key_error("CKey::SignCompact() : Failed to make signature");

        vchSig.clear();
        vchSig.resize(145,0);

        const BIGNUM *sig_r = nullptr;
        const BIGNUM *sig_s = nullptr;
        int nBitsR = 0;
        int nBitsS = 0;

    #if OPENSSL_VERSION_NUMBER >= 0x10100000L
        ECDSA_SIG_get0(sig, &sig_r, &sig_s);

        nBitsR = BN_num_bits(sig_r);
        nBitsS = BN_num_bits(sig_s);
    #else
        sig_r = sig->r;
        sig_s = sig->s;

        nBitsR = BN_num_bits(sig->r);
        nBitsS = BN_num_bits(sig->s);
    #endif


        if(nBitsR <= 571 && nBitsS <= 571)
        {
            int nRecId = -1;
            for(int i=0; i < 9; ++i)
            {
                ECKey keyRec;
                keyRec.fSet = true;
                if(fCompressedPubKey)
                    keyRec.SetCompressedPubKey();

                if(ECDSA_SIG_recover_key_GFp(keyRec.pkey, const_cast<BIGNUM *>(sig_r), const_cast<BIGNUM *>(sig_s), (unsigned char*)&hash, sizeof(hash), i, 1) == 1)
                {
                    if(keyRec.GetPubKey() == this->GetPubKey())
                    {
                        nRecId = i;
                        break;
                    }
                }
            }

            if(nRecId == -1)
            {
                ECDSA_SIG_free(sig);
                throw key_error("CKey::SignCompact() : unable to construct recoverable key");
            }

            vchSig[0] = static_cast<uint8_t>(nRecId+27+(fCompressedPubKey ? 4 : 0));

            BN_bn2bin(sig_r, &vchSig[73-(nBitsR+7)/8]);
            BN_bn2bin(sig_s, &vchSig[145-(nBitsS+7)/8]);

            fOk = true;
        }
        ECDSA_SIG_free(sig);

        return fOk;
    }