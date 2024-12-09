void CICC_CreatorDlg::OnBnClickedCielab()
{
	int code;
	TCHAR szFile[MAX_PATH];
	OPENFILENAME ofn;

	ZeroMemory(szFile, MAX_PATH);
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
	ofn.hwndOwner = this->m_hWnd;
	ofn.lpstrFilter = _T("Supported Files Types(*.txt)\0*.txt;*.TXT\0\0");
	ofn.lpstrTitle = _T("Load CIELAB File");
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;

	if (IDOK == GetOpenFileName(&ofn))
	{
		code = this->GetCIELAB(ofn.lpstrFile);
		if (code == 0)
			this->SetDlgItemText(IDC_STATUS, _T("CIELAB Data Loaded"));
	}
	else
	{
		this->SetDlgItemText(IDC_STATUS, _T("CIELAB file failed to open!"));
	}
}