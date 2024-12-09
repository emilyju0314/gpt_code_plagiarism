int utc2tdb (long mjd, double utc, long &tdb_mjd, double &tdb)
{
    long tt_mjd;             // Terrestrial coordinate time MJD
    double tt;               // Terrestrial coordinate time
    if (!utc2tt (mjd, utc, tt_mjd, tt)) {
        return 0;
    }
    long ut1_mjd;            // actual earth rotation time MJD
    double ut1;              // actual earth rotation time
    utc2ut1 (mjd, utc, ut1_mjd, ut1);
    
    double obs_long = get_observatory_longitude();
    double obs_r = get_observatory_radius() / 1000.0;
    double obs_z = get_observatory_z() / 1000.0;
    tdb = tt + iauDtdb(2400000.5, (double)tt_mjd + tt, ut1, obs_long,
		       obs_r, obs_z) / 86400.0;
    tdb_mjd = tt_mjd;
    if (tdb > 1.0) {
        tdb -= 1.0;
        tdb_mjd++;
    }
    if (tdb < 0.0) {
        tdb += 1.0;
        tdb_mjd--;
    }
    return 1;
}