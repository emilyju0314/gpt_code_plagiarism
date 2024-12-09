int DCCPSendBuffer::remove(){
	int result = 0;
	if (!empty_){
		result = buf_[head_];
		//remove element
		if (head_ != tail_)
			head_ = (head_+1) % size_;
		else
			empty_ = true;
	}
	return result;
}