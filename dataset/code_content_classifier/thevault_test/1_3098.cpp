void CFindSheet::HexFromText(const char *ss, size_t len /*=-1*/)
{
	size_t length = len == -1 ?  strlen(ss) : len;

	if (length == 0)
	{
		hex_string_.Empty();
		mask_string_.Empty();
		return;
	}

	char *out_hex = new char[length*6+1];  // where hex string is built
	char *out_msk = new char[length*6+1];  // where mask is built
	char *po1 = out_hex;
	char *po2 = out_msk;
	const char *pp;                         // Ptr into input (ASCII char) string
	BOOL bad_chars = FALSE;                 // Any unrecognised characters for the char set

	// Display hex in upper or lower case?
	const char *hex_fmt;
	if (theApp.hex_ucase_)
		hex_fmt = "%02X ";
	else
		hex_fmt = "%02x ";

	for (pp = ss; *pp != '\0'; ++pp)
	{
		int out_count = 0;

		if (charset_ == RB_CHARSET_ASCII)
		{
			sprintf(po1, hex_fmt, (unsigned char)*pp);
			po1 += 3;
			out_count = 1;
		}
		else if (charset_ == RB_CHARSET_UNICODE)
		{
			wchar_t ww;

			// Convert ASCII character to wide char then to hex digits
			if (mbtowc(&ww, pp, 1) == 1)
			{
				sprintf(po1, hex_fmt, ww & 0xFF);
				po1 += 3;
				sprintf(po1, hex_fmt, (ww>>8) & 0xFF);
				po1 += 3;
				out_count = 2;
			}
		}
		else if (charset_ == RB_CHARSET_EBCDIC)
		{
			if (*pp < 128 && *pp >= 0 && a2e_tab[*pp] != '\0')
			{
				sprintf(po1, hex_fmt, a2e_tab[(unsigned char)*pp]);
				po1 += 3;
				out_count = 1;
			}
		}
		else
			ASSERT(0);

		// Add the mask characters
		while (out_count--)
		{
			if (wildcards_allowed_ && *pp == wildcard_char_[0])
				strcpy(po2, "00 ");
			else if (theApp.hex_ucase_)
				strcpy(po2, "FF ");
			else
				strcpy(po2, "FF ");
			po2 += 3;
		}
	}
	if (po1 > out_hex)
	{
		// Forget trailing space
		po1--;
		po2--;
	}
	*po1 = *po2 = '\0';                 // Terminate string

	hex_string_ = out_hex;
	mask_string_ = out_msk;
	delete[] out_hex;
	delete[] out_msk;
}