void TcpAgent::recv_frto_helper(Packet *pkt)
{
	hdr_tcp *tcph = hdr_tcp::access(pkt);
	if (tcph->seqno() == last_ack_ && frto_ != 0) {
		/*
		 * Duplicate ACK while in F-RTO indicates that the
		 * timeout was valid. Go to slow start retransmissions.
		 */
		t_seqno_ = highest_ack_ + 1;
		cwnd_ = frto_;
		frto_ = 0;

		// Must zero dupacks (in order to trigger send_much at recv)
		// dupacks is increased in recv after exiting this function
		dupacks_ = -1;
	}
}