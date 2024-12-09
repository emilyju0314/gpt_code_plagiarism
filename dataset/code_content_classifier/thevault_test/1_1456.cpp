unsigned char *
GEOSGeomToHEX_buf(const Geometry *g, size_t *size)
{
    return GEOSGeomToHEX_buf_r( handle, g, size );
}