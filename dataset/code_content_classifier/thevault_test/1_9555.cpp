void GridMeasure::appendInitialBarline(HumdrumFile& infile, int startbarline) {
	(void)startbarline; // suppress compiler warnings about variable not being used
	if (infile.getLineCount() == 0) {
		// strange case which should never happen.
		return;
	}
	if (getMeasureNumber() > 0) {
		startbarline = getMeasureNumber();
	}
	int fieldcount = infile.back()->getFieldCount();
	HLp line = new HumdrumLine;
	string tstring = "=";
//	if (startbarline) {
//		tstring += to_string(startbarline);
//	} else {
//		tstring += "1";
//	}
	// probably best not to start with an invisible barline since
	// a plain barline would not be shown before the first measure anyway.
	// tstring += "-";
	HTp token;
	for (int i=0; i<fieldcount; i++) {
		token = new HumdrumToken(tstring);
		line->appendToken(token);
	}
	infile.push_back(line);
}