bool ECKey::SetPubKey(const std::vector<uint8_t>& vchPubKey)
    {
        const uint8_t* pbegin = &vchPubKey[0];
        if(!o2i_ECPublicKey(&pkey, &pbegin, vchPubKey.size()))
            return false;

        fSet = true;
        if(vchPubKey.size() >= 33)
            SetCompressedPubKey();

        return true;
    }