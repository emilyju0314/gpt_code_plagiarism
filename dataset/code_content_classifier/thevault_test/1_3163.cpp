std::vector<FILE_ADDRESS> CHexEditView::codepage_startchar(FILE_ADDRESS fst, FILE_ADDRESS lst)
{
	ASSERT(display_.char_set == CHARSET_CODEPAGE && max_cp_bytes_ > 1 && code_page_ != CP_UTF8);
	std::vector<FILE_ADDRESS> retval;

	FILE_ADDRESS aa = fst - 16;  // We need to start well before the display top to make sure we are in sync
	if (aa < 0) aa = 0;                         // Don't go back before start of file

	// Get buffer of data to check
	size_t len = size_t(lst - aa) + max_cp_bytes_;  // this gets (fst-aa) extra bytes at the start AND an extra max_cp_bytes_ at the end
	char *buf = new char[len];
	size_t got = GetDocument()->GetData((unsigned char *)buf, len-1, aa);
	ASSERT(got >= size_t(lst - aa));
	buf[got] = '\0';                            // Add a string teminator just to make sure we don't run off the end of the data

	FILE_ADDRESS nn = fst;                      // nn is address of the start of the next line
	for ( const char *pp = buf; ; )
	{
		// Have we reached the end of this row yet?
		// Note that the number of bytes in a "char" may be 5 or more which is longer than the minimum row size (4)
		//      so some rows may have the same address (ie a row may be all leader bytes).
		while (aa >= nn && nn < lst)
		{
			retval.push_back(aa);               // save this address as the start of the first "char" in this row
			nn += rowsize_;                     // get start of next line
		}

		// Have we got to the end of all rows?
		if (aa >= lst && nn >= lst)
			break;

		// Find the start of the next character
		const char *prev = pp;
		pp = CharNextExA(code_page_, prev, 0);
		if (pp == prev) ++pp;                   // skip nul (and error?) bytes
		aa += pp - prev;                        // update the address to match
	}
	delete[] buf;

	// xxx can we resurrect these assertions (fail with short last line)
	//ASSERT(nn == lst);
	//ASSERT(retval.size() == (lst - fst)/rowsize_);  // must have an entry for all lines of the display
	retval.push_back(-1);   // We add an extra dummy entry to simplify calcs for byte past end of file
	return retval;
}