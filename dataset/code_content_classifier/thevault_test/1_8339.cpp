void CLeaves::OnSize(UINT nType, int cx, int cy)
    {
     CPropertyPage::OnSize(nType, cx, cy);

     if(c_Platform.GetSafeHwnd() != NULL)
        { /* move it */
         CRect platform;
         c_Platform.GetWindowRect(&platform);
         ScreenToClient(&platform);

         CRect c;
         GetClientRect(&c);
         c_Platform.SetWindowPos(NULL, c.left, c.bottom - platform.Height(),
                                 0, 0,
                                 SWP_NOSIZE | SWP_NOZORDER);
        } /* move it */
    }