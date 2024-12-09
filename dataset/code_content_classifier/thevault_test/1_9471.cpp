void utc2ut0 (long mjd, double utc, long &ut0_mjd, double &ut0)
{
    long ut1_mjd = ut0_mjd = mjd;
    double ut1;
    utc2ut1(mjd, utc, ut1_mjd, ut1);
    
    double x, y;
    if (!get_pole_offsets(mjd, utc, x, y)) {
	ut0 = ut1;
	return;
    }
    x /= 1296000.0;		// convert arcseconds into days
    y /= 1296000.0;
    double lon = get_observatory_longitude();
    double lat = get_observatory_geoc_latitude();
    ut0 = ut1 + tan(lat) * (x * sin(lon) + y * cos(lon));
    ut0_mjd = ut1_mjd;
    if (ut0 < 0.0) {
	ut0 += 1.0;
	ut0_mjd--;
    }
    if (ut0 > 1.0) {
	ut0 -= 1.0;
	ut0_mjd++;
    }
}