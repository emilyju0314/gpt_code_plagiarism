ECKey::ECKey(const uint32_t nID, const uint32_t nKeySizeIn)
    : pkey(nullptr)
    , fSet(false)
    , fCompressedPubKey(false)
    , nCurveID(nID)
    , nKeySize(nKeySizeIn)
    {

        /* Set the Curve Type. */
        switch(nID)
        {
        case SECT_571_R1:
            nCurveID = NID_sect571r1;
            break;
        case BRAINPOOL_P512_T1:
            nCurveID = NID_brainpoolP512t1;
            break;
        default:
            throw key_error("ECKey::ECKey() : Unrecognized EC Type");
        }

        /* Create a new key from the curve type. */
        pkey = EC_KEY_new_by_curve_name(nCurveID);

        /* Check for failure. */
        if(pkey == nullptr)
            throw key_error("ECKey::ECKey() : EC_KEY_new_by_curve_name failed");

    }