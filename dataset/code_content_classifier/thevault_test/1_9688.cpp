void analyzeBarNumbers(HumdrumFile& infile) {
	m_barnum.clear();
	m_barnum.resize(infile.getLineCount());
	int current = -1;
	HumRegex hre;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isBarline()) {
			m_barnum.at(i) = current;
			continue;
		}
		if (hre.search(infile[i].token(0), "=(\\d+)")) {
			current = hre.getMatchInt(1);
		}
		m_barnum.at(i) = current;
	}
}