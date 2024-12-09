bool DCCPAckVector::nextPacket(u_int32_t *seqnum, dccp_packet_state *state){
	if (!p_walking_ || p_reverse_)
		return false;

	u_int8_t runlen = vector_[p_walk_] & DCCP_RUN_LENGTH_MASK;

	if (delta_p_walk_ > runlen){
		p_walk_ = (p_walk_+1) % max_size_;
		delta_p_walk_ = 0;
	}
		
	*seqnum = seq_p_walk_;
	*state = (dccp_packet_state) (vector_[p_walk_] >> DCCP_RUN_LENGTH_BITS);

	delta_p_walk_++;

	p_walking_ = (seq_p_walk_ != seq_tail_);

	seq_p_walk_--;

	return true;
}