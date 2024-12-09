int
BayFullTcpAgent::advance(int n, int close_flag)
{
	close_on_empty_ = close_flag;

	//
	// state-specific operations:
	//	if CLOSED, do an active open/connect
	//	if ESTABLISHED, just try to send more
	//	if above ESTABLISHED, we are closing, so don't allow
	//	if anything else (establishing), do nothing here
	//
	if (state_ > TCPS_ESTABLISHED) {
		return 0;	//try again later, please
	} else if (state_ == TCPS_CLOSED)	{
		curseq_ = iss_ + n;
		reinit();
		connect();		// initiate new connection
	}
	else if (state_ == TCPS_ESTABLISHED)
		curseq_ += n;	
	else
		return 0;
	return 1;
}