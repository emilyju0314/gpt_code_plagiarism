void GridMeasure::addInterpretationAfter(GridSlice* slice, int partindex,
		int staffindex, int voiceindex, const string& interpretation, HumNum timestamp) {
	HumNum targettime = slice->getTimestamp();

	auto iter = this->rbegin();
	if (iter == this->rend()) {
		// something strange happened: expecting at least one item in measure.
		return;
	}
	// GridPart* part;
	// GridStaff* staff;
	// GridVoice* voice;

	auto previous = iter;
	// auto last = previous;
	previous++;
	HumNum ptime;
	HumNum newtargettime;
	if (previous != this->rend()) {
		ptime = (*previous)->getTimestamp();
		newtargettime = ptime;
	} else {
		ptime = targettime;
		newtargettime = targettime;
	}

	if (ptime == targettime) {

		auto nextone = previous;
		nextone--;
		if ((nextone != this->rend()) && ((*nextone)->isInterpretationSlice())) {
			GridPart* gp = (*nextone)->at(partindex);
			GridStaff* gs = gp->at(staffindex);
			// only place in voice=0 for now:
			if (gs->size() == 0) {
				GridVoice* gv = new GridVoice;
				gs->push_back(gv);
			}
			HTp token = gs->at(0)->getToken();
			if (token == NULL) {
				gs->at(0)->setToken(interpretation);
				return;
			} else if (*token == "*") {
				gs->at(0)->setToken(interpretation);
				return;
			}
		}
	}

	if (ptime <= targettime) {
		// Insert slice at end of measure.
		GridSlice* newslice = new GridSlice(this, timestamp, SliceType::_Interpretation);
		newslice->initializeBySlice(slice);
		this->push_back(newslice);
		HTp newtoken = new HumdrumToken(interpretation);
		if (newslice->at(partindex)->at(0)->size() == 0) {
			GridVoice* v = new GridVoice;
			newslice->at(partindex)->at(0)->push_back(v);
		}
		newslice->at(partindex)->at(0)->at(0)->setToken(newtoken);
		return;
	}
}