void Tool_satb2gs::printTerminatorLine(vector<vector<int>>& tracks) {
	int count = getNewTrackCount(tracks);
	for (int i=0; i<count; i++) {
		m_humdrum_text << "*-";
		if (i < count - 1) {
			m_humdrum_text << "\t";
		}
	}
	m_humdrum_text << endl;
}