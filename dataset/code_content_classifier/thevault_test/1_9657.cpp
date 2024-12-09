void Tool_autostem::getVoiceInfo(vector<vector<int> >& voice,
		HumdrumFile& infile) {

	voice.resize(infile.getLineCount());

	int i, j, v;
	for (i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		voice[i].resize(infile[i].getFieldCount());
		fill(voice[i].begin(), voice[i].end(), -1);
		for (j=0; j<infile[i].getFieldCount(); j++) {
			if (!infile.token(i, j)->isKern()) {
				continue;
			}
			if (infile.token(i, j)->isNull()) {
				continue;
			}
			v = getVoice(infile, i, j);
			voice[i][j] = v;
		}
	}
}