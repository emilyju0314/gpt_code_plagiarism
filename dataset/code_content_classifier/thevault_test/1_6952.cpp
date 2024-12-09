Packet* DelayBoxQueue::dequeue(double* resched_time)
{
	double head_delta;

	if (head_ == NULL)
		return NULL;

	pktinfo *ptr = head_;
	Packet* p = ptr->pkt_;

	// save delta value
	head_delta = ptr->delta_;

	// advance the head pointer
	head_ = ptr->next_;        
	ptr->next_ = NULL;
	delete ptr;

	if (head_ == NULL) {
		*resched_time = 0;
		deltasum_ = 0;
		tail_ = NULL;
	}
	else {
		// new head of the queue's delta should be its time to send
		// which is head_->delta + new_head_->delta
		*resched_time = head_->delta_;
		head_->delta_ += head_delta;   // fix the head's delta
	}
	return (p);
}