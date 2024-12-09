HTp HumdrumFileBase::getTrackEnd(int track, int subtrack) const {
	if (track < 0) {
		track += (int)m_trackends.size();
	}
	if (track < 0) {
		return NULL;
	}
	if (track >= (int)m_trackends.size()) {
		return NULL;
	}
	if (subtrack < 0) {
		subtrack += (int)m_trackends[track].size();
	}
	if (subtrack < 0) {
		return NULL;
	}
	if (subtrack >= (int)m_trackends[track].size()) {
		return NULL;
	}
	return m_trackends[track][subtrack];
}