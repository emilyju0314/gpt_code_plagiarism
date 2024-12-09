void HumdrumFileBase::getSpineStartList(vector<HTp>& spinestarts) {
	spinestarts.reserve(m_trackstarts.size());
	spinestarts.resize(0);
	for (int i=1; i<(int)m_trackstarts.size(); i++) {
		spinestarts.push_back(m_trackstarts[i]);
	}
}