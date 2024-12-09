bool GCToOSInterface::GetProcessorForHeap(uint16_t heap_number, uint16_t* proc_no, uint16_t* node_no)
{
    bool success = false;

    // Locate heap_number-th available processor
    uint16_t procIndex;
    size_t cnt = heap_number;
    for (uint16_t i = 0; i < GCToOSInterface::GetTotalProcessorCount(); i++)
    {
        if (g_processAffinitySet.Contains(i))
        {
            if (cnt == 0)
            {
                procIndex = i;
                success = true;
                break;
            }

            cnt--;
        }
    }

    if (success)
    {
        WORD gn, gpn;

        if (CanEnableGCCPUGroups())
        {
            GetGroupForProcessor(procIndex, &gn, &gpn);
        }
        else
        {
            gn = GroupProcNo::NoGroup;
            gpn = procIndex;
        }

        GroupProcNo groupProcNo(gn, gpn);
        *proc_no = groupProcNo.GetCombinedValue();

        PROCESSOR_NUMBER procNumber;

        if (CanEnableGCCPUGroups())
        {
            procNumber.Group = gn;
        }
        else
        {
            // Get the current processor group
            GetCurrentProcessorNumberEx(&procNumber);
        }

        if (GCToOSInterface::CanEnableGCNumaAware())
        {
            procNumber.Number   = (BYTE)gpn;
            procNumber.Reserved = 0;

            if (!GetNumaProcessorNodeEx(&procNumber, node_no))
            {
                *node_no = NUMA_NODE_UNDEFINED;
            }
        }
        else
        {   // no numa setting, each cpu group is treated as a node
            *node_no = procNumber.Group;
        }
    }

    return success;
}