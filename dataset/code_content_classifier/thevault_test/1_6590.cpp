void TcpAgent::newtimer(Packet* pkt)
{
	hdr_tcp *tcph = hdr_tcp::access(pkt);
	/*
	 * t_seqno_, the next packet to send, is reset (decreased) 
	 *   to highest_ack_ + 1 after a timeout,
	 *   so we also have to check maxseq_, the highest seqno sent.
	 * In addition, if the packet sent after the timeout has
	 *   the ECN bit set, then the returning ACK caused cwnd_ to
	 *   be decreased to less than one, and we can't send another
	 *   packet until the retransmit timer again expires.
	 *   So we have to check for "cwnd_ < 1" as well.
	 */
	if (t_seqno_ > tcph->seqno() || tcph->seqno() < maxseq_ || cwnd_ < 1) 
		set_rtx_timer();
	else
		cancel_rtx_timer();
}