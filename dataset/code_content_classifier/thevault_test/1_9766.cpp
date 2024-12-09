HLp HumdrumFileBase::getLine(int index) {
	if (index < 0) {
		return NULL;
	} else if (index >= (int)m_lines.size()) {
		return NULL;
	} else {
		return m_lines[index];
	}
}