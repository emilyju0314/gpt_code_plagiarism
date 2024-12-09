CString bin_str(__int64 val, int bits)
{
	ASSERT(bits <= 64);
	char buf[100], *pp = buf;

	for (int ii = 0; ii < bits; ++ii)
	{
		if (ii%8 == 0)
			*pp++ = ' ';
		*pp++ = (val&(_int64(1)<<ii)) ? '1' : '0';
	}
	*pp = '\0';

	CString retval(buf+1);
	retval.MakeReverse();
	return retval;
}