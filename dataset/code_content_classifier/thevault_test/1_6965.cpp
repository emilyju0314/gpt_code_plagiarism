char *
NamStream::rgets(char *buf, int len)
{
	int ch;

	/*
	 * prior-line \n current-line \n next-line
	 *
	 * Initially the cursor is on the n of next-line.
	 * read in current-line (which is behind us)
	 * return it
	 * leave the cursor on c of current line.
	 */

	/* first make sure we back over the prior newline, if any */
	if (seek(-1, SEEK_CUR) < 0)
		return NULL;
	ch = get_char();
	if (seek(ch == '\n' ? -2 : -1, SEEK_CUR) < 0)
		return NULL;
	/* now loop backwards until we get to the newline separating
	 * prior and current.
	 */
	off_t pos = tell();
	for(;;) {
		ch = get_char();
		if (ch == '\n')
			break;
		if (pos == 0) {
			// beginning of file
			if (seek(-1, SEEK_CUR) < 0)
				return NULL;
			break;
		}
		// back up a char & try again
		pos--;
		if (seek(-2, SEEK_CUR) < 0)
			return NULL;
	};
	/* we're just passed the newline for prior-line, or we're at 0 */
	/* read current-line, then reset the pointer there */
	gets(buf, len);
	if (pos != seek(pos, SEEK_SET))
		return NULL;
	return buf;
}