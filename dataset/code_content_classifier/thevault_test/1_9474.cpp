double utc2gast (long mjd, double utc)
{
    double gmst = utc2gmst(mjd, utc);
// ------- using the equation of the equinoxes -------
    // first get the Ephemeris Time (actually Terrestrial Dynamic Time)
    long tt_mjd;
    double tt;
    utc2tt (mjd, utc, tt_mjd, tt);
    // then compute and add the equation of the equinoxes
    return gmst + iauEqeq94(2400000.5, (double)tt_mjd + tt) / TWOPI;
// ---------------------------------------------------
/* a longer alternative using full nutation and taking the R.A. component
    double vector[3];
    iauS2c (gmst * TWOPI, 0.0, vector);

    long tt_mjd;
    double tt;
    utc2tt(mjd, utc, tt_mjd, tt);

    double nut_mat[3][3];
    iauNum00a(2400000.5, (double)tt_mjd + tt, nut_mat);

    double new_vector[3];
    iauRxp(nut_mat, vector, new_vector);

    double ra, dec;
    iauC2s(new_vector, &ra, &dec);
    ra /= TWOPI;
    if (ra < 0.0) ra += 1.0;
    if (ra >= 1.0) ra -= 1.0;
    return ra;
*/
}