void CGridCtrl::SetFixedBackClr(COLORREF clr)
{
    m_cellFixedColDef.SetBackClr(clr);
    m_cellFixedRowDef.SetBackClr(clr);
    m_cellFixedRowColDef.SetBackClr(clr);
}