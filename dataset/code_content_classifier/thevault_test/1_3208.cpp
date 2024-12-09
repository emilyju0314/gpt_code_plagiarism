void CHexEditView::DoTransform(CryptoPP::BufferedTransformation *pTrx, int transform_type, CString strDesc, double mem_factor /*=1*/)
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
	if (check_ro(strDesc))
		return;

	// Get current address or selection
	FILE_ADDRESS start_addr, end_addr;          // Start and end of selection
	GetSelAddr(start_addr, end_addr);

	// Make sure there is a selection
	if (start_addr >= end_addr)
	{
		// No selection, presumably in macro playback
		ASSERT(aa->playing_);
		TaskMessageBox("No Selection", "The selection is empty");
		aa->mac_error_ = 10;
		return;
	}

	// If in OVR and transformation changes the selection length then we give the user an option to
	// turn off OVR mode (go into INS mode) or cancel the operation.
	if (display_.overtype && mem_factor != 0.0)
	{
		if (AvoidableTaskDialog(IDS_OVERTYPE,
			"The operation will change the length of the "
			"selection.  This is not permitted in OVR mode.\n\n."
			"Do you want to turn off overtype mode?",
			NULL, NULL, TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON) != IDOK)
		{
			aa->mac_error_ = 10;
			return;
		}
		else if (!do_insert())
			return;
	}

	CWaitCursor wait;                                  // Turn on wait cursor (hourglass)

	CryptoPP::BufferedTransformation * pSink = NULL;   // stores result (either to buffer or temp file)
	char temp_file[_MAX_PATH] = { '\0' };              // temp file if transformed bytes are stored on disk (too big for mem)
	unsigned char *outbuf = NULL;                      // buffer used if transformed bytes are stored in memory
	size_t outlen = size_t(end_addr - start_addr);     // worst case size for output buffer

	if (mem_factor > 0.0)
		outlen = size_t(outlen * mem_factor) + 512;   // Allow a bit extra (eg block encryptio may increase the length slightly)

	// Create "sink" that is used to store the result of the trasnformation
	if (outlen > (64 * 1024 * 1024) && GetDocument()->DataFileSlotFree())
	{
		// Too big for memory so create a "temp" file to store the transformed data
		// (This file stores the data until the document is closed or written to disk.)
		char temp_dir[_MAX_PATH];
		::GetTempPath(sizeof(temp_dir), temp_dir);
		::GetTempFileName(temp_dir, _T("_HE"), 0, temp_file);

		// Create Crypto++ file sink object
		pSink = new CryptoPP::FileSink(temp_file);
	}
	else if (outlen < UINT_MAX)
	{
		// We need to allocate a buffer in memory so warn if we might cause memory exhaustion
		if (outlen > MEM_WARNING_SIZE)  // More than 256 Mb may be too big
		{
			if (TaskMessageBox(strDesc + " Warning",
				"HexEdit is out of temporary file "
				"handles and such a large selection "
				"may cause memory exhaustion.  Please click "
				"\"No\" and save the file to free handles "
				"or click \"Yes\" to continue.\n\n"
				"Do you want to continue?",
				MB_YESNO) != IDYES)
			{
				theApp.mac_error_ = 5;
				return;
			}
		}

		// Get memory for selection and create Crypto++ buffer sink
		try
		{
			outbuf = new unsigned char[outlen];
		}
		catch (std::bad_alloc)
		{
			AfxMessageBox("Insufficient memory");
			aa->mac_error_ = 10;
			return;
		}

		pSink = new CryptoPP::ArraySink(outbuf, outlen);
	}
	else
	{
		// Error if we ran out of temp file handles and selection is really big
		TaskMessageBox(strDesc + " Error",
			"HexEdit is out of temporary files and "
			"cannot handle such a large selection.\n\n"
			"Please save the file to deallocate "
			"temporary file handles and try again.");
		theApp.mac_error_ = 10;
		return;
	}

	// Add our sink to the output of the transformation
	pTrx->Attach(pSink);

	// Note: at this point Crypto++ "owns" pSink and will "destruct" it when pTrx is destructed but
	// we can still use it - eg, to get the output length from ArraySink (if stored in memory) 

	// Get buffer for reading source blocks
	unsigned char *inbuf = NULL;
	size_t inbuflen = size_t(min(32768, end_addr - start_addr));
	try
	{
		inbuf = new unsigned char[inbuflen];
	}
	catch (std::bad_alloc)
	{
		AfxMessageBox("Insufficient memory");
		theApp.mac_error_ = 10;
		return;
	}

	size_t len;                                    // size of data block to be transformed at once
	for (FILE_ADDRESS curr = start_addr; curr < end_addr; curr += len)
	{
		// Get the next buffer full from the document
		len = size_t(min(inbuflen, end_addr - curr));
		VERIFY(GetDocument()->GetData(inbuf, len, curr) == len);

		// Call Crypto++ to transform and output
		pTrx->Put(inbuf, len);

		if (AbortKeyPress() &&
			TaskMessageBox(strDesc + " Abort?",
			"You have interrupted the operaion.\n\n"
			"Do you want to stop?", MB_YESNO) == IDYES)
		{
			pTrx->MessageEnd();
			pTrx->Detach();      // so we can delete the file

			if (temp_file[0] != '\0')
				remove(temp_file);
			theApp.mac_error_ = 10;
			goto func_return;
		}

		mm->Progress(int(((curr - start_addr) * 100) / (end_addr - start_addr)));
	}
	pTrx->MessageEnd();

	// Get the actual size of the transformed data
	FILE_ADDRESS new_len;
	if (outbuf != NULL)
	{
		new_len = (dynamic_cast<CryptoPP::ArraySink *>(pSink))->TotalPutLength();
	}
	else
	{
		pTrx->Detach();        // this is so we can use the file

		CFileStatus fs;
		CFile64::GetStatus(temp_file, fs);
		new_len = fs.m_size;
	}

	if (outbuf != NULL && new_len == end_addr - start_addr)
	{
		// "new" data is the same length as the "old" data so just do a replace
		GetDocument()->Change(mod_replace, start_addr, new_len, outbuf, 0, this);
	}
	else
	{
		ASSERT(!display_.overtype);     // can't have different length in OVR mode

		// Delete the "old" block that is to be replaced
		// Note: this must be done before calling AddDataFile otherwise it will delete the temp file.
		GetDocument()->Change(mod_delforw, start_addr, end_addr - start_addr, NULL, 0, this);

		if (outbuf == NULL)
		{
			// Add the temp file to the document
			int idx = GetDocument()->AddDataFile(temp_file, TRUE);
			ASSERT(idx != -1);
			GetDocument()->Change(mod_insert_file, start_addr, new_len, NULL, idx, this, TRUE);
		}
		else
		{
			// Add the new data block
			GetDocument()->Change(mod_insert, start_addr, new_len, outbuf, 0, this, TRUE);
		}
		undo_.back().previous_too = true;    // Merge changes (at least in this view)

		// Select the "new" data
		SetSel(addr2pos(start_addr), addr2pos(start_addr + new_len));

		// Inform the user in case they don't notice the selection has been increased
		CString mess;
		mess.Format("%s increased the selection length by %ld bytes", strDesc, long(new_len - (end_addr - start_addr)));
		((CMainFrame *)AfxGetMainWnd())->StatusBarText(mess);
	}
	DisplayCaret();
	aa->SaveToMacro(km_transform, transform_type);

func_return:
	mm->Progress(-1);  // disable progress bar

	if (inbuf != NULL)
		delete[] inbuf;
	if (outbuf != NULL)
		delete[] outbuf;
}