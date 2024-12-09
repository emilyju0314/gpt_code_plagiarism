void CArrow::QueryShowTip(CPoint pt)
    {
     if(Rgn.GetSafeHandle() != NULL)
        { /* has region */
         if(!Rgn.PtInRegion(pt))
            { /* not in region */
             CBlock::DisplayToolTip(pt, _T(""));
             return;
            } /* not in region */
        } /* has region */

     CBlock::DisplayToolTip(pt, ToolTipText);
    }