void Tool_autostem::insertStems(HumdrumFile& infile,
		vector<vector<int> >& stemdir) {
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			if (!infile.token(i, j)->isKern()) {
				continue;
			}
			setStemDirection(infile, i, j, stemdir[i][j]);
		}
	}
}