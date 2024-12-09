void utc2ut2 (long mjd, double utc, long &ut2_mjd, double &ut2)
{
    long ut1_mjd;
    double ut1;
    utc2ut1(mjd, utc, ut1_mjd, ut1);
    double arg = TWOPI * (2000.0 + ((double)ut1_mjd + ut1 - 51544.03))
								/ 365.2422;
    ut2 = ut1 + (0.022 * sin(arg) - 0.012 * cos(arg)
		 - 0.006 * sin(2.0 * arg) + 0.007 * cos(2.0 * arg)) / 86400.0;
    ut2_mjd = ut1_mjd;
    if (ut2 < 0.0) {
	ut2 += 1.0;
	ut2_mjd--;
    }
    if (ut2 > 1.0) {
	ut2 -= 1.0;
	ut2_mjd++;
    }
}