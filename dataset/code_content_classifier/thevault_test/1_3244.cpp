static const unsigned char * memmem(const unsigned char * buf, size_t buflen, const unsigned char * to_find, size_t to_find_len)
{
	for (const unsigned char * pp = buf; pp < buf + buflen - to_find_len; ++pp)
		if (memcmp(pp, to_find, to_find_len) == 0)
			return pp;

	return NULL;
}