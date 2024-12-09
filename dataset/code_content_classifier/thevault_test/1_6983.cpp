int MediaSegmentList::evict_head_offset(int offset)
{
	int sz = 0;
	MediaSegment *tmp = (MediaSegment *)head_;
	while ((tmp != NULL) && (tmp->start() < offset)) {
		if (tmp->end() <= offset) {
			// delete whole segment
			sz += tmp->datasize();
			length_ -= tmp->datasize();
			detach(tmp);
			delete tmp;
			tmp = (MediaSegment *)head_;
		} else {
			// remove part of the segment
			sz += offset - tmp->start();
			length_ -= offset - tmp->start();
			tmp->set_start(offset);
		}
	}
	if (head_ == NULL)
		tail_ = NULL;
	return sz;
}