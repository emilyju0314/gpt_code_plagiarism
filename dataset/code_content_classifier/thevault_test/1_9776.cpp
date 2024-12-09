void HumdrumFileBase::getPrimaryTrackSequence(vector<HTp>& sequence, int track,
		int options) {
	vector<vector<HTp> > tempseq;
	getTrackSequence(tempseq, track, options | OPT_PRIMARY);
	sequence.resize(tempseq.size());
	for (int i=0; i<(int)tempseq.size(); i++) {
		sequence[i] = tempseq[i][0];
	}
}