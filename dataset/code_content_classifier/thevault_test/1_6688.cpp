int DCCPAckVector::getAckVector(u_char* vect, u_int16_t *size){
	if (size_ == 0)
		return DCCP_ACKV_EMPTY;
	else if (size_ > *size){
		*size = size_;
		return DCCP_ACKV_ERR_SIZE;
	}

	int walker = head_;

	for (int i = 0; i < size_; i++){
		vect[i] = vector_[walker];
		walker = (walker + 1) % max_size_;
	}
	*size = size_;
	
	return size_;
}