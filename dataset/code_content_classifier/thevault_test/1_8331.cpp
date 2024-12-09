BOOL CBasicCPU1EDXAMD::OnSetActive()
    {
     CPUregs regs;
     GetAndReport(1, regs);

     EDX1b EDX;
     EDX.w = regs.EDX;

     CString s;

     SETWINDOWBIT(Reserved5, EDX, AMD);         // 18

     s = FormatBinary(EDX.AMD.Reserved2, 3);    // 22..20
     c_Reserved2.SetWindowText(s + _T("B"));              
     
     SETWINDOWBIT(Reserved4, EDX, AMD);         // 27

     s = FormatBinary(EDX.AMD.Reserved3, 3);    // 31..29
     c_Reserved3.SetWindowText(s + _T("B"));
     
     return CBasicCPU1EDX::OnSetActive();
    }