bool DCCPAckVector::addItems(dccp_packet_state state, u_int8_t runlen, int count){
	u_int8_t temp = state;	
	int new_head, walker;
	u_int8_t item = (temp << DCCP_RUN_LENGTH_BITS | (runlen & DCCP_RUN_LENGTH_MASK));
	if (size_+count > max_size_){
		//increase size and try again
		return (doubleMaxSize() && addItems(state,runlen,count));
	}

	if(size_ != 0)
		seq_head_ +=(runlen+1)*count;
	
	new_head = (head_ - count + max_size_) % max_size_;
	walker = new_head;
	
	while(walker != head_){
		vector_[walker] = item;
		walker = (walker + 1) % max_size_;
	}
	
	size_ += count;
	head_ = new_head;

	return true;
}