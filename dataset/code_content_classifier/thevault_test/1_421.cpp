ECKey::ECKey()
    : pkey(EC_KEY_new_by_curve_name(NID_sect571r1))
    , fSet(false)
    , fCompressedPubKey(false)
    , nCurveID(NID_sect571r1)
    , nKeySize(72)
    {
        /* Check for failure. */
        if(pkey == nullptr)
            throw key_error("ECKey::ECKey() : EC_KEY_new_by_curve_name failed");
    }