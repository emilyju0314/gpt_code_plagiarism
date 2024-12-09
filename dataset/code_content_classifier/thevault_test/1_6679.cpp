void DCCPAckVector::removePackets(u_int32_t seqnum){
	if (size_ == 0 || seqnum < seq_tail_)
		return;
	else if (seqnum > seq_head_) { 
		size_ = 0;
		seq_tail_ = seq_head_;
		tail_ = head_;
		ene_ = 0;
		return;
	}

	u_int16_t where;
	u_int32_t seq_start;
	u_int32_t seq_end;

	u_int32_t dist = 0;

	if (findSeqNum(seqnum, &where, &seq_start, &seq_end)){
		dist = seq_start-seq_end;
		if (dist > 0 && seq_start != seqnum){
			vector_[where] = vector_[where] - (seqnum-seq_end+1);
			size_ = ((where - head_ + max_size_) % max_size_)+1;
			tail_ = where;
			seq_tail_ = seqnum + 1;
		} else if (where == head_){
			size_ = 0;
			seq_tail_ = seq_head_;
			tail_ = head_;
			ene_ = 0;
		} else {
			where = ((where -1 + max_size_) % max_size_);
			size_ = ((where - head_ + max_size_) % max_size_)+1;
			tail_ = where;
			seq_tail_ = seqnum +1;
		}


	}
	
}