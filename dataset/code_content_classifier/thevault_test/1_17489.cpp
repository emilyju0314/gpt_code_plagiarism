bool IsInRect (float x, float y, const float bounds_ltrb[4])
{
    return ((bounds_ltrb[0] <= x) && (x < bounds_ltrb[2]) &&
            (bounds_ltrb[3] <= y) && (y < bounds_ltrb[1]));
}