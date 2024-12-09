void
FullTcpAgent::newack(Packet* pkt)
{
	hdr_tcp *tcph = hdr_tcp::access(pkt);

	register int ackno = tcph->ackno();
	int progress = (ackno > highest_ack_);

	if (ackno == maxseq_) {
		cancel_rtx_timer();	// all data ACKd
	} else if (progress) {
		set_rtx_timer();
	}

	// advance the ack number if this is for new data
	if (progress)
		highest_ack_ = ackno;

	// if we have suffered a retransmit timeout, t_seqno_
	// will have been reset to highest_ ack.  If the
	// receiver has cached some data above t_seqno_, the
	// new-ack value could (should) jump forward.  We must
	// update t_seqno_ here, otherwise we would be doing
	// go-back-n.

	if (t_seqno_ < highest_ack_)
		t_seqno_ = highest_ack_; // seq# to send next

        /*
         * Update RTT only if it's OK to do so from info in the flags header.
         * This is needed for protocols in which intermediate agents

         * in the network intersperse acks (e.g., ack-reconstructors) for
         * various reasons (without violating e2e semantics).
         */
        hdr_flags *fh = hdr_flags::access(pkt);

	if (!fh->no_ts_) {
                if (ts_option_) {
			recent_age_ = now();
			recent_ = tcph->ts();
			rtt_update(now() - tcph->ts_echo());
			if (ts_resetRTO_ && (!ect_ || !ecn_backoff_ ||
		           !hdr_flags::access(pkt)->ecnecho())) { 
				// From Andrei Gurtov
				//
                         	// Don't end backoff if still in ECN-Echo with
                         	// a congestion window of 1 packet.
				t_backoff_ = 1;
			}
		} else if (rtt_active_ && ackno > rtt_seq_) {
			// got an RTT sample, record it
			// "t_backoff_ = 1;" deleted by T. Kelly.
			rtt_active_ = FALSE;
			rtt_update(now() - rtt_ts_);
                }
		if (!ect_ || !ecn_backoff_ ||
		    !hdr_flags::access(pkt)->ecnecho()) {
			/*
			 * Don't end backoff if still in ECN-Echo with
			 * a congestion window of 1 packet.
			 * Fix from T. Kelly.
			 */
			t_backoff_ = 1;
			ecn_backoff_ = 0;
		}

        }
	return;
}