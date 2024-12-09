void
TcpAgent::rtt_counting()
{
        int tcp_now = (int)(Scheduler::instance().clock()/tcp_tick_ + 0.5);
	int rtt = (int(t_srtt_) >> T_SRTT_BITS) ;

	if (rtt < 1) 
		rtt = 1 ;
	if (tcp_now - T_last >= 2*rtt) {
		// The sender has been idle.
		int RTTs ; 
		RTTs = (tcp_now -T_last)*RTT_goodcount/(rtt*2) ; 
		RTTs = RTTs - Backoffs ; 
		Backoffs = 0 ; 
		if (RTTs > 0) {
			slowdown(THREE_QUARTER_SSTHRESH|TCP_IDLE) ;
			for (int i = 0 ; i < RTTs ; i ++) {
				slowdown(CWND_HALF_WITH_MIN|TCP_IDLE);
				RTT_prev = RTT_count ; 
				W_used = 0 ;
			}
		}
	}
	T_last = tcp_now ;
	if (tcp_now - T_start >= 2*rtt) {
		if ((RTT_count > RTT_goodcount) || (F_full == 1)) {
			RTT_goodcount = RTT_count ; 
			if (RTT_goodcount < 1) RTT_goodcount = 1 ; 
		}
		RTT_prev = RTT_prev - RTT_count ;
		RTT_count = 0 ; 
		T_start  = tcp_now ;
		F_full = 0;
	}
	if (t_seqno_ == highest_ack_ + window()) {
		W_used = 0 ; 
		F_full = 1 ; 
		RTT_prev = RTT_count ;
	}
	else if (t_seqno_ == curseq_-1) {
		// The sender has no more data to send.
		int tmp = t_seqno_ - highest_ack_ ;
		if (tmp > W_used)
			W_used = tmp ;
		if (RTT_count - RTT_prev >= 2) {
			// The sender has been application-limited.
			slowdown(THREE_QUARTER_SSTHRESH|TCP_IDLE) ;
			slowdown(CLOSE_CWND_HALF_WAY|TCP_IDLE);
			RTT_prev = RTT_count ; 
			Backoffs ++ ; 
			W_used = 0;
		}
	}
	if (F_counting == 0) {
		W_timed = t_seqno_  ;
		F_counting = 1 ;
	}
}