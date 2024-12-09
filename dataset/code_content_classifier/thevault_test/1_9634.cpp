void Tool_shed::initializeSegment(HumdrumFile& infile) {
	m_spines.clear();
	if (getBoolean("spines")) {
		int maxtrack = infile.getMaxTrack();
		Convert::makeBooleanTrackList(m_spines, getString("spines"), maxtrack);
	}
}