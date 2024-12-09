void GridMeasure::addInterpretationBefore(GridSlice* slice, int partindex, int staffindex, int voiceindex,
		const string& interpretation) {
	auto iter = this->rbegin();
	if (iter == this->rend()) {
		// something strange happened: expecting at least one item in measure.
		return;
	}

	auto previous = iter;
	previous++;

	// Try to insert new token in the current interpretation
	// line if there is a spot that is empty.  This should usually
	// work, but there could be times when the interpretation line
	// has a specific submeaning that will not match the inserted
	// interpretation.
	if ((previous != this->rend()) && (*previous)->isInterpretationSlice()) {
		GridPart* gp = (*previous)->at(partindex);
		GridStaff* gs = gp->at(0);
		GridVoice* gv = NULL;
		if (gs->empty()) {
			gv = new GridVoice;
			gs->push_back(gv);
		}
		// only allowing at index 0 voice for now:
		// And is asuumed now to be non-null.
		gv = gs->at(0);
		HTp token = gv->getToken();
		if (!token) {
			gv->setToken(interpretation);
			return;
		} else if (token->isNull()) {
			gv->setToken(interpretation);
			return;
		}
	}

	// Could not insert interpretation on interpretation line immediatly before
	// the assumed starting data line, so insert a new interpretation slice just before
	// the data slice.
	auto insertpoint = previous.base();
	GridSlice* newslice = new GridSlice(this, (*iter)->getTimestamp(), SliceType::_Interpretation);
	newslice->initializeBySlice(*iter);
	this->insert(insertpoint, newslice);
	HTp newtoken = new HumdrumToken(interpretation);
	if (newslice->at(partindex)->at(0)->size() == 0) {
		GridVoice* v = new GridVoice;
		newslice->at(partindex)->at(0)->push_back(v);
	}
	newslice->at(partindex)->at(0)->at(0)->setToken(newtoken);
}