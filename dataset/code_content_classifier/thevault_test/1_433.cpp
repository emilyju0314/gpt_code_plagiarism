bool ECKey::Sign(const std::vector<uint8_t>& vchData, std::vector<uint8_t>& vchSig) const
    {
        uint32_t nSize = ECDSA_size(pkey);
        vchSig.resize(nSize); // Make sure it is big enough

        /* Attempt the ECDSA Signing Operation. */
        if(ECDSA_sign(0, &vchData[0], static_cast<int32_t>(vchData.size()), &vchSig[0], &nSize, pkey) != 1)
        {
            vchSig.clear();
            return debug::error("Failed to Sign");
        }

        vchSig.resize(nSize);
        if(!Encoding(vchSig))
            return Sign(vchData, vchSig);

        return true;
    }