CString GetCPUName()
    {
     CString name;
     CPUregs regs;
     CurrentProcessor.GetCPUID(0x80000000, &regs);
     if(regs.EAX < 0x80000004)
        return _T("data");
     name = GetStringSegment(0x80000002);
     name += GetStringSegment(0x80000003);
     name += GetStringSegment(0x80000004);
     name.Trim();
     return name;
    }