bool static IsDERSignature(const valtype &vchSig) {

    if (vchSig.size() < 9) {
        //  Non-canonical signature: too short
        return false;
    }
    if (vchSig.size() > 73) {
        // Non-canonical signature: too long
        return false;
    }
    if (vchSig[0] != 0x30) {
        //  Non-canonical signature: wrong type
        return false;
    }
    if (vchSig[1] != vchSig.size()-3) {
        //  Non-canonical signature: wrong length marker
        return false;
    }
    unsigned int nLenR = vchSig[3];
    if (5 + nLenR >= vchSig.size()) {
        //  Non-canonical signature: S length misplaced
        return false;
    }
    unsigned int nLenS = vchSig[5+nLenR];
    if ((unsigned long)(nLenR+nLenS+7) != vchSig.size()) {
        //  Non-canonical signature: R+S length mismatch
        return false;
    }

    const unsigned char *R = &vchSig[4];
    if (R[-2] != 0x02) {
        //  Non-canonical signature: R value type mismatch
        return false;
    }
    if (nLenR == 0) {
        //  Non-canonical signature: R length is zero
        return false;
    }
    if (R[0] & 0x80) {
        //  Non-canonical signature: R value negative
        return false;
    }
    if (nLenR > 1 && (R[0] == 0x00) && !(R[1] & 0x80)) {
        //  Non-canonical signature: R value excessively padded
        return false;
    }

    const unsigned char *S = &vchSig[6+nLenR];
    if (S[-2] != 0x02) {
        //  Non-canonical signature: S value type mismatch
        return false;
    }
    if (nLenS == 0) {
        //  Non-canonical signature: S length is zero
        return false;
    }
    if (S[0] & 0x80) {
        //  Non-canonical signature: S value negative
        return false;
    }
    if (nLenS > 1 && (S[0] == 0x00) && !(S[1] & 0x80)) {
        //  Non-canonical signature: S value excessively padded
        return false;
    }
    return true;
}