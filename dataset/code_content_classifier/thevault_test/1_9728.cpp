bool Tool_satb2gs::validateHeader(HumdrumFile& infile) {
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isData()) {
			break;
		}
		if (!infile[i].isInterpretation()) {
			continue;
		}
		HTp token = infile.token(i, 0);
		if (token->isExclusive()) {
			continue;
		}
		if (infile[i].isManipulator()) {
			return false;
		}
	}

	return true;
}