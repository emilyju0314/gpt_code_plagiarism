bool GCToOSInterface::SetCurrentThreadIdealAffinity(uint16_t srcProcNo, uint16_t dstProcNo)
{
    LIMITED_METHOD_CONTRACT;

    bool success = true;

    GroupProcNo srcGroupProcNo(srcProcNo);
    GroupProcNo dstGroupProcNo(dstProcNo);

    if (CanEnableGCCPUGroups())
    {
        if (srcGroupProcNo.GetGroup() != dstGroupProcNo.GetGroup())
        {
            //only set ideal processor when srcProcNo and dstProcNo are in the same cpu
            //group. DO NOT MOVE THREADS ACROSS CPU GROUPS
            return true;
        }
    }

#if !defined(FEATURE_CORESYSTEM)
    SetThreadIdealProcessor(GetCurrentThread(), (DWORD)dstGroupProcNo.GetProcIndex());
#else
    PROCESSOR_NUMBER proc;

    if (dstGroupProcNo.GetGroup() != GroupProcNo::NoGroup)
    {
        proc.Group = (WORD)dstGroupProcNo.GetGroup();
        proc.Number = (BYTE)dstGroupProcNo.GetProcIndex();
        proc.Reserved = 0;

        success = !!SetThreadIdealProcessorEx(GetCurrentThread(), &proc, NULL);
    }
    else
    {
        if (GetThreadIdealProcessorEx(GetCurrentThread(), &proc))
        {
            proc.Number = (BYTE)dstGroupProcNo.GetProcIndex();
            success = !!SetThreadIdealProcessorEx(GetCurrentThread(), &proc, &proc);
        }
    }
#endif

    return success;
}