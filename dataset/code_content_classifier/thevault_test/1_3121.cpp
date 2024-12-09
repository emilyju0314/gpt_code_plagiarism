void CCompareView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
	// Is there any text selected?
	CPointAp start, end;
	GetSel(start, end);
	pCmdUI->Enable(start != end);
}