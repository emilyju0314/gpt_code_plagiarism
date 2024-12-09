void HumdrumFileSet::clear(void) {
	for (int i=0; i<(int)m_data.size(); i++) {
		delete m_data[i];
		m_data[i] = NULL;
	}
	m_data.resize(0);
}