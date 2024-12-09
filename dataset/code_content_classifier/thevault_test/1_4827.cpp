unsigned int static ComputeMaxBits(CBigNum bnTargetLimit, unsigned int nBase, int64 nTime)
{
    // Testnet has min-difficulty blocks
    // after nTargetSpacing*2 time between blocks:
    if (fTestNet && nTime > nTargetSpacing*2)
        return bnTargetLimit.GetCompact();

    CBigNum bnResult;
    bnResult.SetCompact(nBase);
    while (nTime > 0 && bnResult < bnTargetLimit)
    {
 if ( fTestNet ){
if(nBestHeight+1<NDIFF_START_DIGISHIELD_TESTNET){
// Maximum 400% adjustment...
bnResult *= 4;
// ... in best-case exactly 4-times-normal target time
nTime -= nTargetTimespan*4;
} else {
// Maximum 10% adjustment...
bnResult = (bnResult * 110) / 100;
// ... in best-case exactly 4-times-normal target time
nTime -= nTargetTimespanNEW*4;
}
}else{
if(nBestHeight+1<NDIFF_START_DIGISHIELD){
// Maximum 400% adjustment...
bnResult *= 4;
// ... in best-case exactly 4-times-normal target time
nTime -= nTargetTimespan*4;
} else {
// Maximum 10% adjustment...
bnResult = (bnResult * 110) / 100;
// ... in best-case exactly 4-times-normal target time
nTime -= nTargetTimespanNEW*4;
}
}
    }
    if (bnResult > bnTargetLimit)
        bnResult = bnTargetLimit;
    return bnResult.GetCompact();
}