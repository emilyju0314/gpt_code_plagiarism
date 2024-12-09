const Geometry *
GEOSGetGeometryN(const Geometry *g1, int n)
{
    return GEOSGetGeometryN_r( handle, g1, n );
}