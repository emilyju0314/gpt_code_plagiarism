void CCalcDlg::add_hist()
{
	// We get the expression that generated the result as a full string to be added
	// to the tape (history window) and the drop down (history list)
	CString strTape = CString(get_expr(true));   // string to be added to calc tape window
	CString strDrop;                             // string to be added to drop down history
	if (strTape.GetLength() <= 100)
		strDrop = strTape;
	else
		strDrop = strTape.Left(100) + "...";  // Don't add a really long string to the drop down

	// The first char of the string stores the radix as a char ('2'-'9', 'A'-'Z')
	char buf[64];
	if (state_ > CALCINTEXPR)
		buf[0] = ' ';               // space indicates we don't care about the radix because it's not an int
	else if (orig_radix_ < 10)
		buf[0] = orig_radix_ + '0';      // 0-9
	else
		buf[0] = orig_radix_ - 10 + 'A'; // A-Z
	buf[1] = '\0';

	CString * pResult = new CString(buf);   // Create the string to attach to the new drop-down hist list element

	// Put the result string on the heap so we can store it in the drop list item data
	edit_.get();   // Get the result string into current_str_
	int len = current_str_.GetLength();

	CString strAnswerOrigRadix;                        // result as string in original radix
	if (state_ >= CALCINTRES && state_ <= CALCINTEXPR)
	{
		// Short int result that needs conversion to original radix
		int numlen = mpz_sizeinbase(current_.get_mpz_t(), orig_radix_) + 3;
		char *numbuf = new char[numlen];
		numbuf[numlen-1] = '\xCD';

		// Get the number as a string
		mpz_get_str(numbuf, theApp.hex_ucase_? -orig_radix_ : orig_radix_, current_.get_mpz_t());
		ASSERT(numbuf[numlen-1] == '\xCD');

		strAnswerOrigRadix = numbuf;
		delete[] numbuf;

		// Add to the tape (history window)
		mm_->m_wndCalcHist.Add(strTape + " = " + 
							   strAnswerOrigRadix +
							   //CString(radix_ == orig_radix_ ? "" : radix_string(orig_radix_)) );
							   CString(radix_string(orig_radix_)) );
	}
	else
	{
		CString strType;
		switch (state_)
		{
		case CALCREALEXPR:
		case CALCREALRES:
			strType = " [REAL (dec)]";
			break;
		case CALCDATEEXPR:
		case CALCDATERES:
			strType = " [DATE]";
			break;
		case CALCSTREXPR:
		case CALCSTRRES:
			strType = " [STRING]";
			break;
		case CALCBOOLEXPR:
		case CALCBOOLRES:
			strType = " [BOOLEAN]";
			break;
		}
		mm_->m_wndCalcHist.Add(strTape + " = " + (CString)current_str_ + strType);
	}

	if (len < 2000 && state_ > CALCINTLIT)
	{
		// Short non-int result
		*pResult += current_str_;
	}
	else if (state_ > CALCINTLIT)      // not integer - probably a very long string
	{
		// Long non-int result
		*pResult += current_str_.Left(2000);
		*pResult += " ...";
	}
	else if (len < 2000 && radix_ != orig_radix_)
	{
		// Short int result in original radix
		*pResult += strAnswerOrigRadix;
	}
	else if (len < 2000 && radix_ == orig_radix_)
	{
		*pResult += current_str_;
	}
	else
	{
		// Large integer result (displayed in radix 10)
		const int extra = 2 + 1;  // Need room for possible sign, EOS, and dummy (\xCD) byte
		int numlen = mpz_sizeinbase(current_.get_mpz_t(), 10) + extra;
		char *numbuf = new char[numlen];
		numbuf[numlen-1] = '\xCD';

		// Get the number as a string
		mpz_get_str(numbuf, 10, current_.get_mpz_t());
		ASSERT(numbuf[numlen-1] == '\xCD');

		// Copy the most sig. digits copying sign if present, including decimal point after 1st digit
		const char * pin = numbuf;
		char * pout = buf;
		if (*pin == '-')
		{
			*pout = '-';
			++pin, ++pout;
			//numlen--;         // mpz_sizeinbase does not return room for sign
		}
		*pout++ = *pin++;
		*pout++ = theApp.dec_point_;
		for (int ii = 0; ii < 40; ++ii)
		{
			if (isdigit(*pin) || isalpha(*pin))
				*pout++ = *pin;
			++pin;
		}
		delete[] numbuf;

		// Add the exponent (decimal) and add initial 'A' to indicate that this number uses base 10
		sprintf(pout, " E %d", numlen - 1 - extra);
		*pResult = CString("A") + buf;
	}

	// Find any duplicate entry in the history (expression and result) and remove it
	for (int ii = 0; ii < ctl_edit_combo_.GetCount(); ++ii)
	{
		// Get expression and result for this item
		CString ss, * ps;
		ctl_edit_combo_.GetLBText(ii, ss);
		ps = (CString *)ctl_edit_combo_.GetItemDataPtr(ii);

		if (ss == strDrop && ps != NULL && *ps == *pResult)
		{
			// We also have to delete the string (here and when combo is destroyed)
			// It would have been easy just to handle WM_DELETEITEM but 
			// this is only sent for owner-draw combo boxes apparently.
			delete ps;

			ctl_edit_combo_.DeleteString(ii);       // remove this entry

			break;  // exit loop since the same value could not appear again
		}
	}

	// Add the new entry (at the top of the drop-down list)
	ctl_edit_combo_.InsertString(0, strDrop);
	ctl_edit_combo_.SetItemDataPtr(0, pResult);
}