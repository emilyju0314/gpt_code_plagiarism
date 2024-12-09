void utc2ut1 (long mjd, double utc, long &ut1_mjd, double &ut1)
{
    ut1_mjd = mjd;
    ut1 = utc + get_ut1_offset(mjd, utc) / 86400.0;
    if (ut1 > 1.0) {
        ut1 -= 1.0;
        ut1_mjd++;
    }
    if (ut1 < 0.0) {
        ut1 += 1.0;
        ut1_mjd--;
    }
}