inline void dsdeq(dfloat a, double b)
{
    a[0] = (float)b;
    a[1] = (float)(b - a[0]);
}