void Tool_pccount::setFactorMaximum(void) {
	m_factor = 0.0;
	for (int i=0; i<(int)m_counts[0].size(); i++) {
		if (m_counts[0][i] > m_factor) {
			m_factor = m_counts[0][i];
		}
	}
}