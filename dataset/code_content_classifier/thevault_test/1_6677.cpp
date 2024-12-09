bool DCCPAckVector::addPacket(u_int32_t seqnum, dccp_packet_state state){
	int dist = seqnum - seq_head_;
	u_int8_t runlen = 0;
	
	if (size_ == 0){
		seq_head_ = seqnum;
		seq_tail_ = seqnum;
		head_ = 0;
		tail_ = max_size_-1;
	} else if (dist > 1){  //some packets are missing
		int num_fulls = (dist-2) / (DCCP_RUN_LENGTH_MASK+1);
		int last_runlen = (dist-2) % (DCCP_RUN_LENGTH_MASK+1);
	
		if (size_ + num_fulls + 1 + 1 > max_size_)
			return doubleMaxSize() && addPacket(seqnum, state);

		if (num_fulls > 0)
			addItems(DCCP_PACKET_NOT_RECV, DCCP_RUN_LENGTH_MASK, num_fulls);

		addItems(DCCP_PACKET_NOT_RECV,last_runlen);

	} else if (dist == 1) { //expected packet
		u_int8_t last_runlen = vector_[head_] & DCCP_RUN_LENGTH_MASK;
		u_int8_t last_state = vector_[head_] >> DCCP_RUN_LENGTH_BITS;
		if (last_runlen < DCCP_RUN_LENGTH_MASK && last_state == (u_int8_t) state){
			vector_[head_] += 1;
			seq_head_ = seqnum;
			return true;
		}

	} else {
		dccp_packet_state curr_state;
		if (getState(seqnum, &curr_state))
			if (alterState(seqnum,ackv_cons_[curr_state][state])){
				return true;
			}
		
		return false;
	}

	if (!addItems(state, runlen)){
		return false;
	}

	return true;
}