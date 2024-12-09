bool HumdrumFileContent::analyzePhrasings(void) {
	if (m_analyses.m_phrases_analyzed) {
		return false;
	}
	m_analyses.m_phrases_analyzed = true;
	bool output = true;
	output &= analyzeKernPhrasings();
	return output;
}