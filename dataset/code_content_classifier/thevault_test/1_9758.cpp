void Tool_tassoize::updateKeySignatures(HumdrumFile& infile, int lineindex) {
	HumdrumLine& line = infile[lineindex];
	int track;
	for (int i=0; i<line.getFieldCount(); i++) {
		if (!line.token(i)->isKeySignature()) {
			continue;
		}
		HTp token = line.token(i);
		track = token->getTrack();
		string text = token->getText();
		fill(m_kstates[track].begin(), m_kstates[track].end(), 0);
		for (int j=3; j<(int)text.size()-1; j++) {
			if (text[j] == ']') {
				break;
			}
			switch (text[j]) {
				case 'a': case 'A':
					switch (text[j+1]) {
						case '#': m_kstates[track][5] = +1;
						break;
						case '-': m_kstates[track][5] = -1;
						break;
					}
					break;

				case 'b': case 'B':
					switch (text[j+1]) {
						case '#': m_kstates[track][6] = +1;
						break;
						case '-': m_kstates[track][6] = -1;
						break;
					}
					break;

				case 'c': case 'C':
					switch (text[j+1]) {
						case '#': m_kstates[track][0] = +1;
						break;
						case '-': m_kstates[track][0] = -1;
						break;
					}
					break;

				case 'd': case 'D':
					switch (text[j+1]) {
						case '#': m_kstates[track][1] = +1;
						break;
						case '-': m_kstates[track][1] = -1;
						break;
					}
					break;

				case 'e': case 'E':
					switch (text[j+1]) {
						case '#': m_kstates[track][2] = +1;
						break;
						case '-': m_kstates[track][2] = -1;
						break;
					}
					break;

				case 'f': case 'F':
					switch (text[j+1]) {
						case '#': m_kstates[track][3] = +1;
						break;
						case '-': m_kstates[track][3] = -1;
						break;
					}
					break;

				case 'g': case 'G':
					switch (text[j+1]) {
						case '#': m_kstates[track][4] = +1;
						break;
						case '-': m_kstates[track][4] = -1;
						break;
					}
					break;
			}
			for (int j=0; j<7; j++) {
				if (m_kstates[track][j] == 0) {
					continue;
				}
				for (int k=1; k<10; k++) {
					m_kstates[track][j+k*7] = m_kstates[track][j];
				}
			}
		}
	}

	// initialize m_pstates with contents of m_kstates
	for (int i=0; i<(int)m_kstates.size(); i++) {
		for (int j=0; j<(int)m_kstates[i].size(); j++) {
			m_pstates[i][j] = m_kstates[i][j];
		}
	}

}