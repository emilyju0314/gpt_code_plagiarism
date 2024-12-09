static CString GetStringSegment(UINT id)
    {
     CPUregs regs;
     CurrentProcessor.GetCPUID(id, &regs);
     CStringA a((LPCSTR)&regs.EAX, 4);
     a.GetBuffer();
     a.ReleaseBuffer();
     CStringA b((LPCSTR)&regs.EBX, 4);
     b.GetBuffer();
     b.ReleaseBuffer();
     CStringA c((LPCSTR)&regs.ECX, 4);
     c.GetBuffer();
     c.ReleaseBuffer();
     CStringA d((LPCSTR)&regs.EDX, 4);
     d.GetBuffer();
     d.ReleaseBuffer();
     CString result = a + b + c + d;
     return result;
    }