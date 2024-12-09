double GetInflationAdjustment(const CBlockIndex* pindex)
{
    int64_t nStart = GetTimeMicros();
    float nInflationTarget = 0.05;
    double dMaxThreshold = 5;
    double dMinThreshold = .5;
    int64_t nMoneySupply = pindex->pprev->nMoneySupply;

    // some rounding for year/ leap year
    int64_t nBlocksPerDay = 1440; // generate block per 60sec
    int64_t nBlocksPerYear = ((365 * 33 + 8.0) / 33.0) * nBlocksPerDay;
    // month are a consistent period
    int64_t nBlocksPerMonth = nBlocksPerYear / 12;
    int64_t nPoSVRewards = 0;

    bool fProofOfStake = false;

    if (pindex && pindex->nHeight >= Params().LastProofOfWorkHeight()) {
        fProofOfStake = true;
        if (pindex->nHeight - Params().LastProofOfWorkHeight() < nBlocksPerMonth) {
            nBlocksPerMonth = pindex->nHeight - Params().LastProofOfWorkHeight();
        }
    }

    // get previous block interval
    std::string strHash = chainActive[pindex->nHeight - nBlocksPerMonth]->GetBlockHash().GetHex();
    uint256 hash(strHash);

    if (mapBlockIndex.count(hash) == 0)
        LogPrintf("- Hash block missing\n");

    int64_t nMoneySupplyPrev = mapBlockIndex[hash]->nMoneySupply;
    int64_t nHeightPrev = mapBlockIndex[hash]->nHeight;

    nPoSVRewards = nMoneySupply - nMoneySupplyPrev;
    LogPrintf("- PoSV rewards %s in last interval.\n", FormatMoney(nPoSVRewards));

    double nRatio = (double(nMoneySupply) / double(nPoSVRewards));
    double nRawInflationAdjustment = ((nInflationTarget / 12) * nRatio); // looking at the last month of blocks
    double nInflationAdjustment = max(min(nRawInflationAdjustment, dMaxThreshold), dMinThreshold);

    LogPrintf("- Inflation = %s.\n", (double(nPoSVRewards) / double(nMoneySupply)) * 12 * 100);
    LogPrintf("- Inflation Bound Adjustment = %s. Using Max %s | Min %s thresholds\n", nInflationAdjustment, dMaxThreshold, dMinThreshold);

    int64_t nTime = GetTimeMicros() - nStart;

    LogPrint("bench", "- Inflation Unbound Adjustment = %s Using last %s blocks from height %s to height %s: %.2fms\n", nRawInflationAdjustment, nBlocksPerMonth, nHeightPrev, pindex->nHeight, nTime * 0.001);

    return nInflationAdjustment;
}