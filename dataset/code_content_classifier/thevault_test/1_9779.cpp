int HumdrumFileBase::getTrackEndCount(int track) const {
	if (track < 0) {
		track += (int)m_trackends.size();
	}
	if (track < 0) {
		return 0;
	}
	if (track >= (int)m_trackends.size()) {
		return 0;
	}
	return (int)m_trackends[track].size();
}