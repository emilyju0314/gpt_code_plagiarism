void HumdrumFileSet::clearNoFree(void) {
	for (int i=0; i<(int)m_data.size(); i++) {
		m_data[i] = NULL;
	}
	m_data.resize(0);
}