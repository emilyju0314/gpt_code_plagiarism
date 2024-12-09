bool HumdrumFileBase::analyzeNonNullDataTokens(void) {
	vector<HTp> ptokens;

	// analyze forward tokens:
	for (int i=1; i<=getMaxTrack(); i++) {
		if (!processNonNullDataTokensForTrackForward(getTrackStart(i),
				ptokens)) {
			return false;
		}
	}

	ptokens.resize(0);

	// analyze backward tokens:
	for (int i=1; i<=getMaxTrack(); i++) {
		for (int j=0; j<getTrackEndCount(i); j++) {
			if (!processNonNullDataTokensForTrackBackward(getTrackEnd(i, j),
					ptokens)) {
				return false;
			}
		}
	}

	// Eventually set the foward and backward non-null data token for
	// tokens in spines for all types of line types  For now specify
	// the next non-null data token for the exclusive interpretation token.
	// Also this implementation does not consider that the first
	// non-null data tokens may be from multiple split tokens (fix later).

	// This algorithm is probably not right, but good enough for now.
	// There may be missing portions of the file for the analysis,
	// and/or the algorithm is probably retracking tokens in the case
	// of spine splits.

	vector<HTp> stops;
	getSpineStopList(stops);
	HTp nexts = NULL;

	for (int i=0; i<(int)stops.size(); i++) {
		if (stops[i] == NULL) {
			continue;
		}
		HTp token = stops[i];
		if (token->isData() && !token->isNull()) {
			nexts = token;
		}
		token = token->getPreviousToken();

		while (token) {
			if (nexts) {
				token->addNextNonNullToken(nexts);
			}
			if (token->isData() && !token->isNull()) {
				nexts = token;
			}
			token = token->getPreviousToken();
		}
	}

	return true;
}