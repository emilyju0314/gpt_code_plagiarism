int ZipRawUncompress(void* pUncompressed, size_t* pDestSize, const void* pCompressed, size_t nSrcSize)
    {
        int nReturnCode = Z_OK;

        //check first 4 bytes to see what compression codec was used
        if (CompressionCodec::TestForZSTDMagic(pCompressed))
        {
            size_t result = ZSTD_decompress(pUncompressed, *pDestSize, pCompressed, nSrcSize);

            if (ZSTD_isError(result))
            {
                AZ_Error("ZipDirStructures", false, "Error decompressing using zstd: %s", ZSTD_getErrorName(result));
                nReturnCode = Z_BUF_ERROR;
            }
            else
            {
                *pDestSize = result;
            }
            return nReturnCode;
        }
        else if (CompressionCodec::TestForLZ4Magic(pCompressed))
        {
            size_t result;
            LZ4F_decompressionContext_t dctx;
            result = LZ4F_createDecompressionContext(&dctx, LZ4F_VERSION);
            if (LZ4F_isError(result))
            {
                AZ_Error("ZipDirStructures", false, "Error creating lz4 decompression context: %s", LZ4F_getErrorName(result));
                return Z_BUF_ERROR;
            }

            size_t dstSize = *pDestSize;
            size_t srcSize = nSrcSize;
            result = LZ4F_decompress(dctx, pUncompressed, &dstSize, pCompressed, &srcSize, nullptr);
            if (LZ4F_isError(result))
            {
                AZ_Error("ZipDirStructures", false, "Error decompressing using lz4: %s", LZ4F_getErrorName(result));
                nReturnCode = Z_BUF_ERROR;
            }
            else
            {
                *pDestSize = dstSize;
            }

            size_t freeCode = LZ4F_freeDecompressionContext(dctx);
            if (LZ4F_isError(freeCode))
            {
                //We are not changing the return code in this case, but it is good to record that releasing the
                //decompression context failed.
                AZ_Error("ZipDirStructures", false, "Error releasing lz4 decompression context: %s", LZ4F_getErrorName(freeCode));
            }

            return nReturnCode;
        }

        //fallback to zlib
        ZipDirStructuresInternal::ZlibInflateElement_Impl(pCompressed, pUncompressed, nSrcSize, *pDestSize, pDestSize, &nReturnCode);

        return nReturnCode;
    }