int64_t GetCoinAgeWeight(int64_t nIntervalBeginning, int64_t nIntervalEnd)
{
    if (nIntervalBeginning <= 0) {
        LogPrintf("WARNING *** GetCoinAgeWeight: nIntervalBeginning (%d) <= 0\n", nIntervalBeginning);
        return 0;
    }

    int64_t nSeconds = max((int64_t)0, nIntervalEnd - nIntervalBeginning - Params().StakeMinAge());
    double days = double(nSeconds) / (24 * 60 * 60);
    double weight = 0;

    if (days <= 7) {
        weight = -0.00408163 * pow(days, 3) + 0.05714286 * pow(days, 2) + days;
    } else {
        weight = 8.4 * log(days) - 7.94564525;
    }

    return min((int64_t)(weight * 24 * 60 * 60), (int64_t)Params().StakeMaxAge());
}