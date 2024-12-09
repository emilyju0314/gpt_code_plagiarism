int Tool_semitones::filterData(HTp token) {
	vector<HTp> toks = getTieGroup(token);
	HumRegex hre;
	if (!m_exclude.empty()) {
		for (int i=0; i<(int)toks.size(); i++) {
			if (hre.search(toks[i], m_exclude)) {
				return -1;
			}
		}
		return 1;
	} else if (!m_include.empty()) {
		for (int i=0; i<(int)toks.size(); i++) {
			if (hre.search(toks[i], m_include)) {
				return 1;
			}
		}
		return 0;
	}
	return 0;
}