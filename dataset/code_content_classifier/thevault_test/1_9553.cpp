GridSlice* GridMeasure::addGlobalComment(const string& tok, HumNum timestamp) {
	GridSlice* gs = NULL;
	if (this->empty() || (this->back()->getTimestamp() < timestamp)) {
		// add a new GridSlice to an empty list or at end of list if timestamp
		// is after last entry in list.
		gs = new GridSlice(this, timestamp, SliceType::GlobalComments, 1);
		gs->addToken(tok, 0, 0, 0);
		this->push_back(gs);
	} else {
		// search for existing data line (or any other type)  with same timestamp
		auto iterator = this->begin();
		while (iterator != this->end()) {
			// does it need to be before data slice or any slice?
			// if (((*iterator)->getTimestamp() == timestamp) && (*iterator)->isDataSlice()) {
			if ((*iterator)->getTimestamp() == timestamp) {
				// found the correct timestamp on a data slice, so add the global comment
				// before the data slice.  But don't add if the previous
				// grid slice is a global comment with the same text.
				if ((iterator != this->end()) && (*iterator)->isGlobalComment()) {
					if (tok == (*iterator)->at(0)->at(0)->at(0)->getToken()->getText()) {
						// do not insert duplicate global comment
						gs = *iterator;
						break;
					}
				}
				gs = new GridSlice(this, timestamp, SliceType::GlobalComments, 1);
				gs->addToken(tok, 0, 0, 0);
				this->insert(iterator, gs);
				break;
			} else if ((*iterator)->getTimestamp() > timestamp) {
				gs = new GridSlice(this, timestamp, SliceType::GlobalComments, 1);
				gs->addToken(tok, 0, 0, 0);
				this->insert(iterator, gs);
				break;
			}
			iterator++;
		}
	}
	return gs;
}