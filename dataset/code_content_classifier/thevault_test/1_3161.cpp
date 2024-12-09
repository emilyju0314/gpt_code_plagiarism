CString CHexEditView::DescChar(int cc)
{
	CString retval;

	static char *ascii_control_char[] =
	{
		"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
		"BS",  "HT",  "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
		"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
		"CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US",
		"space", "**ERROR"
	};

	static char *ebcdic_control_char[] =
	{
		"NUL", "SOH", "STX", "ETX", "PF",  "HT",  "LC",  "DEL",
		"GE",  "RLF", "SMM", "VT",  "FF",  "CR",  "SO",  "SI",
		"DLE", "DC1", "DC2", "TM",  "RES", "NL",  "BS",  "IL",
		"CAN", "EM",  "CC",  "CU1", "IFS", "IGS", "IRS", "IUS",
		"DS",  "SOS", "FS",  "",    "BYP", "LF",  "ETB", "ESC",
		"",    "",    "SM",  "CU2", "",    "ENQ", "ACK", "BEL",
		"",    "",    "SYN", "",    "PN",  "RS",  "UC",  "EOT",
		"",    "",    "",    "CU3", "DC4", "NAK", "",    "SUB",
		"space","**ERROR"
	};

	if (EbcdicMode())
	{
		if (e2a_tab[cc] != '\0')
			retval.Format("'%c'", e2a_tab[cc]);
		else if (cc < sizeof(ebcdic_control_char)/sizeof(*ebcdic_control_char))
			retval = ebcdic_control_char[cc];
	}
	else if (cc >= 0x20 && cc < 0x7F || AnsiMode())
	{
		// Normal ASCII char
		retval.Format("'%c'", cc);
	}
	else if (OemMode())
	{
		// do nothing for other OEM chars
	}
	else if (cc < 0x20)
	{
		// ASCII Control char
		if (cc > 0 && cc < 27)
			retval.Format("%s [^%c]", ascii_control_char[cc], cc+0x40);
		else
			retval = ascii_control_char[cc];
	}
	else if (AsciiMode())
	{
		// do nothing for other ASCII chars
	}
	else if (code_page_ == CP_UTF8)
	{
		ASSERT(CodePageMode() && cc > 0x7F);
		if ((cc & 0xC0) == 0x80)
			retval = "cont";
		//else if ((cc & 0x0xE0) -- 0xC0)
		//	retval = "UTF2";
		//else if ((cc & 0x0xF0) -- 0xE0)
		//	retval = "UTF3";
		//else if ((cc & 0x0xF8) -- 0xF0)
		//	retval = "UTF4";
		//else if ((cc & 0x0xFC) -- 0xF8)
		//	retval = "UTF5";
		//else if ((cc & 0x0xFE) -- 0xFC)
		//	retval = "UTF6";
	}
	else
	{
		ASSERT(CodePageMode());
		if (::IsDBCSLeadByteEx(code_page_, cc))
			retval = "lead-in";
	}
	return retval;
}