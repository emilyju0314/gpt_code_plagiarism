void TcpAsymAgent::output_helper(Packet* p) 
{
	hdr_tcpasym *tcpha = hdr_tcpasym::access(p);
	hdr_flags *flagsh = hdr_flags::access(p);

	tcpha->win() = min(highest_ack_+window(), curseq_) - t_seqno_;
	tcpha->highest_ack() = highest_ack_;
	tcpha->max_left_to_send() = curseq_ - highest_ack_; /* XXXX not needed? */

	flagsh->ecnecho() = ecn_to_echo_;
	ecn_to_echo_ = 0;
}