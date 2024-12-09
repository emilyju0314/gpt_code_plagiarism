void CGridCtrl::ResetSelectedRange()
{
#ifdef USE_CMAP
    m_PrevSelectedCellMap.RemoveAll();
#else
    m_PrevSelMap.clear();
#endif
    SetSelectedRange(-1,-1,-1,-1);
    SetFocusCell(-1,-1);
}