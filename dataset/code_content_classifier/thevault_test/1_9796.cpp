HLp HumdrumFileBase::insertNullInterpretationLineAbove(HumNum timestamp) {
	// for now do a linear search for the insertion point, but later
	// do something more efficient.
	HumdrumFileBase& infile = *this;
	HumNum beforet(-1);
	HumNum aftert(-1);
	int beforei = -1;
	// int afteri = -1;
	HumNum current;
	for (int i=0; i<infile.getLineCount(); i++) {
		current = infile[i].getDurationFromStart();
		if (current == timestamp) {
			beforei = i;
			break;
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

	HLp target = getLineForInterpretationInsertionAbove(beforei);

	HLp newline = new HumdrumLine;
	// copyStructure will add null tokens automatically
	newline->copyStructure(target, "*");

	int targeti = target->getLineIndex();

	// There will be problems with linking to previous line if it is
	// a manipulator.
	// infile.insertLine(targeti-1, newline);
	infile.insertLine(targeti, newline);

	// inserted line will increment beforei by one:
	beforei++;

	// Set the timestamp information for inserted line:
	HumNum durationFromStart = infile[beforei].getDurationFromStart();
	HumNum durationFromBarline = infile[beforei].getDurationFromBarline();
	HumNum durationToBarline = infile[beforei].getDurationToBarline();

	newline->m_durationFromStart = durationFromStart;
	newline->m_durationFromBarline = durationFromBarline;
	newline->m_durationToBarline = durationToBarline;

	newline->m_duration = 0;

	// Problems here if targeti line is a manipulator.
	for (int i=0; i<infile[targeti].getFieldCount(); i++) {
		HTp token = infile.token(targeti, i);
		HTp newtoken = newline->token(i);
		token->insertTokenAfter(newtoken);
	}

	return newline;
}