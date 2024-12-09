int tai2utc (long tai_mjd, double tai, long &mjd, double &utc)
{
    mjd = tai_mjd;
    double ls = get_leap_sec(tai_mjd, tai);
    utc = tai - ls / 86400.0;
    if (utc < 0.0) {
	utc += 1.0;
	mjd--;
    }
    if (ls > (get_leap_sec(mjd, utc) + 0.00001)) {
	utc += 1.0 / 86400.0;
	if (utc >= 1.0) {
	    utc -= 1.0;
	    mjd++;
	}
    }
    return 1;
}