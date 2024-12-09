bool DCCPAckVector::findSeqNum(u_int32_t seqnum, u_int16_t *where, u_int32_t *seq_start, u_int32_t *seq_end){
	if (size_ == 0 || seqnum > seq_head_ || seqnum < seq_tail_ )
		return false;
	
	*where = head_;
	*seq_start = seq_head_;
	*seq_end = 0;
	int stop = (tail_ + 1) % max_size_;
	
	do{
		*seq_end = *seq_start - (vector_[*where] & DCCP_RUN_LENGTH_MASK);
		
		if (*seq_end <= seqnum && *seq_start >= seqnum){
			return true;
		}
		
		*where = (*where + 1) % max_size_;
		*seq_start = *seq_end - 1;
	} while(*where != stop);
	
	//should never get here!!
	return false;
}