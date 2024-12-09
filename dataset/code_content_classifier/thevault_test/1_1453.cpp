unsigned char *
GEOSGeomToHEX_buf_r(GEOSContextHandle_t extHandle, const Geometry *g, size_t *size)
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

    using geos::io::WKBWriter;
    try
    {
        int byteOrder = static_cast<int>(handle->WKBByteOrder);
        WKBWriter w(handle->WKBOutputDims, byteOrder);
        std::ostringstream os(std::ios_base::binary);
        w.writeHEX(*g, os);
        std::string hexstring(os.str());

        char *result = gstrdup(hexstring);
        if (0 != result)
        {
            *size = hexstring.length();
        }

        return reinterpret_cast<unsigned char*>(result);
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