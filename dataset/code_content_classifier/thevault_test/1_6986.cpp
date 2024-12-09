char* MediaSegmentList::dump2buf()
{
	char *buf = new char[1024];
	char *b = buf;
	MediaSegment *p = (MediaSegment *)head_;
	int i = 0, sz = 1024;
	buf[0] = 0;
	while (p != NULL) {
		// XXX snprintf() should either be in libc or implemented
		// by TclCL (see Tcl2.cc there).
		i = snprintf(b, sz, "{%d %d} ", p->start(), p->end());
		sz -= i;
		// Boundary check: if less than 50 bytes, allocate new buf
		if (sz < 50) {
			char *tmp = new char[strlen(buf)+1024];
			strcpy(tmp, buf);
			delete []buf;
			buf = tmp;
			b = buf + strlen(buf);
			sz += 1024;
		} else 
			b += i;
		p = p->next();
	}
	return buf;
}