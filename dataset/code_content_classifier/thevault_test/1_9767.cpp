bool HumdrumFileBase::analyzeTokens(void) {
	for (int i=0; i<(int)m_lines.size(); i++) {
		m_lines[i]->createTokensFromLine();
	}
	return isValid();
}