void Tool_msearch::doTextSearch(HumdrumFile& infile, NoteGrid& grid,
		vector<MSearchTextQuery>& query) {

	vector<TextInfo*> words;
	words.reserve(10000);
	fillWords(infile, words);
	int tcount = 0;

	HumRegex hre;
	for (int i=0; i<(int)query.size(); i++) {
		for (int j=0; j<(int)words.size(); j++) {
			if (hre.search(words.at(j)->fullword, query.at(i).word, "i")) {
				tcount++;
				markTextMatch(infile, *words[j]);
			}
		}
	}

	string textinterp = "**text";
	vector<HTp> interps;
	infile.getSpineStartList(interps);
	//int textcount = 0;
	int silbecount = 0;
	for (int i=0; i<(int)interps.size(); i++) {
		//if (interps[i]->getText() == "**text") {
		//	textcount++;
		//}
		if (interps[i]->getText() == "**silbe") {
			silbecount++;
		}
	}
	if (silbecount > 0) {
		// giving priority to **silbe content
		textinterp = "**silbe";
	}

	if (tcount && m_markQ) {
		string content = "!!!RDF";
		content += textinterp;
		content += ": ";
		content += m_marker;
		content += " = marked text";
		if (getBoolean("color")) {
			content += ", color=\"" + getString("color") + "\"";
		}
		infile.appendLine(content);
		infile.createLinesFromTokens();
	}

	for (int i=0; i<(int)words.size(); i++) {
		delete words[i];
		words[i] = NULL;
	}

	if (!m_quietQ) {
		addTextSearchSummary(infile, tcount, m_marker);
	}
}