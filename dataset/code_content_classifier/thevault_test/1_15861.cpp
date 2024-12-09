int line_input_formatter::input(void *buf, std::size_t len, int flags)
{
	char mybuf[1024];
	string::size_type ix;

	while (true) {
		ix = tmp.find('\n');
		if (ix!=string::npos)
			break;

		int i = formatterin(mybuf, sizeof mybuf, flags);

		if (i==-1)
			return -1;

		tmp += string(mybuf,i);
	}

	const char *ib = tmp.c_str();
	char *ob = (char*)buf;
	int count = 0;

	for (string::size_type i=0; i<ix; ++i)
		if (*ib!='\r') {
			*ob++ = *ib++;
			count++;
		}

	tmp.erase(0, ix+1);

	return count;
}