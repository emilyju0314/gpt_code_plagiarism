bool HumdrumFileBase::stitchLinesTogether(HumdrumLine& previous,
		HumdrumLine& next) {
	int i;

	// first handle simple cases where the spine assignments are one-to-one:
	if (!previous.isInterpretation() && !next.isInterpretation()) {
		if (previous.getTokenCount() != next.getTokenCount()) {
			stringstream err;
			err << "Error lines " << (previous.getLineNumber())
			    << " and " << (next.getLineNumber()) << " not same length\n";
			err << "Line " << (previous.getLineNumber()) << ": " << previous << endl;
			err << "Line " << (next.getLineNumber()) << ": " << next << endl;
			return setParseError(err);
		}
		for (i=0; i<previous.getTokenCount(); i++) {
			if (next.token(i)) {
				previous.token(i)->makeForwardLink(*next.token(i));
			} else {
				cerr << "Strange error 1" << endl;
			}
		}
		return true;
	}
	int ii = 0;
	for (i=0; i<previous.getTokenCount(); i++) {
		if (!previous.token(i)->isManipulator()) {
			if (next.token(ii) != NULL) {
				previous.token(i)->makeForwardLink(*next.token(ii++));
			} else {
				cerr << "Strange error 2" << endl;
			}
		} else if (previous.token(i)->isSplitInterpretation()) {
			// connect the previous token to the next two tokens.
			if (next.token(ii) != NULL) {
				previous.token(i)->makeForwardLink(*next.token(ii++));
			} else {
				cerr << "Strange error 3" << endl;
			}
			if (next.token(ii) != NULL) {
				previous.token(i)->makeForwardLink(*next.token(ii++));
			} else {
				cerr << "Strange error 4" << endl;
			}
		} else if (previous.token(i)->isMergeInterpretation()) {
			// connect multiple previous tokens which are adjacent *v
			// spine manipulators to the current next token.
			while ((i<previous.getTokenCount()) &&
					previous.token(i)->isMergeInterpretation()) {
				if (next.token(ii) != NULL) {
					previous.token(i)->makeForwardLink(*next.token(ii));
				} else {
					cerr << "Strange error 5" << endl;
				}
				i++;
			}
			i--;
			ii++;
		} else if (previous.token(i)->isExchangeInterpretation()) {
			// swapping the order of two spines.
			if ((i<previous.getTokenCount()) &&
					previous.token(i+1)->isExchangeInterpretation()) {
				if (next.token(ii) != NULL) {
					previous.token(i+1)->makeForwardLink(*next.token(ii++));
				} else {
					cerr << "Strange error 6" << endl;
				}
				if (next.token(ii) != NULL) {
					previous.token(i)->makeForwardLink(*next.token(ii++));
				} else {
					cerr << "Strange error 7" << endl;
				}
			}
			i++;
		} else if (previous.token(i)->isTerminateInterpretation()) {
			// No link should be made.  There may be a problem if a
			// new segment is given (this should be handled by a
			// HumdrumSet class, not HumdrumFileBase.
		} else if (previous.token(i)->isAddInterpretation()) {
			// A new data stream is being added, the next linked token
			// should be an exclusive interpretation.
			if (!next.token(ii+1)->isExclusiveInterpretation()) {
				stringstream err;
				err << "Error: expecting exclusive interpretation on line "
				    << next.getLineNumber() << " at token " << i << " but got "
				    << next.token(i);
				return setParseError(err);
			}
			if (next.token(ii) != NULL) {
				previous.token(i)->makeForwardLink(*next.token(ii++));
			} else {
				cerr << "Strange error 8" << endl;
			}
			ii++;
		} else if (previous.token(i)->isExclusiveInterpretation()) {
			if (next.token(ii) != NULL) {
				if (previous.token(i) != NULL) {
					previous.token(i)->makeForwardLink(*next.token(ii++));
				} else {
					cerr << "Strange error 10" << endl;
				}
			} else {
				cerr << "Strange error 9" << endl;
			}
		} else {
			return setParseError("Error: should not get here");
		}
	}

	if ((i != previous.getTokenCount()) || (ii != next.getTokenCount())) {
		stringstream err;
		err << "Error: cannot stitch lines together due to alignment problem\n";
		err << "Line " << previous.getLineNumber() << ": "
		    << previous << endl;
		err << "Line " << next.getLineNumber() << ": "
		    << next << endl;
		err << "I = " <<i<< " token count " << previous.getTokenCount() << endl;
		err << "II = " <<ii<< " token count " << next.getTokenCount();
		return setParseError(err);
	}

	return isValid();
}