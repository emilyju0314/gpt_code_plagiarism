double utc2gmst (long mjd, double utc)
{
    long ut1_mjd;
    double ut1;
    utc2ut1 (mjd, utc, ut1_mjd, ut1);
    return iauGmst82 (2400000.5, (double)ut1_mjd + ut1) / TWOPI;
}