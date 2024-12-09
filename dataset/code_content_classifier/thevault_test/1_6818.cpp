bool DCCPSendBuffer::add(int packet_size){
	if (empty_) {
		buf_[head_] = packet_size;
		empty_ = false;
	} else if ( (tail_+1) % size_ == head_)  //buffer is full
		return false;
	else {
		tail_ = (tail_ + 1) % size_;
		buf_[tail_] = packet_size;
	}
	return true;
}