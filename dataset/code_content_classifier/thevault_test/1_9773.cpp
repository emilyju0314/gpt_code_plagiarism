void HumdrumFileBase::getSpineStopList(vector<HTp>& spinestops) {
	spinestops.reserve(m_trackends.size());
	spinestops.resize(0);
	for (int i=0; i<(int)m_trackends.size(); i++) {
		for (int j=0; j<(int)m_trackends[i].size(); j++) {
			spinestops.push_back(m_trackends[i][j]);
		}
	}
}