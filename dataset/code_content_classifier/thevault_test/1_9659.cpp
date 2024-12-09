void Tool_autostem::assignBasicStemDirections(vector<vector<int> >& stemdir,
		vector<vector<int> >& voice, vector<vector<vector<int> > >& notepos,
		HumdrumFile& infile) {

	int i, j;
	for (i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		for (j=0; j<infile[i].getFieldCount(); j++) {
			if (!infile.token(i, j)->isKern()) {
				continue;
			}
			if (infile.token(i, j)->isNull()) {
				continue;
			}
			if (infile.token(i, j)->isRest()) {
				continue;
			}
			if (removeQ) {
				removeStem2(infile, i, j);
			}

			if (Convert::contains(infile.token(i, j), '/')) {
				stemdir[i][j] = +1;
			} else if (Convert::contains(infile.token(i, j), '\\')) {
				stemdir[i][j] = -1;
			} else {
				stemdir[i][j] = determineChordStem(voice, notepos, infile, i, j);
			}
		}
	}
}