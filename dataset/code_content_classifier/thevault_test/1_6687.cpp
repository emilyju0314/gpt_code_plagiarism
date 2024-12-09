bool DCCPAckVector::nextInterval(u_char *interval, u_int32_t *seq_start, u_int32_t *seq_end, dccp_packet_state *state){
	if (!i_walking_)
		return false;

	*interval = vector_[i_walk_];
	*seq_start = seq_i_walk_;
	*seq_end = seq_i_walk_ - (vector_[i_walk_] & DCCP_RUN_LENGTH_MASK);
	*state = (dccp_packet_state) (vector_[i_walk_] >> DCCP_RUN_LENGTH_BITS);
	
	i_walking_ = (i_walk_ != tail_);
	i_walk_ = (i_walk_ +1) % max_size_;
	seq_i_walk_ = *seq_end - 1;
	
	return true;
}