void
TcpAgent::traceAll() {
	if (!channel_)
		return;

	double curtime;
	Scheduler& s = Scheduler::instance();
	char wrk[TCP_WRK_SIZE];

	curtime = &s ? s.clock() : 0;
	snprintf(wrk, TCP_WRK_SIZE,
		 "time: %-8.5f saddr: %-2d sport: %-2d daddr: %-2d dport:"
		 " %-2d maxseq: %-4d hiack: %-4d seqno: %-4d cwnd: %-6.3f"
		 " ssthresh: %-3d dupacks: %-2d rtt: %-6.3f srtt: %-6.3f"
		 " rttvar: %-6.3f bkoff: %-d\n", curtime, addr(), port(),
		 daddr(), dport(), int(maxseq_), int(highest_ack_),
		 int(t_seqno_), double(cwnd_), int(ssthresh_),
		 int(dupacks_), int(t_rtt_)*tcp_tick_, 
		 (int(t_srtt_) >> T_SRTT_BITS)*tcp_tick_, 
		 int(t_rttvar_)*tcp_tick_/4.0, int(t_backoff_)); 
	(void)Tcl_Write(channel_, wrk, -1);
}