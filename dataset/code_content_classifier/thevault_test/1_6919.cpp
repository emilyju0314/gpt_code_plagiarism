void
Sack1TcpAgent::partial_ack_action()
{
	if (next_pkt_ < highest_ack_ + 1) {
		next_pkt_ = highest_ack_ + 1;
	}
	// Output two packets in response to a partial ack,
	//   so as not to do worse than slow-start.
	int i;
	for (i = 1; i<=2; i++) {
		int getNext = scb_->GetNextUnacked(next_pkt_);
		if (getNext > next_pkt_) {
			next_pkt_ = getNext;
		}
		if (t_seqno_ < next_pkt_) {
			t_seqno_ = next_pkt_;
		}
		output(next_pkt_, TCP_REASON_PARTIALACK);	
		scb_->MarkRetran(next_pkt_);
		++next_pkt_; 
	}
	return;
}