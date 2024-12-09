void CHexEditView::OnUpdateByteBinary(CCmdUI* pCmdUI)
{
	if (((CMainFrame *)AfxGetMainWnd())->m_wndCalc.ByteSize() > 1)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	OnUpdateByte(pCmdUI);
}