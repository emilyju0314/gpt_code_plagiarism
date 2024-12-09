int length_output_formatter::output(const void *buf, std::size_t len, int flags)
{
	int val;
	char *newbuf = new char[len+sizeof(int)];
	memcpy(newbuf+sizeof(int), buf, len);
	*reinterpret_cast<int*>(newbuf) = htonl(len);

	try {
		val = formatterout((const void*)newbuf,len+sizeof(int),flags);
	}
	catch (...) {
		delete[] newbuf;
		throw;
	}

	delete[] newbuf;
	return val-sizeof(int);
}