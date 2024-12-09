void CHexEditView::DoConversion(convert_type op, LPCSTR desc)
{
	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
	unsigned char *buf = NULL;

	if (check_ro(desc))
		return;

	// Get current address or selection
	FILE_ADDRESS start_addr, end_addr;          // Start and end of selection
	GetSelAddr(start_addr, end_addr);

	// Make sure there is a selection
	if (start_addr >= end_addr)
	{
		ASSERT(theApp.playing_);
		CString mess;
		mess.Format("There is nothing selected to %s", desc);
		TaskMessageBox("No Selection", mess);
		theApp.mac_error_ = 10;
		return;
	}
	ASSERT(start_addr < end_addr && end_addr <= GetDocument()->length());

	// Test if selection is too big to do in memory
	if (end_addr - start_addr > (16*1024*1024) && GetDocument()->DataFileSlotFree())
	{
		int idx = -1;                       // Index into docs data_file_ array (or -1 if no slots avail.)

		// Create a file to store the resultant data
		// (Temp file used by the document until it is closed or written to disk.)
		char temp_dir[_MAX_PATH];
		char temp_file[_MAX_PATH];
		::GetTempPath(sizeof(temp_dir), temp_dir);
		::GetTempFileName(temp_dir, _T("_HE"), 0, temp_file);

		// Get data buffer
		size_t len, buflen = size_t(min(4096, end_addr - start_addr));
		try
		{
			buf = new unsigned char[buflen];
		}
		catch (std::bad_alloc)
		{
			AfxMessageBox("Insufficient memory");
			theApp.mac_error_ = 10;
			goto func_return;
		}

		try
		{
			CFile64 ff(temp_file, CFile::modeCreate|CFile::modeWrite|CFile::shareExclusive|CFile::typeBinary);

			for (FILE_ADDRESS curr = start_addr; curr < end_addr; curr += len)
			{
				// Get the next buffer full from the document
				len = size_t(min(buflen, end_addr - curr));
				if (op != unary_at)      // We don't need to get old value if assigning
					VERIFY(GetDocument()->GetData(buf, len, curr) == len);

				ProcConversion(buf, len, op);

				ff.Write(buf, len);

				if (AbortKeyPress())
				{
					CString mess;
					mess.Format("Abort %s?", desc);
					if (TaskMessageBox(mess, 
						"Do you want to stop the process?", MB_YESNO) == IDYES)
					{
						ff.Close();
						remove(temp_file);
						theApp.mac_error_ = 10;
						goto func_return;
					}
				}

				mm->Progress(int(((curr - start_addr)*100)/(end_addr - start_addr)));
			}
		}
		catch (CFileException *pfe)
		{
			TaskMessageBox("Temp File Error", ::FileErrorMessage(pfe, CFile::modeWrite));
			pfe->Delete();

			remove(temp_file);
			theApp.mac_error_ = 10;
			goto func_return;
		}

		// Delete the unprocessed block that is to be replaced
		// Note: this must be done before AddDataFile otherwise Change() (via regenerate()) will delete the temp file.
		GetDocument()->Change(mod_delforw, start_addr, end_addr - start_addr, NULL, 0, this);

		// Add the temp file to the document
		idx = GetDocument()->AddDataFile(temp_file, TRUE);
		ASSERT(idx != -1);
		GetDocument()->Change(mod_insert_file, start_addr, end_addr - start_addr, NULL, idx, this, TRUE);
	}
	else
	{
		// Allocate memory block and process it

		// Error if ran out of temp file handles and file is too big
		if (end_addr - start_addr > UINT_MAX)  // why is there no SIZE_T_MAX?
		{
			TaskMessageBox("Conversion Error",
						  "HexEdit is out of temporary files and "
						  "cannot convert such a large selection.\n\n"
						  "Please save the file to deallocate "
						  "temporary file handles and try again.");
			theApp.mac_error_ = 10;
			return;
		}

		// Warn if we might cause memory exhaustion
		if (end_addr - start_addr > MEM_WARNING_SIZE)  // buffer may be too big
		{
			if (TaskMessageBox("Conversion Warning",
				"HexEdit is out of temporary file "
				"handles and converting such a large selection "
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

		CWaitCursor wait;                           // Turn on wait cursor (hourglass)

		try
		{
			buf = new unsigned char[size_t(end_addr - start_addr)];
		}
		catch (std::bad_alloc)
		{
			AfxMessageBox("Insufficient memory");
			theApp.mac_error_ = 10;
			goto func_return;
		}
		size_t got = GetDocument()->GetData(buf, size_t(end_addr - start_addr), start_addr);
		ASSERT(got == size_t(end_addr - start_addr));

		ProcConversion(buf, got, op);

		GetDocument()->Change(mod_replace, start_addr, got, (unsigned char *)buf, 0, this);
	}

	DisplayCaret();
	theApp.SaveToMacro(km_convert, op);

func_return:
	mm->Progress(-1);  // disable progress bar

	if (buf != NULL)
		delete[] buf;
}