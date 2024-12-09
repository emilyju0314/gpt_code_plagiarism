void RapAgent::UpdateLastHole(int seqNum)
{
	assert(seqNum > 0);

	if (seqNum > (lastRecv_ + 1)) {
		prevRecv_ = lastRecv_;
		lastRecv_ = seqNum;
		lastMiss_ = seqNum - 1;
		return;
	}

	if (seqNum == (lastRecv_ + 1)) {
		lastRecv_ = seqNum;
		return;
	}
	
	if ((lastMiss_ < seqNum) && (seqNum <= lastRecv_)) // Duplicate
		return;

	if (seqNum == lastMiss_) {
		if ((prevRecv_ + 1) == seqNum) // Hole filled
			prevRecv_ = lastMiss_ = 0;
		else
			lastMiss_--;
		
		return;
	}
	
	if ((prevRecv_ < seqNum) && (seqNum < lastMiss_)) {
		prevRecv_ = seqNum;
		return;
	}

	assert(seqNum <= prevRecv_);	// Pretty late...
}