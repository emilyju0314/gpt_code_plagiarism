bool HumdrumFileBase::analyzeLinks(void) {
	HumdrumFileBase& infile = *this;
	infile.clearTokenLinkInfo();

	HLp next     = NULL;
	HLp previous = NULL;

	for (int i=0; i<(int)m_lines.size(); i++) {
		if (!m_lines[i]->hasSpines()) {
			continue;
		}
		previous = next;
		next = m_lines[i];
		if (previous != NULL) {
			if (!stitchLinesTogether(*previous, *next)) {
				return isValid();
			}
		}
	}
	return isValid();;
}