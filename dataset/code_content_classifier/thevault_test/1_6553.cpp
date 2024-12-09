const char *make_query(u_4bytes query) {
	static char buf[128];

	sprintf(buf, "?%d", query);

	return buf;
}