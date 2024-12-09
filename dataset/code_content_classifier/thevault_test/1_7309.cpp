char * fl_utf2mbcs(const char *s)
{
	if (!s) return NULL;
#if defined(WIN32) && !defined(__CYGWIN__)
	int l = strlen(s);
	static char *buf = NULL;

//	mbwbuf = (xchar*)realloc(mbwbuf, (l+6) * sizeof(xchar));
//	l = fl_utf2unicode((unsigned char*)s, l, mbwbuf);
//	mbwbuf[l] = 0;
	unsigned wn = fl_utf8toUtf16(s, l, NULL, 0) + 7; // Query length
	mbwbuf = (xchar*)realloc(mbwbuf, sizeof(xchar)*wn);
	l = fl_utf8toUtf16(s, l, (unsigned short *)mbwbuf, wn); // Convert string
	mbwbuf[l] = 0;

	buf = (char*)realloc(buf, l * 6 + 1);
	l = wcstombs(buf, mbwbuf, l * 6);
	buf[l] = 0;
	return buf;
#else
	return (char*) s;
#endif
}