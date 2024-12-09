bool DCCPAckVector::alterState(u_int32_t seqnum, dccp_packet_state newstate, dccp_packet_state *oldstate){
	u_int16_t where;
	u_int32_t seq_start;
	u_int32_t seq_end;
	u_char items[3];
	int num_to_add = 0;
	dccp_packet_state old_state;
	u_int8_t old_runlen;
	bool result = false;
	
	if (findSeqNum(seqnum, &where, &seq_start, &seq_end)){
		old_state = (dccp_packet_state) (vector_[where] >> DCCP_RUN_LENGTH_BITS);

		if (oldstate != NULL)
			*oldstate = old_state;
		
		if (old_state != newstate){			
			old_runlen = vector_[where] & DCCP_RUN_LENGTH_MASK;
			if (old_runlen == 0){
				vector_[where] = ((u_int8_t) newstate) << DCCP_RUN_LENGTH_BITS;
				result = true;
			} else if (seqnum == seq_start || seqnum == seq_end){
				if (size_ + 1 > max_size_){
				        //increase size and try again
					result = (doubleMaxSize() && alterState(seqnum, newstate));
				} else {
					if(seqnum == seq_start){
						items[0] = ((u_int8_t) newstate) << DCCP_RUN_LENGTH_BITS;
						items[1] = (((u_int8_t) old_state) << DCCP_RUN_LENGTH_BITS)
							+ (old_runlen-1);
					} else {
						items[0] = (((u_int8_t) old_state) << DCCP_RUN_LENGTH_BITS)
							+ (old_runlen-1);
						items[1] = ((u_int8_t) newstate) << DCCP_RUN_LENGTH_BITS;
					}
					num_to_add = 2;
				}
			} else {
				if (size_ + 2 > max_size_){
				        //increase size and try again
					result = (doubleMaxSize() && alterState(seqnum, newstate));
				} else {
					items[0] = (((u_int8_t) old_state) << DCCP_RUN_LENGTH_BITS)
							+ (old_runlen-1-(seqnum-seq_end));
					items[1] = ((u_int8_t) newstate) << DCCP_RUN_LENGTH_BITS;
					items[2] = (((u_int8_t) old_state) << DCCP_RUN_LENGTH_BITS)
							+ (old_runlen-1-(seq_start-seqnum));
					num_to_add = 3;
				}
			}
		} else
			result = true;
	}
	
	if (num_to_add > 1){
		if(where == tail_){
			tail_ = (tail_ + (num_to_add - 1)) % max_size_;			
		} else if (where == head_){
			head_ = (head_ - (num_to_add - 1) + max_size_) % max_size_;
			where = head_;
		} else {
			int from = head_;
			int to = (head_ - (num_to_add - 1) + max_size_) % max_size_;
			head_ = to;
			while (from != where){
				vector_[to] = vector_[from];
				from = (from + 1) % max_size_;
				to = (to + 1) % max_size_;
			}
			where = (where - (num_to_add - 1) + max_size_) % max_size_;
		}
		for(int i = 0; i < num_to_add; i++){
			vector_[where] = items[i];
			where = (where + 1 ) % max_size_;
		}
		size_ += num_to_add - 1;
		result = true;
	}
	
	return result;
	
}