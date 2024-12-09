void CHexEditView::DoDigest(CryptoPP::HashTransformation * digest, int mac_id)
{
	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
	CString desc(digest->AlgorithmName().c_str());
	unsigned char *buf = NULL;

	// Get current address or selection range
	FILE_ADDRESS start_addr, end_addr;          // Start and end of selection
	GetSelAddr(start_addr, end_addr);

	ASSERT(start_addr <= end_addr);   // We now allow calc of digest on empty selection
	ASSERT(start_addr < GetDocument()->length());

	// Get a buffer - fairly large for efficiency
	size_t len, buflen = size_t(min(4096, end_addr - start_addr));
	try
	{
		buf = new unsigned char[buflen];
	}
	catch (std::bad_alloc)
	{
		AfxMessageBox("Insufficient memory");
		theApp.mac_error_ = 10;
		return;
	}
	ASSERT(buf != NULL);

	// Process the selection in "buflen" chunks
	for (FILE_ADDRESS curr = start_addr; curr < end_addr; curr += len)
	{
		// Get the next buffer full from the document
		len = size_t(min(buflen, end_addr - curr));
		VERIFY(GetDocument()->GetData(buf, len, curr) == len);

		digest->Update(buf, len);  // update digest

		// Allow for abort + update progress
		if (AbortKeyPress() &&
			TaskMessageBox("Abort " + desc + " calculation?", 
			"You have interrupted the " + desc + " calculation.\n\n"
			"Do you want to stop the process?", MB_YESNO) == IDYES)
		{
			theApp.mac_error_ = 10;
			mm->Progress(-1);  // disable progress bar
			goto func_return;
		}
		mm->Progress(int(((curr - start_addr)*100)/(end_addr - start_addr)));
	}

	// Get the resulting digest
	size_t result_len = digest->DigestSize();   // size of the digest in bytes
	byte * result = new byte[result_len];
	digest->Final(result);

	mm->Progress(-1);  // disable progress bar

	// Display the value in calculator and (avoidable) message box
	{
		CString ss;
		const char * fmt = theApp.hex_ucase_ ? "%2.2X" : "%2.2x";
		for (int ii = 0; ii < result_len; ++ii)
		{
			char buf[8];
			sprintf(buf, fmt, result[ii]);
			ss += buf;
		}

		// Load the value into the calculator ensuring bits is at least big enough and radix is hex
		if (((CMainFrame *)AfxGetMainWnd())->m_wndCalc.get_bits() <= result_len * 8)
		{
			((CMainFrame *)AfxGetMainWnd())->m_wndCalc.change_bits(result_len * 8);
			((CMainFrame *)AfxGetMainWnd())->m_wndCalc.change_signed(false);  // avoid overflow if top bit is on
		}
		((CMainFrame *)AfxGetMainWnd())->m_wndCalc.change_base(16);       // Digests are traditionally shown in hex

		//((CMainFrame *)AfxGetMainWnd())->m_wndCalc.SetStr(ss);
		mpz_class tmp;
		mpz_set_str(tmp.get_mpz_t(), ss, 16);
		((CMainFrame *)AfxGetMainWnd())->m_wndCalc.Set(tmp);

		dynamic_cast<CMainFrame *>(::AfxGetMainWnd())->show_calc();          // make sure calc is displayed

		// Display the result in an (avoidable) dialog
		AddSpaces(ss);
		CString mess;
		mess.Format("%s %s\n\n"
			"The calculator value has been set to the result of the %s calculation "
			"which is %d bits (%d bytes) in length and displayed in hex (radix 16).\n\n"
			"%s", 
			(const char *)desc, start_addr == end_addr ? "(zero length input)" : "",
			(const char *)desc, 
			(int)(result_len * 8), (int)result_len, 
			(const char *)ss);
		AvoidableTaskDialog(IDS_DIGEST, mess);
	}

	delete[] result;

	// Record in macro since we did it successfully
	theApp.SaveToMacro(km_checksum, mac_id);

func_return:
	if (buf != NULL)
		delete[] buf;
}