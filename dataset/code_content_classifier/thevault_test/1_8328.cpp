void WriteSpecs()
    {
     CString filename = GetCPUName();
     CString filter;
     filter.LoadString(IDS_FILTER);
     CString ext;
     ext.LoadString(IDS_DEFAULT_EXTENSION);

     CFileDialog dlg(FALSE, // save-as
                     ext, // default extension
                     filename,
                     OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                     filter);
     if(dlg.DoModal() != IDOK)
        return;

     CStdioFile f;
     if(!f.Open(dlg.GetPathName(), CFile::modeCreate | CFile::modeWrite))
        { /* open failed */
         DWORD err = ::GetLastError();
         CString openerror;
         openerror.LoadString(IDS_OPEN_ERROR);
         CString s;
         s.Format(_T("%s\n%s\n%s"),
                  openerror,
                  dlg.GetPathName(),
                  ErrorString(err));
         AfxMessageBox(s, MB_ICONERROR | MB_OK);
         return;
        } /* open failed */
     f.WriteString(_T("<?xml version \"1.0\"?>\n"));
     f.WriteString(_T("<CPUID:id name=\"") + GetCPUName() + _T("\"/>\n"));
     f.WriteString(_T("<CPUID:block>\n"));

     CPUregs regs;
     GetCPUID(0, &regs);

     for(UINT i = 0; i <= min(regs.EAX, 255); i++)
        { /* read each basic */
         CPUregs regs2;
         switch(i)
            { /* special cases */
             case 4:
                { /* cache information */
                 for(int n = 0; ; n++)
                    { /* scan each */
                     regs2.ECX = n;
                     GetCPUID(i, &regs2);
                     BOOL HasCache = CBasicCPU4_0_31::GetCacheParameters(n, &regs2);
                     if(!HasCache)
                        break;
                     WriteCPUID(f, i, n, &regs2);
                    } /* scan each */
                } /* cache information */
                break;
             default:
                GetCPUID(i, &regs2);
                WriteCPUID(f, i, 0, &regs2);
                break;
            } /* special cases */
        } /* read each basic */

     GetCPUID(0x80000000, &regs);
     for(UINT i = 0x80000000; i <= regs.EAX; i++)
        { /* read each extended */
         CPUregs regs2;
         GetCPUID(i, &regs2);
         WriteCPUID(f, i, 0, &regs2);
        } /* read each extended */

     f.WriteString(_T("</CPUID:block>\n"));
     f.Close();
    }