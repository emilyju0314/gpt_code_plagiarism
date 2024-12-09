void CFindSheet::FixHexString()
{
	int count;
	char *out_hex = new char[hex_string_.GetLength()*3/2+2];
	char *out_msk = new char[__max(hex_string_.GetLength(), mask_string_.GetLength())*3/2+2];
	char *po1 = out_hex;
	char *po2 = out_msk;

	const char *p1 = hex_string_;
	const char *p2 = mask_string_;

	for (count = 0; ; ++count)
	{
		// Skip unrecognised characters in both strings
		while (*p1 != '\0' && !isxdigit(*p1) && *p1 != '?')
			++p1;
		while (*p2 != '\0' && !isxdigit(*p2))
			++p2;

		// Finished if end of hex string and rest of mask contains nothing but F's
		if (*p1 == '\0' && (*p2 == '\0' || strcspn(p2, "0123456789abcdefABCDEF") == strlen(p2)))
			break;

		// If we haven't reached the end of the hex string put out the digit in correct case
		if (*p1 != '\0')
		{
			if (theApp.hex_ucase_)
				*po1++ = toupper(*p1);
			else
				*po1++ = tolower(*p1);

			// Put a space between every pair of digits
			if (count%2 == 1)
				*po1++ = ' ';
		}

		if (*p1 == '?')                             // ? matches any digit so use mask of zero
		{
			wildcards_allowed_ = TRUE;
			*po2++ = '0';
		}
		else if (*p1 != '\0' && *p2 == '\0')        // End of mask but not end of search so pad with F's
			*po2++ = theApp.hex_ucase_ ? 'F' : 'f';
		else if (theApp.hex_ucase_)
			*po2++ = toupper(*p2);
		else
			*po2++ = tolower(*p2);

		if (count%2 == 1)
			*po2++ = ' ';

		// Move the ptr forward in both strings
		if (*p1 != '\0')
			++p1;
		if (*p2 != '\0')
			++p2;
	}

	*po1 = *po2 = '\0';

	hex_string_ = out_hex;
	mask_string_ = out_msk;

	// If a question mark was typed we want to turn on wildcard searches
	if (wildcards_allowed_ && GetActivePage() == p_page_hex_)
	{
		ASSERT(p_page_hex_->GetDlgItem(IDC_FIND_USE_MASK) != NULL);
		((CButton *)p_page_hex_->GetDlgItem(IDC_FIND_USE_MASK))->SetCheck(1);
	}
//    GetActivePage()->UpdateData(FALSE);
}