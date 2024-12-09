int DCCPSendBuffer::top(){
	int result = 0;
	if (!empty_)
		result = buf_[head_];
	return result;
}