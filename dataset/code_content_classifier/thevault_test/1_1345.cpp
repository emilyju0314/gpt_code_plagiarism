static int64_t GetStakeModifierSelectionInterval()
{
    int64_t nSelectionInterval = 0;
    for (int nSection = 0; nSection < 64; nSection++)
        nSelectionInterval += GetStakeModifierSelectionIntervalSection(nSection);

    if (fDebug)
        LogPrintf("GetStakeModifierSelectionInterval : %d\n", nSelectionInterval);

    return nSelectionInterval;
}