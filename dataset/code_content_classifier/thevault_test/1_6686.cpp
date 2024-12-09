void DCCPAckVector::startIntervalWalk(){
	i_walk_ = head_;
	seq_i_walk_ = seq_head_;
	i_walking_ = size_ != 0;
}