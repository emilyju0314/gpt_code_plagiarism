vector<int> HumdrumFileBase::getMeasureNumbers(void) {
	HumdrumFileBase& infile = *this;
	vector<int> output(infile.getLineCount(), -1);
	int lastmeasure = -1;
	int current;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isBarline()) {
			current = infile.getMeasureNumber(i);
			if (current >= 0) {
				lastmeasure = current;
			}
		}
		output[i] = lastmeasure;
	}
	return output;
}