ECKey::ECKey(const ECKey& b)
    : pkey(EC_KEY_dup(b.pkey))
    , fSet(b.fSet)
    , fCompressedPubKey(b.fCompressedPubKey)
    , nCurveID(b.nCurveID)
    , nKeySize(b.nKeySize)
    {
        if(pkey == nullptr)
            throw key_error("ECKey::ECKey(const ECKey&) : EC_KEY_dup failed");
    }