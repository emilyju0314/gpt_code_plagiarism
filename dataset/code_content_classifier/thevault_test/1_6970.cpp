char
NamStreamPipe::get_char()
{
	read_pipe();
	return fgetc(back_);
}