void Tool_humdiff::extractTimePoints(vector<TimePoint>& points, HumdrumFile& infile) {
	TimePoint tp;
	points.clear();
	HumRegex hre;
	points.reserve(infile.getLineCount());
	int measure = -1;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isBarline()) {
			if (hre.search(infile.token(i, 0), "(\\d+)")) {
				measure = hre.getMatchInt(1);
			}
		}
		if (!infile[i].isData()) {
			continue;
		}
		if (infile[i].getDuration() == 0) {
			// ignore grace notes for now
			continue;
		}
		tp.clear();
		tp.file.push_back(&infile);
		tp.index.push_back(i);
		tp.timestamp = infile[i].getDurationFromStart();
		tp.measure = measure;
		points.push_back(tp);
	}
}