bool IsSporkActive(int nSporkID)
{
    int64_t r = 0;

    if(mapSporksActive.count(nSporkID)){
        r = mapSporksActive[nSporkID].nValue;
    } else {
        if(nSporkID == SPORK_1_FORTUNASTAKE_PAYMENTS_ENFORCEMENT) r = SPORK_1_FORTUNASTAKE_PAYMENTS_ENFORCEMENT_DEFAULT;
        if(nSporkID == SPORK_2_MAX_VALUE) r = SPORK_2_MAX_VALUE_DEFAULT;
        if(nSporkID == SPORK_3_REPLAY_BLOCKS) r = SPORK_3_REPLAY_BLOCKS_DEFAULT;

        if(r == 0 && fDebug) printf("GetSpork::Unknown Spork %d\n", nSporkID);
    }
    if(r == 0) r = 4070908800; //return 2099-1-1 by default

    return r < GetTime();
}