int utc2tt (long mjd, double utc, long &tt_mjd, double &tt)
{
    long tai_mjd;             // International Atomic Time MJD
    double tai;               // International Atomic Time

    if (!utc2tai (mjd, utc, tai_mjd, tai)) {
        return 0;
    }
    tt = tai + 32.184 / 86400.0;
    tt_mjd = tai_mjd;
    if (tt >= 1.0) {
        tt -= 1.0;
        tt_mjd++;
    }
    return 1;
}