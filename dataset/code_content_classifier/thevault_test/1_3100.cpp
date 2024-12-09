CFindSheet::charset_t CFindSheet::GetCharSet() const
{
	CPropertyPage *pp = GetActivePage();
	ASSERT(pp != NULL);
	pp->UpdateData();

	if (((CMainFrame *)AfxGetMainWnd())->m_paneFind.IsWindowVisible() || 
		pp != p_page_text_)
	{
		// use active view's char set
		CHexEditView *pview = GetView();
		if (pview == NULL || !pview->EbcdicMode())
			return RB_CHARSET_ASCII;
		else
			return RB_CHARSET_EBCDIC;
	}

	return charset_;
}