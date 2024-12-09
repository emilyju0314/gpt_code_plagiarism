int
NamStreamPipe::read(char *buf, int len)
{
	read_pipe();
	return fread(buf, 1, len, back_);
}