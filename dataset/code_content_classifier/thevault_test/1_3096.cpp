void CFindSheet::NewText(LPCTSTR ss)
{
	CWnd *pwnd = GetFocus();
	if (pwnd->IsKindOf(RUNTIME_CLASS(CEdit)))
	{
		// If the Find Tool is active we must preserve focus and selection
		int start, end;
		((CEdit *)pwnd)->GetSel(start, end);
		SetActivePage(p_page_text_);        // Show text search page
		pwnd->SetFocus();
		((CEdit *)pwnd)->SetSel(start, end);
	}
	else
	{
		SetActivePage(p_page_text_);        // Show text search page
		pwnd->SetFocus();
	}

	p_page_text_->UpdateData();
	combined_string_ = text_string_ = ss;
	HexFromText(ss);                    // Convert text to hex using current char set
	p_page_text_->UpdateData(FALSE);
	p_page_text_->ctl_text_string_.SetWindowText(ss);

	// Set current search string so Find Tool(s) match
	CString temp;
	if (GetMatchCase())
		temp = CString("=") + ss;
	else
		temp = CString("~") + ss;
	((CMainFrame *)AfxGetMainWnd())->SetSearchString(temp);
}