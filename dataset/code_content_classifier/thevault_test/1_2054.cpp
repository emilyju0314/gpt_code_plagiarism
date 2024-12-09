inline void dsadd(dfloat dsc, const dfloat dsa, const dfloat dsb)
{
    // Compute dsa + dsb using Knuth's trick.
    float t1 = dsa[0] + dsb[0];
    float e = t1 - dsa[0];
    float t2 = ((dsb[0] - e) + (dsa[0] - (t1 - e))) + dsa[1] + dsb[1];

    // The result is t1 + t2, after normalization.
    dsc[0] = e = t1 + t2;
    dsc[1] = t2 - (e - t1);
}