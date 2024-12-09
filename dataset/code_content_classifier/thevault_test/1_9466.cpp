int utc2tai (long mjd, double utc, long &tai_mjd, double &tai)
{
    tai_mjd = mjd;
    tai = utc;
    tai += get_leap_sec(mjd, utc) / 86400.0;
    if (tai >= 1.0) {
        tai -= 1.0;
        tai_mjd++;
    }
    return 1;
}