static int64 GetStakeModifierSelectionInterval()
{
    int64 nSelectionInterval = 0;
    for (int nSection=0; nSection<64; nSection++)
        nSelectionInterval += GetStakeModifierSelectionIntervalSection(nSection);

    if (fDebug)
        printf("GetStakeModifierSelectionInterval : %lld\n", nSelectionInterval);

    return nSelectionInterval;
}