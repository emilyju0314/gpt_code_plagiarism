void
BayFullTcpAgent::advance(int np)
{
	// XXX hack:
	//	because np is in packets and a data source
	//	may pass a *huge* number as a way to tell us
	//	to go forever, just look for the huge number
	//	and if it's there, pre-divide it
	if (np >= 0x10000000)
		np /= maxseg_;

	curseq_ += (np * maxseg_);

	//
	// state-specific operations:
	//	if CLOSED, do an active open/connect
	//	if ESTABLISHED, just try to send more
	//	if above ESTABLISHED, we are closing, so don't allow
	//	if anything else (establishing), do nothing here
	//
	if (state_ > TCPS_ESTABLISHED) {
		fprintf(stderr,
		 "%f: BayFullTcpAgent::advance(%s): cannot advance while in state %d\n",
		 now(), name(), state_);
		return;
	} else if (state_ == TCPS_CLOSED)	{
		connect();		// initiate new connection
	} else if (state_ == TCPS_ESTABLISHED)
		send_much(0, REASON_NORMAL, 0);
	return;
}