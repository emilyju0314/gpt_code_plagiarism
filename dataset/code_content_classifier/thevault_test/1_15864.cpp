int fixed_input_formatter::input(void *buf, std::size_t len, int flags)
{
	char mybuf[1024];

	while (tmp.length()<len) {
		int i = formatterin(mybuf, sizeof mybuf, flags);
		if (i==-1)
			return -1;

		tmp += string(mybuf,i);
	}
	memcpy(buf, tmp.c_str(), len);
	tmp.erase(0, len);

	return len;
}