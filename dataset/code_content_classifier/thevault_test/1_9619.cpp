int Tool_colortriads::getDiatonicTransposition(HumdrumFile& infile) {
	int key;
	char ch;
	int output = 0;
	if (!m_key.empty()) {
		ch = m_key[0];
		if (isupper(ch)) {
			key = m_key.at(0) - 'A';
		} else {
			key = m_key.at(0) - 'a';
		}
		output = 2 - key; // C index is at 2
		if (abs(output) >= 7) {
			output = 0;
		}
		return output;
	}

	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isData()) {
			break;
		}
		if (!infile[i].isInterpretation()) {
			continue;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (!token->isKern()) {
				continue;
			}
			if (!token->isKeyDesignation()) {
				continue;
			}
			if (token->size() < 2) {
				continue;
			}
			char ch = token->at(1);
			if (isupper(ch)) {
				key = token->at(1) - 'A';
			} else {
				key = token->at(1) - 'a';
			}
			output = 2 - key; // C index is at 2
			if (abs(output) >= 7) {
				output = 0;
			}
			break;
		}
	}
	return output;
}