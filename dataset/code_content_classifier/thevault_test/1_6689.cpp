bool DCCPAckVector::setAckVector(const u_char* vect, u_int16_t size, u_int32_t seq_start, u_int8_t ene){
	if (size > max_size_) {
		size_ = 0;
		return (doubleMaxSize() && setAckVector(vect, size, seq_start, ene));
	}

	u_int32_t seq_end = seq_start;
	
	for (int i = 0; i < size; i++){
		vector_[i] = vect[i];
		if (i == size-1)
			seq_end -= vect[i] & DCCP_RUN_LENGTH_MASK;
		else
			seq_end -= (vect[i] & DCCP_RUN_LENGTH_MASK) + 1;
	}

	size_ = size;
	head_ = 0;
	tail_ = size_-1;
	seq_head_ = seq_start;
	seq_tail_ = seq_end;
	ene_ = ene;

	clearAckHistory();
	return true;
}