int MediaSegmentList::evict_head(int size)
{
	int sz = size, tz;
	MediaSegment *tmp = (MediaSegment *)head_;
	while ((tmp != NULL) && (sz > 0)) {
		// Reduce the last segment's size and adjust its playout time
		tz = tmp->evict_head(sz);
		sz -= tz; 
		length_ -= tz;
		if (tmp->datasize() == 0) {
			// This segment is empty now
			detach(tmp);
			delete tmp;
			tmp = (MediaSegment *)head_;
		}
	}
	return size - sz;
}