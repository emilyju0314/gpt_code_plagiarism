HLp HumdrumFileBase::getLineForInterpretationInsertionAbove(int index) {
	HumdrumFileBase& infile = *this;
	HumNum timestamp = infile[index].getDurationFromStart();
	HumNum teststamp;
	int current = index - 1;
	int previous = index;
	while (current > 0) {
		if (!infile[current].hasSpines()) {
			current--;
			continue;
		}
		teststamp = infile[current].getDurationFromStart();
		if (teststamp == timestamp) {
			previous = current;
			current--;
			continue;
		}
		return &infile[previous];
	}
	return &infile[index];
}