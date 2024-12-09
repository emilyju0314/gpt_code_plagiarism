void Tool_msearch::doMusicSearch(HumdrumFile& infile, NoteGrid& grid,
		vector<MSearchQueryToken>& query) {

	if (m_debugQ) {
		printQuery(query);
	}

	vector<vector<NoteCell*>> attacks;
	attacks.resize(grid.getVoiceCount());
	for (int i=0; i<grid.getVoiceCount(); i++) {
		grid.getNoteAndRestAttacks(attacks[i], i);
	}

	vector<NoteCell*>  match;
	int mcount = 0;
	for (int i=0; i<(int)attacks.size(); i++) {
		for (int j=0; j<(int)attacks[i].size(); j++) {
			m_tomark.clear();
			bool status = checkForMusicMatch(attacks[i], j, query, match);
			if (!status) {
				m_tomark.clear();
			}
			if (status && !match.empty()) {
				mcount++;
				markMatch(infile, match);
				// cerr << "FOUND MATCH AT " << i << ", " << j << endl;
				// markNotes(attacks[i], j, (int)query.size());
			}
		}
	}

	if (mcount && m_markQ) {
		string content = "!!!RDF**kern: " + m_marker + " = marked note";
		if (getBoolean("color")) {
			content += ", color=\"" + getString("color") + "\"";
		}
		infile.appendLine(content);
		infile.createLinesFromTokens();
	}
	if (!m_quietQ) {
		addMusicSearchSummary(infile, mcount, m_marker);
	}
}