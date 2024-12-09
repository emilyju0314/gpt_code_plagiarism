void CHexEditView::OnUpdateTextPaste(CCmdUI* pCmdUI)
{
	BOOL bEnable = !GetDocument()->read_only() && ::IsClipboardFormatAvailable(CF_TEXT);

	if (pCmdUI->m_pSubMenu != NULL)
	{
		// This happens when popup menu itself is drawn
		pCmdUI->m_pMenu->EnableMenuItem(pCmdUI->m_nIndex,
			MF_BYPOSITION | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)));
	}
	else
		pCmdUI->Enable(bEnable);

//    if (GetDocument()->read_only())
//        pCmdUI->Enable(FALSE);                  // Disallow paste if file is read only
//    else
//        pCmdUI->Enable(::IsClipboardFormatAvailable(CF_TEXT));
}