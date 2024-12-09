void HumdrumFileBase::deleteLine(int index) {
	if (index >= (int)m_lines.size()) {
		return;
	}
	if (index < 0) {
		return;
	}
	delete m_lines[index];
	for (int i=index+1; i<(int)m_lines.size(); i++) {
		m_lines[i-1] = m_lines[i];
	}
	m_lines.resize(m_lines.size() - 1);
}