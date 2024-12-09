bool DCCPAckVector::doubleMaxSize(){
	if (max_size_ == DCCP_MAX_ACKV_SIZE)
		return false;
    
	int new_max_size = max_size_ * 2;

	if (new_max_size > DCCP_MAX_ACKV_SIZE)
		new_max_size = DCCP_MAX_ACKV_SIZE;

	u_char *new_vector = new u_char[new_max_size];
	int walker = head_;

	for (int i = 0; i < size_; i++){
		new_vector[i] = vector_[walker];
		walker = (walker + 1) % max_size_;
	}
	max_size_ = new_max_size;

	if (size_ > 0) {
		head_ = 0;
		tail_ = size_-1;
	}
	
	delete [] vector_;
	vector_ = new_vector;
	return true;
}