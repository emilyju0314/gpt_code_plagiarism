DCCPSendBuffer::DCCPSendBuffer(int size): head_(0), tail_(0),
	size_(size), empty_(true) {
	if (size_ <= 0)
		size_ = 1;
	
	buf_ = new int[size_];
}