void HumdrumFileBase::addToTrackStarts(HTp token) {
	if (token == NULL) {
		m_trackstarts.push_back(NULL);
		m_trackends.resize(m_trackends.size()+1);
	} else if ((m_trackstarts.size() > 1) && (m_trackstarts.back() == NULL)) {
		m_trackstarts.back() = token;
	} else {
		m_trackstarts.push_back(token);
		m_trackends.resize(m_trackends.size()+1);
	}
}