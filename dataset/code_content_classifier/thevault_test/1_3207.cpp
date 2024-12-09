void CHexEditView::OnUpdateConvert(CCmdUI* pCmdUI)
{
	FILE_ADDRESS start_addr, end_addr;              // Current selection
	GetSelAddr(start_addr, end_addr);

	if (pCmdUI->m_pSubMenu != NULL)
	{
		// This happens when popup menu itself is drawn
		pCmdUI->m_pMenu->EnableMenuItem(pCmdUI->m_nIndex,
			MF_BYPOSITION | (start_addr < end_addr ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)));
	}
	else
		pCmdUI->Enable(start_addr < end_addr);
}