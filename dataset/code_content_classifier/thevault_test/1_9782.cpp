bool HumdrumFileBase::analyzeTracks(void) {
	for (int i=0; i<(int)m_lines.size(); i++) {
		int status = m_lines[i]->analyzeTracks(m_parseError);
		if (!status) {
			return false;
		}
	}
	return isValid();
}