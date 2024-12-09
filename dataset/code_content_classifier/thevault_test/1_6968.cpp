char *
NamStreamPipe::gets(char *buf, int len)
{
	char *ret = buf;
	off_t off = ftell(back_);

	read_pipe();

	/*
	 * Case 1: The pipe is just opened to read, but the other end
	 *         of the pipe has not open it to write. So, read_pipe()
	 *         will close it.
	 *         => Reopen the pipe, and return a fake initial command.
	 * Case 2: Both ends have opened the pipe, but the writer has not
	 *         produced any data.
	 *         => Return a fake initial command.
	 * The fake return value needs to be an initial command. Comment
	 * lines or empty lines are not accepted by nam (e.g. see animator.tcl)
	 *
	 */
	if (back_len_ == 0) {
#ifndef WIN32
		// Windows doesn't have O_NONBLOCK
		if (front_ == -1) {   // it may be closed by read_pipe()
			front_ = ::open(pipename_, O_RDONLY | O_NONBLOCK);
		}
#endif
		strcpy(buf, "V -t * -v 1.0a9 -a 0\n");
		return buf;
	}

	while (1) {
	/*
	 * Case 3: The backup file is over, but there is no new data in pipe.
	 *         => Busy waiting for new input.	XXX
	 *            This is not a good idea. Since nam is a
	 *            single-thread application, busy waiting makes nam
	 *            unable to handle other events (e.g. Window, I/O events).
	 *            The problem here is that we don't know what to return
	 *            when there is no new input from the pipe.
	 *            (see netmodel.cc#NetModel::handle())
	 */
		if (! fgets(buf, len, back_)) {	// EOF backup file
			if (front_ == -1)
				return NULL;
			else	read_pipe();
		}
	/*
	 * Case 4: The backup file is near to over and the last line is
	 *         not complete.
	 *         => Busy waiting for new input.	XXX
	 */
		else {
			int n = strlen(buf) - 1;
			if (buf[n] == '\n')	// here is the normal case
				return buf;
			if (front_ == -1)
				return NULL;
			fseek(back_, off, SEEK_SET);
			read_pipe();
		}
	}
	return ret;
}