void CHexEditView::OnReadFile()
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());

	// Get name of file to read
	CHexFileDialog dlgFile("ReadFileDlg", HIDD_FILE_READ, TRUE, NULL, aa->current_read_,
						   OFN_HIDEREADONLY | OFN_SHOWHELP | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR | OFN_DONTADDTORECENT,
						   aa->GetCurrentFilters(), "Read", this);

	// Set up the title of the dialog
	dlgFile.m_ofn.lpstrTitle = "Insert File";

	if (dlgFile.DoModal() == IDOK)
	{
		aa->current_read_ = dlgFile.GetPathName();

		do_read(aa->current_read_);
	}
}