void CHexEditDoc::CreatePreviewThread()
{
	ASSERT(pthread6_ == NULL);
	ASSERT(pfile6_ == NULL);

	// Open copy of file to be used by background thread
	if (pfile1_ != NULL)
	{
		if (IsDevice())
			pfile6_ = new CFileNC();
		else
			pfile6_ = new CFile64();
		if (!pfile6_->Open(pfile1_->GetFilePath(),
					CFile::modeRead|CFile::shareDenyNone|CFile::typeBinary) )
		{
			TRACE1("+++ Preview file open failed for %p\n", this);
			return;
		}
	}

	// Open copy of any data files in use too
	for (int ii = 0; ii < doc_loc::max_data_files; ++ii)
	{
		ASSERT(data_file6_[ii] == NULL);
		if (data_file_[ii] != NULL)
			data_file6_[ii] = new CFile64(data_file_[ii]->GetFilePath(), 
										  CFile::modeRead|CFile::shareDenyWrite|CFile::typeBinary);
	}

	// Create new thread
	preview_command_ = NONE;
	preview_state_ = STARTING;    // pre start and very beginning
	preview_fin_ = false;
	TRACE1("+++ Creating preview thread for %p\n", this);
	pthread6_ = AfxBeginThread(&bg_func, this, THREAD_PRIORITY_LOWEST);
	ASSERT(pthread6_ != NULL);
}