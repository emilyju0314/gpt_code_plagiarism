void CICC_CreatorDlg::OnBnClickedPstables()
{
	int returnval;
	TCHAR szFile[MAX_PATH];
	OPENFILENAME ofn;

	ZeroMemory(szFile, MAX_PATH);
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
	ofn.hwndOwner = this->m_hWnd;
	ofn.lpstrFilter = _T("Supported Files Types(*.txt)\0*.txt\0TXT Files (*.)\0*.TXT\0\0");
	ofn.lpstrTitle = _T("Load PS Table Data");
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;

	if (IDOK == GetOpenFileNameW(&ofn))
	{
		returnval = ParseData(ofn.lpstrFile, true);
		if (returnval == 0)
		{
			this->SetDlgItemTextW(IDC_STATUS, L"Data Loaded OK");
		}
		else
		{
			this->SetDlgItemTextW(IDC_STATUS, L"Data Load Failed!");
			free(m_ucr_bg_data->cyan);
			free(m_ucr_bg_data->magenta);
			free(m_ucr_bg_data->yellow);
			free(m_ucr_bg_data->black);
			free(m_ucr_bg_data);
			m_ucr_bg_data = NULL;
		}
	}
}