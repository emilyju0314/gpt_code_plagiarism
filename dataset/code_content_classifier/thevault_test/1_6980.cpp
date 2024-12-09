MediaSegment MediaSegmentList::get_nextseg(const MediaSegment& s) 
{
	MediaSegment res(0, 0); // If unsuccessful, return start() = 0

	MediaSegment* tmp = (MediaSegment *)head_;
	while ((tmp != NULL) && (tmp->before(s))) 
		tmp = tmp->next();
	if (tmp == NULL) {
		res.set_last();
		return res;
	}
	assert(tmp->end() > s.start());
// 	// Don't return a segment which do not *OVERLAP* with s 
// 	// (boundary overlap is excluded).
// 	if ((tmp->end() <= s.start()) || (tmp->start() >= s.end())) 
// 	    return res;

	// XXX How to flag that no more data is available in the future??
	res = s;
	int orig_size = s.datasize();
	if (res.start() < tmp->start()) {
		// |-------| (s)    ---> time axis
		//    |--------| (tmp)
		//
		// The start time of s is invalid, we need to adjust both 
		// the start time (and size if necessary)
		res.set_start(tmp->start());
		if (tmp->datasize() < orig_size) 
			// Not enough data available??
			res.set_datasize(tmp->datasize());
		else
			res.set_datasize(orig_size);
	} else if (res.end() > tmp->end()) {
		//    |---------| (s)    ---> time axis
		// |-------| (tmp)
		// 
		// The start time in s is valid, but we may need to adjust the 
		// end time (i.e., size) of s.
		res.set_datasize(tmp->end()-res.start());
	}
	// Falling through means that the requested segment is available 
	// and can be returned as it is.

	assert(res.datasize() <= tmp->datasize());
	if ((res.end() == tmp->end()) && (tmp->next() == NULL))
		// This is the last data segment of the layer
		res.set_last();
	return res;
}