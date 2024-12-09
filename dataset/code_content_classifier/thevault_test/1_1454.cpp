const Geometry *
GEOSGetGeometryN_r(GEOSContextHandle_t extHandle, const Geometry *g1, int n)
{
    if ( 0 == extHandle )
    {
        return NULL;
    }

    GEOSContextHandleInternal_t *handle = 0;
    handle = reinterpret_cast<GEOSContextHandleInternal_t*>(extHandle);
    if ( 0 == handle->initialized )
    {
        return NULL;
    }

    try
    {
        using geos::geom::GeometryCollection;
        const GeometryCollection *gc = dynamic_cast<const GeometryCollection *>(g1);
        if ( ! gc )
        {
            handle->ERROR_MESSAGE("Argument is not a GeometryCollection");
            return NULL;
        }
        return gc->getGeometryN(n);
    }
    catch (const std::exception &e)
    {
        handle->ERROR_MESSAGE("%s", e.what());
    }
    catch (...)
    {
        handle->ERROR_MESSAGE("Unknown exception thrown");
    }
    
    return NULL;
}