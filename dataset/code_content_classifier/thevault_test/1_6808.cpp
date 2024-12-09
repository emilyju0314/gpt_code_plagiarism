void BayFullTcpAgent::send_much(int force, int reason, int maxburst)
{

	/*
	 * highest_ack is essentially "snd_una" in real TCP
	 *
	 * loop while we are in-window (seqno <= (highest_ack + win))
	 * and there is something to send (t_seqno_ < curseq_+iss_)
	 */
	int win = window() * maxseg_;	// window() in pkts
	int npackets = 0;
	int topwin = curseq_ + iss_;
	if (topwin > highest_ack_ + win)
		topwin = highest_ack_ + win;

	if (!force && (delsnd_timer_.status() == TIMER_PENDING))
		return;

	while (force || (t_seqno_ < topwin)) {
		if (overhead_ != 0 && !(delsnd_timer_.status() == TIMER_PENDING)) {
			delsnd_timer_.resched(Random::uniform(overhead_));
			return;
		}
		output(t_seqno_, reason);	// updates seqno for us
		force = 0;
		if (outflags() & TH_SYN)
			break;
		if (maxburst && ++npackets >= maxburst)
			break;
	}
}