vector<int> HumdrumFileBase::getTrackWidths(void) {
	HumdrumFileBase& infile = *this;
	vector<int> output(infile.getTrackCount() + 1, 1);
	output[0] = 0;
	vector<int> local(infile.getTrackCount() + 1);
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].hasSpines()) {
			continue;
		}
		fill(local.begin(), local.end(), 0);
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			int track = token->getTrack();
			local[track]++;
		}
		for (int j=1; j<(int)local.size(); j++) {
			if (local[j] > output[j]) {
				output[j] = local[j];
			}
		}
	}
	return output;
}