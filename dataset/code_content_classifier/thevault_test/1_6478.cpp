int
FullTcpAgent::predict_ok(Packet* pkt)
{
	hdr_tcp *tcph = hdr_tcp::access(pkt);
        hdr_flags *fh = hdr_flags::access(pkt);

	/* not the fastest way to do this, but perhaps clearest */

	int p1 = (state_ == TCPS_ESTABLISHED);		// ready
	int p2 = ((tcph->flags() & (TH_SYN|TH_FIN|TH_ACK)) == TH_ACK); // ACK
	int p3 = ((flags_ & TF_NEEDFIN) == 0);		// don't need fin
	int p4 = (!ts_option_ || fh->no_ts_ || (tcph->ts() >= recent_)); // tsok
	int p5 = (tcph->seqno() == rcv_nxt_);		// in-order data
	int p6 = (t_seqno_ == maxseq_);			// not re-xmit
	int p7 = (!ecn_ || fh->ecnecho() == 0);		// no ECN
	int p8 = (tcph->sa_length() == 0);		// no SACK info

	return (p1 && p2 && p3 && p4 && p5 && p6 && p7 && p8);
}