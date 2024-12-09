SYSTEM_LOGICAL_PROCESSOR_INFORMATION *GetLPI(PDWORD nEntries) 
{
    DWORD cbslpi = 0;
    DWORD dwNumElements = 0;
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION *pslpi = NULL;

    // We setup the first call to GetLogicalProcessorInformation to fail so that we can obtain
    // the size of the buffer required to allocate for the SLPI array that is returned

    if (!GetLogicalProcessorInformation(pslpi, &cbslpi) &&
            GetLastError() != ERROR_INSUFFICIENT_BUFFER)
    {
        // If we fail with anything other than an ERROR_INSUFFICIENT_BUFFER here, we punt with failure.
        return NULL;
    }

    _ASSERTE(cbslpi);

    // compute the number of SLPI entries required to hold the information returned from GLPI

    dwNumElements = cbslpi / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);

    // allocate a buffer in the free heap to hold an array of SLPI entries from GLPI, number of elements in the array is dwNumElements 

    pslpi = new (std::nothrow) SYSTEM_LOGICAL_PROCESSOR_INFORMATION[ dwNumElements ];

    if (pslpi == NULL)
    {
        // the memory allocation failed
        return NULL;
    }      

    // Make call to GetLogicalProcessorInformation. Returns array of SLPI structures

    if (!GetLogicalProcessorInformation(pslpi, &cbslpi))
    {
        // GetLogicalProcessorInformation failed
        delete[] pslpi ; //Allocation was fine but the API call itself failed and so we are releasing the memory before the return NULL.
        return NULL ;
    } 

    // GetLogicalProcessorInformation successful, set nEntries to number of entries in the SLPI array
    *nEntries  = dwNumElements;

    return pslpi;    // return pointer to SLPI array

}