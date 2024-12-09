int line_output_formatter::output(const void *buf, std::size_t len, int flags)
{
	int val;
	char *newbuf = new char[len+2];

	memcpy(newbuf, buf, len);
	memcpy(newbuf+len, "\r\n", 2);

	try {
		val = formatterout(newbuf,len+2,flags);
	}
	catch (...) {
		delete[] newbuf;
		throw;
	}

	delete[] newbuf;
	return val-2;
}