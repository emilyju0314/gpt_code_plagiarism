int
GEOSGetNumGeometries(const Geometry *g1)
{
    return GEOSGetNumGeometries_r( handle, g1 );
}