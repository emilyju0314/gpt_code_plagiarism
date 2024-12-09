int HumdrumFileContent::hasPickup(void) {
	HumdrumFileContent& infile = *this;
	int barline = -1;
	HTp tsig = NULL;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isBarline()) {
			if (barline > 0) {
				// second barline found, so stop looking for time signature
				break;
			}
			barline = i;
			continue;
		}
		if (!infile[i].isInterpretation()) {
			continue;
		}
		if (tsig != NULL) {
			continue;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (token->isTimeSignature()) {
				tsig = token;
				break;
			}
		}
	}
	if (tsig == NULL) {
		// no time signature so return 0
		return 0;
	}
	if (barline < 0) {
		// no barlines in music
		return 0;
	}
	HumNum mdur = infile[barline].getDurationFromStart();
	HumNum tdur = Convert::timeSigToDurationInQuarter(tsig);
	if (mdur == tdur) {
		return 0;
	}
	return barline;
}