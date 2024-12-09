void Tool_autostem::printNotePositions(HumdrumFile& infile,
		vector<vector<vector<int> > >& notepos) {
	vector<string> posinfo(infile.getLineCount());
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			if (!infile.token(i, j)->isKern()) {
				continue;
			}
			if (infile.token(i, j)->isNull()) {
				// ignore null tokens
				continue;
			}
			if (infile.token(i, j)->isRest()) {
				// ignore rests
				continue;
			}
			for (int k=0; k<(int)notepos[i][j].size(); k++) {
				posinfo[i] += notepos[i][j][k];
			}
			if (posinfo[i].back() == ' ') {
				posinfo[i].pop_back();
			}
		}
	}
	infile.appendDataSpine(posinfo, "", "**vpos");
}