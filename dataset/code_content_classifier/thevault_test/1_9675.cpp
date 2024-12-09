void GridSlice::transferTokens(HumdrumFile& outfile, bool recip) {
	HTp token = NULL;
	HLp line = new HumdrumLine;
	GridVoice* voice;
	string empty = ".";
	if (isMeasureSlice()) {
		if (this->size() > 0) {
			if (this->at(0)->at(0)->size() > 0) {
				voice = this->at(0)->at(0)->at(0);
				HTp tok = voice->getToken();
				if (tok != NULL) {
					empty = (string)*tok;
				}
			} else {
				empty = "=YYYYYY";
			}
		}
	} else if (isInterpretationSlice()) {
		empty = "*";
	} else if (isLayoutSlice()) {
		empty = "!";
	} else if (isMeasureSlice()) {
		empty = "=";
	} else if (!hasSpines()) {
		empty = "???";
	}

	if (recip) {
		if (isNoteSlice()) {
			token = createRecipTokenFromDuration(getDuration());
		} else if (isClefSlice()) {
			token = new HumdrumToken("*");
			empty = "*";
		} else if (isMeasureSlice()) {
			if (this->at(0)->at(0)->size() > 0) {
				voice = this->at(0)->at(0)->at(0);
				token = new HumdrumToken((string)*voice->getToken());
			} else {
				token = new HumdrumToken("=XXXXX");
			}
			empty = (string)*token;
		} else if (isInterpretationSlice()) {
			token = new HumdrumToken("*");
			empty = "*";
		} else if (isGraceSlice()) {
			token = new HumdrumToken("q");
			empty = ".";
		} else if (hasSpines()) {
			token = new HumdrumToken("55");
			empty = "!";
		}
		if (token != NULL) {
			if (hasSpines()) {
				line->appendToken(token);
			} else {
				delete token;
				token = NULL;
			}
		}
	}

	// extract the Tokens from each part/staff
	int p; // part index
	int s; // staff index
	int v; // voice index

	for (p=(int)size()-1; p>=0; p--) {
		if ((!hasSpines()) && (p != 0)) {
			continue;
		}
		GridPart& part = *this->at(p);
		for (s=(int)part.size()-1; s>=0; s--) {
			if ((!hasSpines()) && (s != 0)) {
				continue;
			}
			GridStaff& staff = *part.at(s);
			if (staff.size() == 0) {
				// fix this later.  For now if there are no notes
				// on the staff, add a null token.  Fix so that
				// all open voices are given null tokens.
				token = new HumdrumToken(empty);
				line->appendToken(token);
			} else {
				for (v=0; v<(int)staff.size(); v++) {
					if (staff.at(v) && staff.at(v)->getToken()) {
						line->appendToken(staff.at(v)->getToken());
						staff.at(v)->forgetToken();
					} else if (!staff.at(v)) {
						token = new HumdrumToken(empty);
						line->appendToken(token);
					} else {
						token = new HumdrumToken(empty);
						line->appendToken(token);
					}
				}
			}

			if (!this->hasSpines()) {
				// Don't add sides to non-spined lines
				continue;
			}

			int maxxcount = getXmlidCount(p, s);
			int maxvcount = getVerseCount(p, s);
			int maxhcount = getHarmonyCount(p, s);
			int maxfcount = getFiguredBassCount(p, s);
			if (hasSpines()) {
				transferSides(*line, staff, empty, maxxcount, maxvcount, maxhcount, maxfcount);
			}
		}

		// Transfer the sides at the part level
		int maxxcount = getXmlidCount(p);
		int maxhcount = getHarmonyCount(p);
		int maxvcount = getVerseCount(p, -1);
		int maxdcount = getDynamicsCount(p);
		int maxfcount = getFiguredBassCount(p);

		if (hasSpines()) {
			transferSides(*line, part, p, empty, maxxcount, maxvcount, maxhcount, maxdcount, maxfcount);
		}
	}

	outfile.appendLine(line);
}