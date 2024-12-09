size_t GetLogicalProcessorCacheSizeFromOS()
{
    size_t cache_size = 0;
    DWORD nEntries = 0;

    // Try to use GetLogicalProcessorInformation API and get a valid pointer to the SLPI array if successful.  Returns NULL
    // if API not present or on failure.

    SYSTEM_LOGICAL_PROCESSOR_INFORMATION *pslpi = GetLPI(&nEntries) ;   

    if (pslpi == NULL)
    {
        // GetLogicalProcessorInformation not supported or failed.  
        goto Exit;
    }

    // Crack the information. Iterate through all the SLPI array entries for all processors in system.
    // Will return the greatest of all the processor cache sizes or zero
    {
        size_t last_cache_size = 0;

        for (DWORD i=0; i < nEntries; i++)
        {
            if (pslpi[i].Relationship == RelationCache)
            {
                last_cache_size = max(last_cache_size, pslpi[i].Cache.Size);
            }             
        }  
        cache_size = last_cache_size;
    }
Exit:

    if(pslpi)
        delete[] pslpi;  // release the memory allocated for the SLPI array.    

    return cache_size;
}