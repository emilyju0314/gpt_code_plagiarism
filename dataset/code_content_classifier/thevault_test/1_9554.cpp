bool GridMeasure::transferTokens(HumdrumFile& outfile, bool recip,
		bool addbar, int startbarnum) {

	// If the last data slice duration is zero, then calculate
	// the true duration from the duration of the measure.
	if (this->size() > 0) {
		GridSlice* slice = back();
		if (slice->isMeasureSlice() && (this->size() >= 2)) {
			auto ending = this->end();
			--ending;
			--ending;
			while ((ending != this->begin()) && (!(*ending)->isDataSlice())) {
				--ending;
			}
			slice = *ending;
		} else {
			slice = NULL;
		}
		if ((slice != NULL) && slice->isDataSlice()
				&& (slice->getDuration() == 0)) {
			HumNum mts  = getTimestamp();
			HumNum mdur = getDuration();
			HumNum sts  = slice->getTimestamp();
			HumNum slicedur = (mts + mdur) - sts;
			slice->setDuration(slicedur);
		}
	}

	bool founddata = false;
	bool addedbar = false;

	for (auto it : *this) {
		if (it->isInvalidSlice()) {
			// ignore slices to be removed from output (used for
			// removing redundant clef slices).
			continue;
		}
		if (it->isDataSlice()) {
			founddata = true;
		}
		if (it->isLayoutSlice()) {
			// didn't actually find data, but barline should
			// not cross this line.
			founddata = true;
		}
		if (it->isManipulatorSlice()) {
			// didn't acutally find data, but the barline should
			// be placed before any manipulator (a spine split), since
			// that is more a property of the data than of the header
			// interpretations.
			founddata = true;
		}
		if (founddata && addbar && !addedbar) {
			if (getDuration() == 0) {
				// do nothing
			} else {
				if (startbarnum) {
					appendInitialBarline(outfile, startbarnum);
				} else {
					appendInitialBarline(outfile);
				}
				addedbar = true;
			}
		}
		it->transferTokens(outfile, recip);
	}
	return true;
}