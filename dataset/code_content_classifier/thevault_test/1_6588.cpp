void TcpAgent::send_much(int force, int reason, int maxburst)
{
	send_idle_helper();
	int win = window();
	int npackets = 0;

	if (!force && delsnd_timer_.status() == TIMER_PENDING)
		return;
	/* Save time when first packet was sent, for newreno  --Allman */
	if (t_seqno_ == 0)
		firstsent_ = Scheduler::instance().clock();

	if (burstsnd_timer_.status() == TIMER_PENDING)
		return;
	while (t_seqno_ <= highest_ack_ + win && t_seqno_ < curseq_) {
		if (overhead_ == 0 || force || qs_approved_) {
			output(t_seqno_, reason);
			npackets++;
			if (QOption_)
				process_qoption_after_send () ; 
			t_seqno_ ++ ;
			if (qs_approved_ == 1) {
				// delay = effective RTT / window
				double delay = (double) t_rtt_ * tcp_tick_ / win;
				if (overhead_) { 
					delsnd_timer_.resched(delay + Random::uniform(overhead_));
				} else {
					delsnd_timer_.resched(delay);
				}
				return;
			}
		} else if (!(delsnd_timer_.status() == TIMER_PENDING)) {
			/*
			 * Set a delayed send timeout.
			 */
			delsnd_timer_.resched(Random::uniform(overhead_));
			return;
		}
		win = window();
		if (maxburst && npackets == maxburst)
			break;
	}
	/* call helper function */
	send_helper(maxburst);
}