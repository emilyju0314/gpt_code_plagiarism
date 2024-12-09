void BayFullTcpAgent::fast_retransmit(int seq)
{       
        rtt_backoff();                  // bug fix by van to avoid spurious rtx
	int onxt = t_seqno_;		// output() changes t_seqno_
	recover_ = maxseq_;		// keep a copy of highest sent
	recover_cause_ = REASON_DUPACK;	// why we started this recovery period
	output(seq, REASON_DUPACK);	// send one pkt
	t_seqno_ = onxt;
}