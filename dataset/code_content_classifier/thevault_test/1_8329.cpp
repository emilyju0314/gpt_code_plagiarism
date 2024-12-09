BOOL CBasicCPU1EDX::OnSetActive()
    {
     CPUregs regs;
     GetAndReport(1, regs);

     EDX1b EDX;
     EDX.w = regs.EDX;

     CString s;

     
     SETWINDOWBIT(FPU, EDX, Intel);                         // 0
     SETWINDOWBIT(VME, EDX, Intel);                         // 1
     SETWINDOWBIT(DE,  EDX, Intel);                         // 2
     SETWINDOWBIT(PSE, EDX, Intel);                         // 3
     SETWINDOWBIT(TSC, EDX, Intel);                         // 4
     SETWINDOWBIT(MSR, EDX, Intel);                         // 5
     SETWINDOWBIT(PAE, EDX, Intel);                         // 6
     SETWINDOWBIT(MCE, EDX, Intel);                         // 7
     SETWINDOWBIT(CX8, EDX, Intel);                         // 8
     SETWINDOWBIT(APIC, EDX, Intel);                        // 9
     SETWINDOWBIT(Reserved1, EDX, Intel);                   // 10
     SETWINDOWBIT(SEP, EDX, Intel);                         // 11
     SETWINDOWBIT(MTRR, EDX, Intel);                        // 12
     SETWINDOWBIT(PGE, EDX, Intel);                         // 13
     SETWINDOWBIT(MCA, EDX, Intel);                         // 14
     SETWINDOWBIT(CMOV, EDX, Intel);                        // 15
     SETWINDOWBIT(PAT, EDX, Intel);                         // 16
     SETWINDOWBIT(PSE36, EDX, Intel);                       // 17
                                                            // 18: subclas
     SETWINDOWBIT(CFLSH, EDX, Intel);                       // 19
                                                            // 20: subclass
                                                            // 21: subclass
                                                            // 22: subclass
     SETWINDOWBIT(MMX, EDX, Intel);                         // 23
     SETWINDOWBIT(FXSR, EDX, Intel);                        // 24
     SETWINDOWBIT(SSE, EDX, Intel);                         // 25
     SETWINDOWBIT(SSE2, EDX, Intel);                        // 26
     SETWINDOWBIT(HTT, EDX, Intel);                         // 28
                                                            // 29: subclass
                                                            // 30: subclass
                                                            // 31: subclass
     return CScrollableCaptionsParent::OnSetActive();
    }