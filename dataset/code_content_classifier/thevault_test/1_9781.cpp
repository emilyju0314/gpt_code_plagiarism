bool HumdrumFileBase::analyzeLines(void) {
	for (int i=0; i<(int)m_lines.size(); i++) {
		m_lines[i]->setLineIndex(i);
	}
	return isValid();
}