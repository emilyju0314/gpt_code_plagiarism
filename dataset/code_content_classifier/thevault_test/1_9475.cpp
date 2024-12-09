double utc2lmst (long mjd, double utc)
{
    double lmst = utc2gmst (mjd, utc) + get_observatory_longitude() / TWOPI;
    if (lmst < 0.0) {
        lmst += 1.0;
    }
    if (lmst >= 1.0) {
        lmst -= 1.0;
    }
    return lmst;
}