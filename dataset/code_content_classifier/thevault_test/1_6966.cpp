void
NamStreamPipe::timer_handler(ClientData data)
{
	if (read_pipe())
		timer_ = Tcl_CreateTimerHandler(10, timer_handler, NULL);
	else	timer_ = NULL;
}