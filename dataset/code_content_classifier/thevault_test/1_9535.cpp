void fillAnalysisInfo(HumdrumFile& infile) {
	Barnum.resize(infile.getLineCount());
	Meterdur.resize(infile.getLineCount());
	int bar = -1;
	HumNum meter = -1;
	for (int i=0; i<infile.getLineCount(); i++) {
		Barnum[i] = bar;
		Meterdur[i] = meter;
		if (infile[i].isBarline()) {
			int value = infile[i].getBarNumber();
			if (value >= 0) {
				bar = value;
			}
			Barnum[i] = bar;
		}
		if (!infile[i].isInterpretation()) {
			continue;
		}
		for (int j=0; i<infile[i].getFieldCount(); j++) {
			HTp tok = infile.token(i, j);
			if (!tok->isTimeSignature()) {
				continue;
			}
			HumNum value = Convert::timeSigToDurationInQuarter(tok);
			meter = value;
		}
		Meterdur[i] = meter;
	}
}