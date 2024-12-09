double utc2last (long mjd, double utc)
{
    double last = utc2gast (mjd, utc) + get_observatory_longitude() / TWOPI;
    if (last < 0.0) {
        last += 1.0;
    }
    if (last >= 1.0) {
        last -= 1.0;
    }
    return last;
}