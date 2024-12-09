bool GCToOSInterface::SetThreadAffinity(uint16_t procNo)
{
    GroupProcNo groupProcNo(procNo);

    if (groupProcNo.GetGroup() != GroupProcNo::NoGroup)
    {
        GROUP_AFFINITY ga;
        ga.Group = (WORD)groupProcNo.GetGroup();
        ga.Reserved[0] = 0; // reserve must be filled with zero
        ga.Reserved[1] = 0; // otherwise call may fail
        ga.Reserved[2] = 0;
        ga.Mask = (size_t)1 << groupProcNo.GetProcIndex();
        return !!SetThreadGroupAffinity(GetCurrentThread(), &ga, nullptr);
    }
    else
    {
        return !!SetThreadAffinityMask(GetCurrentThread(), (DWORD_PTR)1 << groupProcNo.GetProcIndex());
    }
}