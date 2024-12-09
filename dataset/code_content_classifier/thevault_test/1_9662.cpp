void Tool_autostem::getClefInfo(vector<vector<int> >& baseline,
		HumdrumFile& infile) {
	vector<int> states(infile.getMaxTrack()+1,
			Convert::kernClefToBaseline("*clefG2"));
	baseline.resize(infile.getLineCount());

	int track;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isInterpretation()) {
			for (int j=0; j<infile[i].getFieldCount(); j++) {
				if (!infile.token(i, j)->isKern()) {
					continue;
				}
				if (infile.token(i, j)->compare(0, 5, "*clef") == 0) {
					track = infile.token(i, j)->getTrack();
					states[track] = Convert::kernClefToBaseline(*infile.token(i, j));
				}
			}
		}
		if (!infile[i].isData()) {
			continue;
		}
		baseline[i].resize(infile[i].getFieldCount());
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			if (!infile.token(i, j)->isKern()) {
				continue;
			}
			track = infile.token(i, j)->getTrack();
			baseline[i][j] = states[track];
		}
	}
}