HLp HumdrumFileBase::insertNullDataLine(HumNum timestamp) {
	// for now do a linear search for the insertion point, but later
	// do something more efficient.
	HumdrumFileBase& infile = *this;
	HumNum beforet(-1);
	HumNum aftert(-1);
	int beforei = -1;
	// int afteri = -1;
	HumNum current;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		current = infile[i].getDurationFromStart();
		if (current == timestamp) {
			return &infile[i];
		} else if (current < timestamp) {
			beforet = current;
			beforei = i;
		} else if (current > timestamp) {
			aftert = current;
			// afteri = i;
			break;
		}
	}

	if (beforei < 0) {
		return NULL;
	}
	HLp newline = new HumdrumLine;
	// copyStructure will add null tokens automatically
	newline->copyStructure(&infile[beforei], ".");

	infile.insertLine(beforei+1, newline);

	// Set the timestamp information for inserted line:
	HumNum delta = timestamp - beforet;
	HumNum durationFromStart = infile[beforei].getDurationFromStart() + delta;
	HumNum durationFromBarline = infile[beforei].getDurationFromBarline() + delta;
	HumNum durationToBarline = infile[beforei].getDurationToBarline() - delta;

	newline->m_durationFromStart = durationFromStart;
	newline->m_durationFromBarline = durationFromBarline;
	newline->m_durationToBarline = durationToBarline;

	newline->m_duration = infile[beforei].m_duration - delta;
	infile[beforei].m_duration = delta;

	for (int i=0; i<infile[beforei].getFieldCount(); i++) {
		HTp token = infile.token(beforei, i);
		HTp newtoken = newline->token(i);
		token->insertTokenAfter(newtoken);
	}

	return newline;
}