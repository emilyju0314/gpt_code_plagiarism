void CHexEditApp::OnNewVersion(int old_ver, int new_ver)
{
	if (old_ver == 200)
	{
		// Version 2.0 used BCG 5.3 which did not support resource smart update
		CMFCToolBar::ResetAll();
	}
	else if (old_ver == 210)
	{
		// We need to reset the Edit Bar otherwise the edit controls (Find/Jump tools) don't work properly
		CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
		mm->m_wndEditBar.RestoreOriginalstate();
	}
}