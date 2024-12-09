bool DCCPAckVector::getState(u_int32_t seqnum, dccp_packet_state *state){
	if (size_ == 0 || seqnum > seq_head_ || seqnum < seq_tail_)
		return false;
	bool result = false;
	u_int16_t where;
	u_int32_t seq_start;
	u_int32_t seq_end;

	if(findSeqNum(seqnum, &where, &seq_start, &seq_end)){
		*state = (dccp_packet_state) (vector_[where] >> DCCP_RUN_LENGTH_BITS);
		result = true;
	}

	return result;
}