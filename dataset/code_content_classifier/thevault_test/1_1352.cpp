CAmount GetProofOfStakeReward(int64_t nCoinAge, const CAmount& nFees, double fInflationAdjustment)
{
    // some scary rounding dirty trick here for leap / non-leap years
    // CoinAge=365 -> nSubsidy=9993
    // CoinAge=366 -> nSubsidy=10020
    CAmount nSubsidy = (nCoinAge * COIN_YEAR_REWARD * 33 / (365 * 33 + 8)) * fInflationAdjustment;

    LogPrintf("GetProofOfStakeReward(): nSubsidy=%s nCoinAge=%s nFees=%s fInflationAdjustment=%s\n", FormatMoney(nSubsidy).c_str(), nCoinAge, FormatMoney(nFees), fInflationAdjustment);

    if (fDebug && GetBoolArg("-printcreation", false))
        LogPrintf("GetProofOfStakeReward(): nSubsidy=%s nCoinAge=%s nFees=%s\n", FormatMoney(nSubsidy).c_str(), nCoinAge, FormatMoney(nFees));

    return nSubsidy + nFees;
}