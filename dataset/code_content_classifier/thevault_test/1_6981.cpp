int MediaSegmentList::evict_tail(int size)
{
	int sz = size, tz;
	MediaSegment *tmp = (MediaSegment *)tail_;
	while ((tmp != NULL) && (sz > 0)) {
		// Reduce the last segment's size and adjust its playout time
		tz = tmp->evict_tail(sz);
		length_ -= tz;
		sz -= tz; 
		if (tmp->datasize() == 0) {
			// This segment is empty now
			detach(tmp);
			delete tmp;
			tmp = (MediaSegment *)tail_;
		}
	}
	return size - sz;
}