MediaSegmentList MediaSegmentList::check_holes(const MediaSegment& s)
{
	MediaSegmentList res;  // empty list
	MediaSegment* tmp = (MediaSegment *)head_;
	while ((tmp != NULL) && (tmp->before(s)))
		tmp = tmp->next();
	// If all segments are before s, s is a hole
	if (tmp == NULL) {
		res.add(s);
		return res;
	}
	// If s is within *tmp, there is no hole
	if (s.in(*tmp))
		return res;

	// Otherwise return a list of holes
	int soff, eoff;
	soff = s.start();
	eoff = s.end();
	while ((tmp != NULL) && (tmp->overlap(s))) {
		if (soff < tmp->start()) {
			// Only refetches the missing part
			res.add(MediaSegment(soff, min(eoff, tmp->start())));
#if 1
			// DEBUG ONLY
			// Check if these holes are really holes!
			if (in(MediaSegment(soff, min(eoff, tmp->start())))) {
				fprintf(stderr, "Wrong hole: (%d %d) ", 
					soff, min(eoff, tmp->start()));
				fprintf(stderr, "tmp(%d %d), s(%d %d)\n",
					tmp->start(), tmp->end(),
					soff, eoff);
				fprintf(stderr, "List content: ");
				print();
			}
#endif
		}
		soff = tmp->end();
		tmp = tmp->next();
	}
	if (soff < eoff) {
		res.add(MediaSegment(soff, eoff));
#if 1		
		// DEBUG ONLY
		// Check if these holes are really holes!
		if (in(MediaSegment(soff, eoff))) {
			fprintf(stderr, "Wrong hole #2: (%d %d)\n", 
				soff, eoff);
			fprintf(stderr, "List content: ");
			print();
		}
#endif
	}
#if 0
	check_integrity();
#endif
	return res;
}