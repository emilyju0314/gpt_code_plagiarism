void HumdrumFileBase::getTrackSequence(vector<vector<HTp> >& sequence,
		HTp starttoken, int options) {
	int track = starttoken->getTrack();
	getTrackSequence(sequence, track, options);
}