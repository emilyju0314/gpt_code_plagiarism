void ZlibInflateElement_Impl(const void* pCompressed, void* pUncompressed, size_t compressedSize, size_t nUnCompressedSize, size_t* pUncompressedSize, int* pReturnCode)
    {
        int err;
        z_stream stream;

        Bytef* pIn = const_cast<Bytef*>(static_cast<const Bytef*>(pCompressed));
        uInt nIn = static_cast<uInt>(compressedSize);

        stream.next_out = static_cast<Bytef*>(pUncompressed);
        stream.avail_out = static_cast<uInt>(nUnCompressedSize);

        stream.zalloc = &ZlibAlloc;
        stream.zfree = &ZlibFree;
        stream.opaque = &AZ::AllocatorInstance<AZ::OSAllocator>::Get();

        err = inflateInit2(&stream, -MAX_WBITS);
        if (err != Z_OK)
        {
            *pReturnCode = err;
            return;
        }

        // If src/dst overlap (in place decompress), then inflate in chunks, copying src locally to ensure
        // pointers don't foul each other.
        if ((pIn + nIn) <= stream.next_out || pIn >= (stream.next_out + stream.avail_out))
        {
            stream.next_in = pIn;
            stream.avail_in = nIn;

            // for some strange reason, passing Z_FINISH doesn't work -
            // it seems the stream isn't finished for some files and
            // inflate returns an error due to stream-end-not-reached (though expected) problem
            err = inflate(&stream, Z_SYNC_FLUSH);
        }
        else
        {
            UncompressLookahead lookahead;
            ZlibOverlapInflate(&err, &stream, lookahead, (uint8_t*)pUncompressed, nUnCompressedSize, (uint8_t*)pCompressed, compressedSize);
        }

        if (err != Z_STREAM_END && err != Z_OK)
        {
            inflateEnd(&stream);
            *pReturnCode = err == Z_OK ? Z_BUF_ERROR : err;
            return;
        }

        *pUncompressedSize = stream.total_out;

        err = inflateEnd(&stream);
        *pReturnCode = err;
    }