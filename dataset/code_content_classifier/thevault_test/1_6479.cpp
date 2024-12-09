int
FullTcpAgent::fast_retransmit(int seq)
{
	// we are now going to fast-retransmit and willtrace that event
	trace_event("FAST_RETX");
	
	recover_ = maxseq_;	// recovery target
	last_cwnd_action_ = CWND_ACTION_DUPACK;
	return(foutput(seq, REASON_DUPACK));	// send one pkt
}