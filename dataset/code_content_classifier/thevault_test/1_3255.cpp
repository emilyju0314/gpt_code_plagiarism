bool CHexEditDoc::OpenCompFile()
{
	// Open file to be used by background thread
	if (pfile1_ != NULL)
	{
		CString fileName;
		if (bCompSelf_)
			fileName = tempFileA_;
		else
			fileName = pfile1_->GetFilePath();
		ASSERT(!fileName.IsEmpty());

		if (IsDevice() && !bCompSelf_)
			pfile4_ = new CFileNC();
		else
			pfile4_ = new CFile64();
		if (!pfile4_->Open(fileName, CFile::modeRead|CFile::shareDenyNone|CFile::typeBinary) )
		{
			TRACE1("+++ Compare (file4) open failed for %p\n", this);
			return false;
		}
	}

	// Open any data files in use too, since we need to compare against the in-memory file
	for (int ii = 0; ii < doc_loc::max_data_files; ++ii)
	{
		ASSERT(data_file4_[ii] == NULL);
		if (data_file_[ii] != NULL)
			data_file4_[ii] = new CFile64(data_file_[ii]->GetFilePath(), 
										  CFile::modeRead|CFile::shareDenyWrite|CFile::typeBinary);
	}

	// Open file to compare against
	ASSERT(pfile1_compare_ == NULL && pfile4_compare_ == NULL);

	CString fileName;
	if (!bCompSelf_)
		fileName = compFileName_;
	else if (pfile1_ != NULL)
		fileName = tempFileB_.IsEmpty() ? pfile1_->GetFilePath() : tempFileB_;
	else
		return false;

	pfile1_compare_ = new CFile64();
	pfile4_compare_ = new CFile64();
	if (!pfile1_compare_->Open(fileName, CFile::modeRead|CFile::shareDenyNone|CFile::typeBinary) ||
		!pfile4_compare_->Open(fileName, CFile::modeRead|CFile::shareDenyNone|CFile::typeBinary))
	{
		TRACE1("+++ Compare file open failed for %p\n", this);
		pfile1_compare_ = pfile4_compare_ = NULL;
		return false;
	}
	return true;
}