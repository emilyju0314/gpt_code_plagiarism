void AddCommas(CString &str)
{
	const char *pp, *end;                   // Ptrs into orig. string
	int ndigits = 0;                        // Number of digits in string
//	struct lconv *plconv = localeconv(); // Locale settings (grouping etc) are now just read once in InitInstance

	// Allocate enough space (allowing for space padding)
	char *out = new char[(str.GetLength()*(theApp.dec_group_+1))/theApp.dec_group_ + 2]; // Result created here
	char *dd = out;                     // Ptr to current output char

	// Skip leading whitespace
	pp = str.GetBuffer(0);
	while (isspace(*pp))
		pp++;

	// Keep initial sign if any
	if (*pp == '+' || *pp == '-')
		*dd++ = *pp++;

	// Find end of number and work out how many digits it has
	end = pp + strspn(pp, ", \t0123456789");
	for (const char *qq = pp; qq < end; ++qq)
		if (isdigit(*qq))
			++ndigits;

	for ( ; ndigits > 0; ++pp)
		if (isdigit(*pp))
		{
			*dd++ = *pp;
			if (--ndigits > 0 && ndigits%theApp.dec_group_ == 0)
				*dd++ = theApp.dec_sep_char_;
		}
	ASSERT(pp <= end);
	strcpy(dd, pp);

	str = out;
	delete[] out;
}