void BayFullTcpAgent::newack(Packet* pkt)
{
    hdr_tcp *tcph = hdr_tcp::access(pkt);

	register int ackno = tcph->ackno();

	// we were timing the segment and we
	// got an ACK for it
	if (rtt_active_ && ackno >= rtt_seq_) {
		/* got a rtt sample */
		rtt_active_ = FALSE;	// no longer timing
		t_backoff_ = 1;		// stop exp backoff
	}

	/* always with timestamp option */
	double tao = now() - tcph->ts();
	rtt_update(tao);

	if (ackno >= maxseq_)
		cancel_rtx_timeout();
	else {
		if (ackno > highest_ack_) {
			set_rtx_timer();
		}
	}

	// advance the ack number if this is for new data
	if (ackno > highest_ack_)
		highest_ack_ = ackno;
	// set up the next packet to send
	if (t_seqno_ < highest_ack_)
		t_seqno_ = highest_ack_;	// thing to send next
}