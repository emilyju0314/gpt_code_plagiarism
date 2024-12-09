void DCCPAckVector::startReversePacketWalk(){
	p_walk_ = tail_;
	seq_p_walk_ = seq_tail_;
	delta_p_walk_ = 0;
	p_walking_ = (size_ != 0);
	p_reverse_ = true;
}