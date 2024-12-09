void DCCPSendBuffer::print(){
	int walker_ = head_;
	if (empty_)
		fprintf(stdout, "DCCPSendBuffer :: Buffer is empty (size %d, head %d, tail %d)\n", size_, head_, tail_);
	else {
		fprintf(stdout, "DCCPSendBuffer :: Buffer (size %d, head %d, tail %d): ", size_, head_, tail_);
		while(walker_ != tail_){
			fprintf(stdout, "%d ",buf_[walker_]);
			walker_ = (walker_ + 1) % size_;
		}
		fprintf(stdout, "%d\n",buf_[walker_]);
	}
	fflush(stdout);
}