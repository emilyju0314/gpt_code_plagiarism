void TcpAgent::process_qoption_after_send ()
{
	int tcp_now = (int)(Scheduler::instance().clock()/tcp_tick_ + 0.5);
	int rto = (int)(t_rtxcur_/tcp_tick_) ; 
	/*double ct = Scheduler::instance().clock();*/

	if (!EnblRTTCtr_) {
		if (tcp_now - T_last >= rto) {
			// The sender has been idle.
		 	slowdown(THREE_QUARTER_SSTHRESH|TCP_IDLE) ;
			for (int i = 0 ; i < (tcp_now - T_last)/rto; i ++) {
				slowdown(CWND_HALF_WITH_MIN|TCP_IDLE);
			}
			T_prev = tcp_now ;
			W_used = 0 ;
		}
		T_last = tcp_now ;
		if (t_seqno_ == highest_ack_+ window()) {
			T_prev = tcp_now ; 
			W_used = 0 ; 
		}
		else if (t_seqno_ == curseq_-1) {
			// The sender has no more data to send.
			int tmp = t_seqno_ - highest_ack_ ;
			if (tmp > W_used)
				W_used = tmp ;
			if (tcp_now - T_prev >= rto) {
				// The sender has been application-limited.
				slowdown(THREE_QUARTER_SSTHRESH|TCP_IDLE);
				slowdown(CLOSE_CWND_HALF_WAY|TCP_IDLE);
				T_prev = tcp_now ;
				W_used = 0 ;
			}
		}
	} else {
		rtt_counting();
	}
}