void CacheFactory::Seek(uint32_t nPos, int nOrigin) // throw
    {
        if (FSeek(&m_fileExt, nPos, nOrigin))
        {
            AZ_Warning("Archive", false, "ZD_ERROR_IO_FAILED: Cannot fseek() to the new position in the file. This is unexpected error and should not happen under any circumstances. Perhaps some network or disk failure error has caused this");
            return;
        }
    }