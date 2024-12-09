void Tool_satb2gs::printRegularLine(HumdrumFile& infile, int line,
		vector<vector<int>>& tracks) {

	int spinecount = infile[line].getFieldCount();
	int track;
	HTp token;
	vector<vector<vector<HTp>>> tokens;
	tokens.resize(5);
	for (int i=0; i<(int)tracks.size(); i++) {
		tokens[i].resize(tracks[i].size());
	}

	// store tokens in output order:
	for (int i=0; i<(int)tracks.size(); i++) {
		for (int j=0; j<(int)tracks[i].size(); j++) {
			int target = tracks[i][j];
			for (int k=0; k<spinecount; k++) {
				token = infile.token(line, k);
				track = token->getTrack();
				if (track != target) {
					continue;
				}
				tokens[i][j].push_back(token);
			}
		}
	}

	int counter = 0;
	HTp top;
	HTp bot;
	HTp inner;
	HTp outer;
	bool suppressQ;

	// now print in output order, but hide fermatas
	// in the alto and tenor parts if there are fermatas
	// int the soprano and bass parts respectively.
	for (int i=0; i<(int)tokens.size(); i++) {
		for (int j=0; j<(int)tokens[i].size(); j++) {
			switch (i) {
				case 0:
				case 2:
				case 4:
					// non-kern spines
					for (int k=0; k<(int)tokens[i][j].size(); k++) {
						m_humdrum_text << tokens[i][j][k];
						counter++;
						if (counter < spinecount) {
							m_humdrum_text << "\t";
						}
					}
					break;

				case 1:
				case 3:
					top = tokens[i][0][0];
					bot = tokens[i][1][0];
					if (i == 1) {
						// tenor: top is inner
						inner = top;
						outer = bot;
					} else {
						// alto: bottom is inner
						inner = bot;
						outer = top;
					}
					if (inner->hasFermata() && outer->hasFermata()) {
						suppressQ = true;
					} else {
						suppressQ = false;
					}

					for (int k=0; k<(int)tokens[i][j].size(); k++) {
						token = tokens[i][j][k];
						if (suppressQ && ((void*)token == (void*)inner)) {
							string value = *token;
							// Make fermata invisible by adding 'y' after it:
							for (int m=0; m<(int)value.size(); m++) {
								m_humdrum_text << value[m];
								if (value[m] == ';') {
									if (m < (int)value.size() - 1) {
										if (value.at(m+1) != 'y') {
											m_humdrum_text << 'y';
										}
									} else {
											m_humdrum_text << 'y';
									}
								}
							}
						} else {
							m_humdrum_text << token;
						}
						counter++;
						if (counter < spinecount) {
							m_humdrum_text << "\t";
						}
					}
					break;
			}
		}
	}

	m_humdrum_text << endl;
}