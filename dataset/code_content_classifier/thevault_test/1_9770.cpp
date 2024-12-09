void HumdrumFileBase::insertLine(int index, const string& line) {
	HLp s = new HumdrumLine(line);
	m_lines.insert(m_lines.begin() + index, s);

	// Update the line indexes for this line and the following ones:
	for (int i=index; i<(int)m_lines.size(); i++) {
		m_lines[i]->setLineIndex(i);
	}
}