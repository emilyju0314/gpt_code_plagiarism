BOOL CHexEditDoc::OnNewDocument()
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());

	if (!CDocument::OnNewDocument())
	{
		aa->mac_error_ = 20;
		return FALSE;
	}

	DeleteContents();
	SetModifiedFlag(FALSE);
	readonly_ = shared_ = FALSE;
	length_ = 0L;
	last_view_ = NULL;
	edit_time_.reset(true);

	if (theApp.recording_ && theApp.mac_.size() > 0 && (theApp.mac_.back()).ktype == km_focus)
	{
		// We don't want focus change recorded (see CHexEditView::OnSetFocus)
		theApp.mac_.pop_back();
	}
	if (!theApp.no_ask_insert_)
	{
		if (!theApp.playing_)
		{
			if (!ask_insert())
				return FALSE;   // User cancelled or some error
		}
		else
		{
			CString ss = theApp.last_fill_str_;
			__int64 state = theApp.last_fill_state_;
			// This was for backward compatibility but a value of zero is valid (length 0 file)
			//if (state == 0)
			//{
			//	state = 0x0000200000000001;
			//	ss = "0";
			//}
			if (insert_block(0, state, ss) == -1)
				return FALSE;       // Some error
		}
	}

	if (pthread2_ == NULL && CanDoSearch())
	{
		CreateSearchThread();
		if (theApp.pboyer_ != NULL)        // If a search is active start a bg search on the newly opened file
			StartSearch();
	}
	if (pthread5_ == NULL && CanDoStats())
	{
		CreateStatsThread();
		StartStats();
	}

	OpenDataFormatFile("default");

//    CHexEditView *pv = GetBestView();
//    if (start_ebcdic)
//        pv->OnCharsetEbcdic();

	return TRUE;
}