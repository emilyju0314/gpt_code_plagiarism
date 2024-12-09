int
FullTcpAgent::outflags()
{
	// in real TCP an RST is added in the CLOSED state
	static int tcp_outflags[TCP_NSTATES] = {
		TH_ACK,          	/* 0, CLOSED */  
		0,                      /* 1, LISTEN */ 
		TH_SYN,                 /* 2, SYN_SENT */
		TH_SYN|TH_ACK,          /* 3, SYN_RECEIVED */
		TH_ACK,                 /* 4, ESTABLISHED */
		TH_ACK,                 /* 5, CLOSE_WAIT */
		TH_FIN|TH_ACK,          /* 6, FIN_WAIT_1 */
		TH_FIN|TH_ACK,          /* 7, CLOSING */
		TH_FIN|TH_ACK,          /* 8, LAST_ACK */
		TH_ACK,                 /* 9, FIN_WAIT_2 */
		/* 10, TIME_WAIT --- not used in simulator */
	};

	if (state_ < 0 || (state_ >= TCP_NSTATES)) {
		fprintf(stderr, "%f FullTcpAgent(%s): invalid state %d\n",
			now(), name(), state_);
		return (0x0);
	}

	return (tcp_outflags[state_]);
}