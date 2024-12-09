void ECKey::MakeNewKey(bool fCompressed)
    {
        EC_KEY_free(pkey);
        pkey = EC_KEY_new_by_curve_name(nCurveID);

        if(!EC_KEY_generate_key(pkey))
            throw key_error("ECKey::MakeNewKey() : EC_KEY_generate_key failed");

        if(fCompressed)
            SetCompressedPubKey();
        fSet = true;
    }