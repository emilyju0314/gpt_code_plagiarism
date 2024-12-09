__int64 strtoi64(const char *ss, int radix, const char **endptr)
{
	if (radix == 0) radix = 10;

	__int64 retval = 0;

	unsigned __int64 maxval = _UI64_MAX / radix;

	const char * src;
	for (src = ss; *src != '\0'; ++src)
	{
		// Ignore everything except valid digits
		unsigned int digval;
		if (isdigit(*src))
			digval = *src - '0';
		else if (isalpha(*src))
			digval = toupper(*src) - 'A' + 10;
		else
			break;   // Not a digit

		if (digval >= radix)
			break;   // Digit too large for radix

		if (retval < maxval || (retval == maxval && (unsigned __int64)digval <= _UI64_MAX % radix))
			retval = retval * radix + digval;
		else
			break;  // overflow
	}

	if (endptr != NULL)
		*endptr = src;

	return retval;
}