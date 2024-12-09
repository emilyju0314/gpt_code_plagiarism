static double
ML_VaxFloat(unsigned nVaxFloat)
{
    union {
        unsigned        nVax;
        float           fIEEE;
        unsigned char   rgnBytes[4];
    } u;
    unsigned char nTmp;

    u.nVax = nVaxFloat;
    nTmp = u.rgnBytes[0];
    u.rgnBytes[0] = u.rgnBytes[2];
    u.rgnBytes[2] = nTmp;
    nTmp = u.rgnBytes[3];
    u.rgnBytes[3] = u.rgnBytes[1];
    u.rgnBytes[1] = nTmp;
    return double(u.fIEEE)/4.0;     // avoid underflow by going to double
}