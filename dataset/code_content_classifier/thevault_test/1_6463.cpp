void
FullTcpAgent::sendmsg(int nbytes, const char *flags)
{
	if (flags && strcmp(flags, "MSG_EOF") == 0) 
		close_on_empty_ = TRUE;	
	if (flags && strcmp(flags, "DAT_EOF") == 0) 
		signal_on_empty_ = TRUE;	

	if (nbytes == -1) {
		infinite_send_ = TRUE;
		advance_bytes(0);
	} else
		advance_bytes(nbytes);
}