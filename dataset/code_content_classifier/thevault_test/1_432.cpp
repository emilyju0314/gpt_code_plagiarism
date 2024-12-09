bool ECKey::Encoding(const std::vector<uint8_t>& vchSig) const
    {
        /* Check the signature length. Strict encoding requires no more than 135 bytes. */
        if(vchSig.size() != 135) return false;

        /* Leading byte needs to be 0x30 (compound) */
        if(vchSig[0] != 0x30) return false;

        /* Ensure length is within range of first length indicator. */
        if(vchSig[1] != vchSig.size() - 6)
            return debug::error("length mismatch byte 1 ", vchSig[1], " ", vchSig.size());

        /* Ensure length is within range of second length indicator. */
        if(vchSig[2] != vchSig.size() - 3)
            return debug::error("length mismatch byte 2 ", vchSig[2], " - ", vchSig.size());

        /* Byte 3 needs to indicate integer value for R (0x02) */
        if(vchSig[3] != 0x02)
            return debug::error("R is not an integer");

        /* Byte 4 is length of R value. Extract it. */
        uint32_t lenR = vchSig[4];

        /* Enforce strict rule of 64 byte R value. */
        if(lenR != nKeySize)
            return false;

        /* Make sure R value is not negative (0x80). */
        if(vchSig[5] & 0x80)
            return debug::error("negatives not allowed for R");

        /* No Null value to pad R, unless interpreted as negative. */
        if((vchSig[5] == 0x00) && !(vchSig[6] & 0x80))
            return debug::error("no null bytes at start of R");

        /* Ensure S is flagged as integer (0x02) */
        if(vchSig[5 + lenR] != 0x02)
            return debug::error("S is not an integer");

        /* Extract the length of S. */
        uint32_t lenS = vchSig[6 + lenR];

        /* Enforce strict rule of 64 byte S value. */
        if(lenS != nKeySize)
            return false;

        /* Make sure S value is not negative (0x80) */
        if(vchSig[lenR + 7] & 0x80)
            return debug::error("no negatives allowed for S");

        /* No Null value to pad S, unless interpreted as negative. */
        if((vchSig[lenR + 7] == 0x00) && !(vchSig[lenR + 8] & 0x80))
            return debug::error("no null bytes at start of S");

        return true;
    }