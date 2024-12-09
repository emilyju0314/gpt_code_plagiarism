uint32_t GCToOSInterface::GetCurrentProcessCpuCount()
{
    static int cCPUs = 0;

    if (cCPUs != 0)
        return cCPUs;

    int count;

    if (CanEnableGCCPUGroups())
    {
        count = GCToOSInterface::GetTotalProcessorCount();
    }
    else
    {
        DWORD_PTR pmask, smask;

        if (!GetProcessAffinityMask(GetCurrentProcess(), &pmask, &smask))
        {
            count = 1;
        }
        else
        {
            count = 0;
            pmask &= smask;

            while (pmask)
            {
                pmask &= (pmask - 1);
                count++;
            }

            // GetProcessAffinityMask can return pmask=0 and smask=0 on systems with more
            // than 64 processors, which would leave us with a count of 0.  Since the GC
            // expects there to be at least one processor to run on (and thus at least one
            // heap), we'll return 64 here if count is 0, since there are likely a ton of
            // processors available in that case.  The GC also cannot (currently) handle
            // the case where there are more than 64 processors, so we will return a
            // maximum of 64 here.
            if (count == 0 || count > 64)
                count = 64;
        }
    }

    cCPUs = count;

    return count;
}