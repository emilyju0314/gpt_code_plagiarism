void DCCPAckVector::startPacketWalk(){
	p_walk_ = head_;
	seq_p_walk_ = seq_head_;
	delta_p_walk_ = 0;
	p_walking_ = (size_ != 0);
	p_reverse_ = false;
}