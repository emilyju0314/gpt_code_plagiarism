const Geometry *
GEOSGetExteriorRing(const Geometry *g1)
{
    return GEOSGetExteriorRing_r( handle, g1 );
}