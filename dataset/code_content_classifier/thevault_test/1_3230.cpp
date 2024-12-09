void AddSpaces(CString &str)
{
	const char *pp, *end;               // Ptrs into orig. string
	int ndigits = 0;                    // Number of digits in string
	const char sep_char = ' ';  // Used to separate groups of digits
	const int group = 4;                // How many is in a group

	// Allocate enough space (allowing for space padding)
	char *out = new char[(str.GetLength()*(group+1))/group + 2]; // Result created here
	char *dd = out;                     // Ptr to current output char

	// Skip leading whitespace
	pp = str.GetBuffer(0);
	while (isspace(*pp))
		pp++;

	// Find end of number and work out how many digits it has
	end = pp + strspn(pp, " \t0123456789ABCDEFabcdef");
	for (const char *qq = pp; qq < end; ++qq)
		if (isxdigit(*qq))
			++ndigits;

	for ( ; ndigits > 0; ++pp)
		if (isxdigit(*pp))
		{
			*dd++ = *pp;
			if (--ndigits > 0 && ndigits%group == 0)
				*dd++ = sep_char;
		}
	ASSERT(pp <= end);
	strcpy(dd, pp);

	str = out;
	delete[] out;
}