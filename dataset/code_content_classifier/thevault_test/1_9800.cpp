bool HumdrumFileContent::analyzeKernPhrasings(void) {
	vector<HTp> phrasestarts;
	vector<HTp> phraseends;

	vector<HTp> l;
	vector<pair<HTp, HTp>> labels; // first is previous label, second is next label
	HumdrumFileBase& infile = *this;
	labels.resize(infile.getLineCount());
	l.resize(infile.getLineCount());
	for (int i=0; i<infile.getLineCount(); i++) {
		labels[i].first = NULL;
		labels[i].second = NULL;
		l[i] = NULL;
	}
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isInterpretation()) {
			continue;
		}
		HTp token = infile.token(i, 0);
		if ((token->compare(0, 2, "*>") == 0) && (token->find("[") == std::string::npos)) {
			l[i] = token;
		}
	}
	HTp current = NULL;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (l[i] != NULL) {
			current = l[i];
		}
		labels[i].first = current;
	}
	current = NULL;
	for (int i=infile.getLineCount() - 1; i>=0; i--) {
		if (l[i] != NULL) {
			current = l[i];
		}
		labels[i].second = current;
	}

	vector<int> endings(infile.getLineCount(), 0);
	int ending = 0;
	for (int i=0; i<(int)endings.size(); i++) {
		if (l[i]) {
			char lastchar = l[i]->back();
			if (isdigit(lastchar)) {
				ending = lastchar - '0';
			} else {
				ending = 0;
			}
		}
		endings[i] = ending;
	}

	vector<HTp> kernspines;
	getSpineStartList(kernspines, "**kern");
	bool output = true;
	string linkSignifier = m_signifiers.getKernLinkSignifier();
	for (int i=0; i<(int)kernspines.size(); i++) {
		output = output && analyzeKernPhrasings(kernspines[i], phrasestarts, phraseends, labels, endings, linkSignifier);
	}

	createLinkedPhrasings(phrasestarts, phraseends);
	return output;
}