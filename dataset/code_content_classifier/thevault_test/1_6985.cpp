int MediaSegmentList::overlap_size(const MediaSegment& s) const
{
	int res = 0;
	MediaSegment* tmp = (MediaSegment *)head_;
	while ((tmp != NULL) && (tmp->before(s)))
		tmp = tmp->next();
	// If all segments are before s, there's no overlap
	if (tmp == NULL)
		return 0;
	// If s is within *tmp, entire s overlaps with the list
	if (s.in(*tmp))
		return s.datasize();
	// Otherwise adds all overlapping parts together.
	int soff, eoff;
	soff = s.start();
	eoff = s.end();
	while ((tmp != NULL) && (tmp->overlap(s))) {
		res += min(eoff, tmp->end()) - max(soff, tmp->start());
		soff = tmp->end();
		tmp = tmp->next();
	}
	return res;
}