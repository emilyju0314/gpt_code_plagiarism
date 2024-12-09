void HumdrumFileBase::createLinesFromTokens(void) {
	for (int i=0; i<(int)m_lines.size(); i++) {
		m_lines[i]->createLineFromTokens();
	}
}