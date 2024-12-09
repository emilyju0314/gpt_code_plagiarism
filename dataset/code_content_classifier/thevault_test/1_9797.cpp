HLp HumdrumFileBase::getLineForInterpretationInsertion(int index) {
	HumdrumFileBase& infile = *this;
	int current = index - 1;
	int previous = index;
	while (current > 0) {
		if (!infile[current].hasSpines()) {
			current--;
			continue;
		}
		if (infile[current].isCommentLocal()) {
			previous = current;
			current--;
			continue;
		}
		return &infile[previous];
	}
	return &infile[index];
}