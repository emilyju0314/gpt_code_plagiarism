void CFindSheet::NewHex(LPCTSTR ss)
{
	CWnd *pwnd = GetFocus();
	if (pwnd->IsKindOf(RUNTIME_CLASS(CEdit)))
	{
		// If the Find Tool is active we must preserve focus and selection
		int start, end;
		((CEdit *)pwnd)->GetSel(start, end);
		SetActivePage(p_page_hex_);
		pwnd->SetFocus();
		((CEdit *)pwnd)->SetSel(start, end);
	}
	else
	{
		SetActivePage(p_page_hex_);
		pwnd->SetFocus();
	}

	p_page_hex_->UpdateData();          // Get current value before changing some of them

	combined_string_ = hex_string_ = ss;

	// hex_string_ has not had the case of the last entered character fixed yet
	if (theApp.hex_ucase_)
		combined_string_.MakeUpper();
	else
		combined_string_.MakeLower();

	// We need to call FixHexString to get the updated mask but not change hex_string_
	FixHexString();
	TextFromHex(hex_string_, mask_string_);
//    if (p_page_hex_->m_hWnd != 0)
	ASSERT(p_page_hex_->GetDlgItem(IDC_FIND_MASK) != NULL);
	p_page_hex_->GetDlgItem(IDC_FIND_MASK)->SetWindowText(mask_string_);
	p_page_hex_->UpdateData(FALSE);     // Update the dialog to match
	p_page_hex_->ctl_hex_string_.SetWindowText(hex_string_);

	// Set current search string so Find Tool(s) match Find Dialog
	((CMainFrame *)AfxGetMainWnd())->SetSearchString(ss);
}