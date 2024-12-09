NamStreamPipe*
NamStreamPipe::open_pipe(const char *fn)
{
	NamStreamPipe *p;

	for (p = head_; p; p = p->next_) {
		if (! strcmp(fn, p->pipename_))
			return p;
	}
	return new NamStreamPipe(fn);
}