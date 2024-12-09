void CScrollableCaptions::DoAlign(UINT ctlid, UINT textid)
    {
     CRect r;
     BOOL b = (BOOL)GetParent()->SendMessage(UWM_QUERY_COORDINATES, ctlid, (LPARAM)&r);
     ASSERT(b);
     if(!b)
        return;
     
     TRACE("DoAlign: Parent [%d] (L=%d T=%d R=%d B=%d)\n", ctlid, r.left, r.top, r.right, r.bottom);
     
     /******************************************************************************
                   +----+
                   |    |
                   |    |
                   |    |  Parent object: coordinates in r
                   |    |
                   +----+
                    +----+
                    |    |  
                    |    |  
                    |    |  Local object: coordinates in L
                    |    |  
                    +----+
     ******************************************************************************/

     CWnd * wnd = GetDlgItem(ctlid); // Well, my second GetDlgItem for 2007 (but they tend to come in pairs)
     ASSERT(wnd != NULL);   
     if(wnd == NULL)
        return;
     CRect L;
     wnd->GetWindowRect(&L);

     L.left = r.left;
     L.right = r.right;

     CWnd * caption = GetDlgItem(textid);
     ASSERT(caption != NULL);
     if(caption != NULL)
        { /* force vertical alignment */
         CRect C;
         caption->GetWindowRect(&C);
         L.bottom = C.bottom;
        } /* force vertical alignment */

     ScreenToClient(&L);
     wnd->SetWindowPos(NULL,
                       L.left, L.top,
                       L.Width(), L.Height(),
                       SWP_NOZORDER | SWP_NOACTIVATE);
     wnd->Invalidate();
    }