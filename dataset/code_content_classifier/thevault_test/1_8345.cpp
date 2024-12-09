void CPhysicalAddressLines::OnPaint()
    {
     CPUregs regs;
     CurrentProcessor.GetCPUID(0x80000000, &regs);
     if(regs.EAX < 0x80000008)
        { /* unknown */
         SetWindowText(_T(""));
         SetToolTipText(IDS_PA_UNSPECIFIED);
        } /* unknown */
     else
        { /* has it */
         CurrentProcessor.GetCPUID(0x80000008, &regs);
         EAX8x EAX;
         EAX.w = regs.EAX;
         CString s;
         s.Format(_T("%d"), EAX.bits.PhysicalAddressBits);
         SetWindowText(s);
         SetToolTipText(IDS_80000008_EAX_PAB);
        } /* has it */
     CArrow::OnPaint();
    }