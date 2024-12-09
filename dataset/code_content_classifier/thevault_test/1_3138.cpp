CCellRange CGridCtrl::GetSelectedCellRange() const
{
    CCellRange Selection(GetRowCount(), GetColumnCount(), -1,-1);

#ifdef USE_CMAP
    for (POSITION pos = m_SelectedCellMap.GetStartPosition(); pos != NULL; )
    {
        DWORD key;
        CCellID cell;
        m_SelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);

        Selection.SetMinRow( min(Selection.GetMinRow(), cell.row) );
        Selection.SetMinCol( min(Selection.GetMinCol(), cell.col) );
        Selection.SetMaxRow( max(Selection.GetMaxRow(), cell.row) );
        Selection.SetMaxCol( max(Selection.GetMaxCol(), cell.col) );
    }
#else
    for (std::set<DWORD>::const_iterator pp = m_SelMap.begin(); pp != m_SelMap.end(); ++pp)
    {
        int row = LOWORD(*pp);
        int col = HIWORD(*pp);

        Selection.SetMinRow( min(Selection.GetMinRow(), row) );
        Selection.SetMinCol( min(Selection.GetMinCol(), col) );
        Selection.SetMaxRow( max(Selection.GetMaxRow(), row) );
        Selection.SetMaxCol( max(Selection.GetMaxCol(), col) );
    }
#endif
    return Selection;
}