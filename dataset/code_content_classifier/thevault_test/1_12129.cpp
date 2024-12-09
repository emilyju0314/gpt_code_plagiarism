int ZipRawCompress(const void* pUncompressed, size_t* pDestSize, void* pCompressed, size_t nSrcSize, int nLevel)
    {
        z_stream stream;
        int err;

        stream.next_in = const_cast<Bytef*>(static_cast<const Bytef*>(pUncompressed));
        stream.next_out = reinterpret_cast<Bytef*>(pCompressed);


        stream.avail_in = static_cast<uInt>(nSrcSize);
        stream.avail_out = static_cast<uInt>(*pDestSize);

        AZ_Assert(AZ::AllocatorInstance<AZ::OSAllocator>::IsReady(), "OS Allocator must be ready in order to override zlib allocator");
        stream.zalloc = &ZipDirStructuresInternal::ZlibAlloc;
        stream.zfree = &ZipDirStructuresInternal::ZlibFree;
        stream.opaque = &AZ::AllocatorInstance<AZ::OSAllocator>::Get();

        err = deflateInit2(&stream, nLevel, Z_DEFLATED, -MAX_WBITS, 9, Z_DEFAULT_STRATEGY);
        if (err != Z_OK)
        {
            return err;
        }

        err = deflate(&stream, Z_FINISH);
        if (err != Z_STREAM_END)
        {
            deflateEnd(&stream);
            return err == Z_OK ? Z_BUF_ERROR : err;
        }
        *pDestSize = stream.total_out;

        err = deflateEnd(&stream);
        return err;
    }