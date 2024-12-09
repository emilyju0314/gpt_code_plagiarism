int CCPUCoreRegion::ComputeNProcs()
    {
     CPUregs regs;
     CurrentProcessor.GetCPUID(1, &regs);
     EBX1b EBX;
     EBX.w = regs.EBX;

     int nprocs = EBX.bits.LogicalProcessors;
     if(nprocs == 0)
        nprocs = 1;
     return nprocs;
    }