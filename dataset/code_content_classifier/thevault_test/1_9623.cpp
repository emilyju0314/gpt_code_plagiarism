void Tool_gasparize::deleteDummyTranspositions(HumdrumFile& infile) {
	vector<int> ldel;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].hasSpines()) {
			continue;
		}
		if (!infile[i].isInterpretation()) {
			continue;
		}
		bool empty = true;
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (*token == "*") {
				continue;
			}
			if (!token->isKern()) {
				empty = false;
				continue;
			}
			if (*token == "*Trd0c0") {
				token->setText("*");
			} else {
				empty = false;
			}
		}
		if (empty) {
			ldel.push_back(i);
		}
	}

	if (ldel.size() == 1) {
		infile.deleteLine(ldel[0]);
	} else if (ldel.size() > 1) {
		cerr << "Warning: multiple transposition lines, not deleting them" << endl;
	}

}