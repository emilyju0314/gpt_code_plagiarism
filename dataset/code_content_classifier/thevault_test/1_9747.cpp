void Tool_extract::excludeFields(HumdrumFile& infile, vector<int>& field,
		vector<int>& subfield, vector<int>& model) {
	int start = 0;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].hasSpines()) {
			m_humdrum_text << infile[i] << '\n';
			continue;
		} else {
			start = 0;
			for (int j=0; j<infile[i].getFieldCount(); j++) {
				if (isInList(infile[i].token(j)->getTrack(), field)) {
					continue;
				}
				if (start != 0) {
					m_humdrum_text << '\t';
				}
				start = 1;
				m_humdrum_text << infile.token(i, j);
			}
			if (start != 0) {
				m_humdrum_text << endl;
			}
		}
	}
}