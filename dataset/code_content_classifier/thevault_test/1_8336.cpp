void CScrollableCaptions::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
    {
     int pos = GetScrollPos(SB_VERT);
     CRect r;

     bottom->GetWindowRect(&r);  // choose some control, this is as good as any
     ScreenToClient(&r);

     switch(nSBCode)
        { /* sbcode */
         case SB_PAGEUP:
            pos -= r.Height();
            break;
         case SB_PAGEDOWN:
            pos += r.Height();
            break;
         case SB_LINEUP:
            pos--;
            break;
         case SB_LINEDOWN:
            pos++;
            break;
         case SB_THUMBTRACK:
            pos = nPos;
            break;
        } /* sbcode */
     if(pos < 0)
        pos = 0;

     HDWP wndpos = ::BeginDeferWindowPos(72); // 32-bit displays, no more than 2 per bit + spares

     for(CWnd * wnd = GetWindow(GW_CHILD); wnd != NULL; wnd = wnd->GetWindow(GW_HWNDNEXT))
        { /* scan windows */
         if(wnd == &c_Platform)
            continue;

         LONG L = ::GetWindowLong(wnd->m_hWnd, GWL_USERDATA);
         POINTS pt = MAKEPOINTS(L);
         int y = pt.y - pos;
         //TRACE("OnVScroll: [%d] (x=%d y=%d)\n", wnd->GetDlgCtrlID(), pt.x, y);
         CRect wp;
         wnd->GetWindowRect(&wp);
         wndpos = ::DeferWindowPos(wndpos, wnd->m_hWnd, NULL, pt.x, y, 0, 0, // ignored
                        SWP_NOSIZE | SWP_NOZORDER);
        } /* scan windows */

     ::EndDeferWindowPos(wndpos);

     SetScrollPos(SB_VERT, pos);

     SetPlatformLabel();
     CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
    }