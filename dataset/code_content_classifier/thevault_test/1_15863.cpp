int length_input_formatter::input(void *buf, std::size_t len, int flags)
{
	char mybuf[1024];

	while (tmp.length()<sizeof(int)) {
		int i = formatterin(mybuf, sizeof mybuf, flags);
		if (i==-1)
			return -1;

		tmp += string(mybuf,i);
	}

	int expect = ntohl(*reinterpret_cast<const int*>(tmp.c_str()));

	while (tmp.length()<sizeof(int)+expect) {
		int i = formatterin(mybuf, sizeof mybuf, flags);
		if (i==-1)
			return -1;

		tmp += string(mybuf,i);
	}

	memcpy(buf, tmp.c_str()+sizeof(int), expect);
	tmp.erase(0, expect+sizeof(int));

	return expect;
}