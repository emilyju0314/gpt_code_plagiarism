void CICC_CreatorDlg::OnBnClickedPsicc()
{
	int ok;
	TCHAR szFile[MAX_PATH];
	OPENFILENAME ofn;

	ZeroMemory(szFile, MAX_PATH);
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST |OFN_HIDEREADONLY;
	ofn.hwndOwner = this->m_hWnd;
	ofn.lpstrFilter = _T("Supported Files Types(*.icc)\0*.icc;*.ICC\0\0");
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;

	ofn.lpstrTitle = _T("Save PS Gray Profile");
	if (IDOK == GetSaveFileName(&ofn))
	{
		ok = create_psgray_profile(szFile);
		if (ok == 0)
			this->SetDlgItemText(IDC_STATUS, _T("Created PS Gray Profile"));
	}

	ofn.lpstrTitle	= _T("Save PS RGB Profile");
	if (IDOK == GetSaveFileName(&ofn))
	{
		ok = create_psrgb_profile(szFile);
		if (ok == 0)
			this->SetDlgItemText(IDC_STATUS, _T("Created PS RGB Profile"));
	}

	ofn.lpstrTitle	= _T("Save PS CMYK Profile");
	if (IDOK == GetSaveFileName(&ofn))
	{
		ok = create_pscmyk_profile(szFile, false, this->m_cpsi_mode, this->m_ucr_bg_data);
		if (ok == 0)
			this->SetDlgItemText(IDC_STATUS, _T("Created PS CMYK Profile"));
	}
}