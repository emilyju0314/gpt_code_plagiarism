void CHexEditDoc::OnCloseDocument()
{
	CheckSaveTemplate();

	// Store options for this file associated with the 1st CHexEditView for this doc
	// Note that this is done after saving the template file above so that the correct template
	// file is saved (in StoreOptions) if the template file has been saved to another name (Save As).
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView *pview = GetNextView(pos);
		if (pview->IsKindOf(RUNTIME_CLASS(CHexEditView)))
		{
			((CHexEditView *)pview)->StoreOptions();
			break;
		}
	}

	DeleteContents();

	// If preserving times/attributes of the file restore them now
	if (keep_times_ && !IsDevice())
	{
		RestoreFileTimes(m_strPathName);
		// qqq note that access time keeps getting updated no matter where we put this
	}

	if (hicon_ != HICON(0))
	{
		DestroyIcon(hicon_);
		hicon_ = HICON(0);
	}

	CDocument::OnCloseDocument();
}