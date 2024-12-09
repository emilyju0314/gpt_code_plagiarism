int Acker::update(int seq, int numBytes)
{
	bool just_marked_as_seen = FALSE;
	is_dup_ = FALSE;
	// start by assuming the segment hasn't been received before
	if (numBytes <= 0)
		printf("Error, received TCP packet size <= 0\n");
	int numToDeliver = 0;
	while(seq + 1 - next_ >= wndmask_) {
		// next_ is next packet expected; wndmask_ is the maximum
		// window size minus 1; if somehow the seqno of the
		// packet is greater than the one we're expecting+wndmask_,
		// then resize the buffer.
		resize_buffers((wndmask_+1)*2);
	}

	if (seq > maxseen_) {
		// the packet is the highest one we've seen so far
		int i;
		for (i = maxseen_ + 1; i < seq; ++i)
			seen_[i & wndmask_] = 0;
		// we record the packets between the old maximum and
		// the new max as being "unseen" i.e. 0 bytes of each
		// packet have been received
		maxseen_ = seq;
		seen_[maxseen_ & wndmask_] = numBytes;
		// store how many bytes have been seen for this packet
		seen_[(maxseen_ + 1) & wndmask_] = 0;
		// clear the array entry for the packet immediately
		// after this one
		just_marked_as_seen = TRUE;
		// necessary so this packet isn't confused as being a duplicate
	}
	int next = next_;
	if (seq < next) {
		// Duplicate packet case 1: the packet is to the left edge of
		// the receive window; therefore we must have seen it
		// before
#ifdef DEBUGDSACK
		printf("%f\t Received duplicate packet %d\n",Scheduler::instance().clock(),seq);
#endif
		is_dup_ = TRUE;
	}

	if (seq >= next && seq <= maxseen_) {
		// next is the left edge of the recv window; maxseen_
		// is the right edge; execute this block if there are
		// missing packets in the recv window AND if current
		// packet falls within those gaps

		if (seen_[seq & wndmask_] && !just_marked_as_seen) {
		// Duplicate case 2: the segment has already been
		// recorded as being received (AND not because we just
		// marked it as such)
			is_dup_ = TRUE;
#ifdef DEBUGDSACK
			printf("%f\t Received duplicate packet %d\n",Scheduler::instance().clock(),seq);
#endif
		}
		seen_[seq & wndmask_] = numBytes;
		// record the packet as being seen
		while (seen_[next & wndmask_]) {
			// this loop first gets executed if seq==next;
			// i.e., this is the next packet in order that
			// we've been waiting for.  the loop sets how
			// many bytes we can now deliver to the
			// application, due to this packet arriving
			// (and the prior arrival of any segments
			// immediately to the right)

			numToDeliver += seen_[next & wndmask_];
			++next;
		}
		next_ = next;
		// store the new left edge of the window
	}
	return numToDeliver;
}