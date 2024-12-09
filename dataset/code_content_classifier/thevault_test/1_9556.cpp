void GridMeasure::addLayoutParameter(HumNum timestamp, int partindex,
		int staffindex, const string& locomment) {
	auto iter = this->rbegin();
	if (iter == this->rend()) {
		// no items in measure yet, so add
		cerr << "DEAL WITH THIS LAYOUT COMMAND" << endl;
		return;
	}
	GridPart* part;
	GridStaff* staff;
	GridVoice* voice;

	auto previous = iter;
	previous++;
	while (previous != this->rend()) {
		if ((*previous)->isLayoutSlice()) {
			part = (*previous)->at(partindex);
			staff = part->at(0);
			if (staff->size() == 0) {
				GridVoice* v = new GridVoice;
				staff->push_back(v);
			}
			voice = staff->at(0);
			if (voice) {
				if (voice->getToken() == NULL) {
					// create a token with text
					HTp newtoken = new HumdrumToken(locomment);
					voice->setToken(newtoken);
					return;
				} else if (*voice->getToken() == "!") {
					// replace token with text
					HTp newtoken = new HumdrumToken(locomment);
					voice->setToken(newtoken);
					return;
				}
			} else {
				previous++;
				continue;
			}
		} else {
			break;
		}
		previous++;
	}

	auto insertpoint = previous.base();
	GridSlice* newslice = new GridSlice(this, (*iter)->getTimestamp(), SliceType::Layouts);
	newslice->initializeBySlice(*iter);
	this->insert(insertpoint, newslice);
	HTp newtoken = new HumdrumToken(locomment);
	if (newslice->at(partindex)->at(0)->size() == 0) {
		GridVoice* v = new GridVoice;
		newslice->at(partindex)->at(0)->push_back(v);
	}
	newslice->at(partindex)->at(0)->at(0)->setToken(newtoken);
}