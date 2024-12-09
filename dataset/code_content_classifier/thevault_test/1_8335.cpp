void CScrollableCaptions::SavePos()
    {
     for(CWnd * wnd = GetWindow(GW_CHILD); wnd != NULL; wnd = wnd->GetWindow(GW_HWNDNEXT))
        { /* capture original */
         CRect r;
         wnd->GetWindowRect(&r);
         ScreenToClient(&r);
         CPoint pt(r.left, r.top);
         ::SetWindowLong(wnd->m_hWnd, GWL_USERDATA, POINTTOPOINTS(pt));
        } /* capture original */
    }