void CHexEditView::OnUpdateClipboard(CCmdUI* pCmdUI)
{
	// Is there any text selected?
	CPointAp start, end;
	GetSel(start, end);
	if (pCmdUI->m_pSubMenu != NULL)
	{
		// This happens when popup menu itself is drawn
		pCmdUI->m_pMenu->EnableMenuItem(pCmdUI->m_nIndex,
			MF_BYPOSITION | (start != end ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)));
	}
	else
		pCmdUI->Enable(start != end);
}