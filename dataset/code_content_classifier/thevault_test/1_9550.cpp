GridSlice* GridMeasure::addTransposeToken(const string& tok, HumNum timestamp,
		int part, int staff, int voice, int maxstaff) {
	GridSlice* gs = NULL;
	if (this->empty() || (this->back()->getTimestamp() < timestamp)) {
		// add a new GridSlice to an empty list or at end of list if timestamp
		// is after last entry in list.
		gs = new GridSlice(this, timestamp, SliceType::Transpositions, maxstaff);
		gs->addToken(tok, part, staff, voice);
		this->push_back(gs);
	} else {
		// search for existing line with same timestamp and the same slice type
		GridSlice* target = NULL;
		auto iterator = this->begin();
		while (iterator != this->end()) {
			if (((*iterator)->getTimestamp() == timestamp) && (*iterator)->isTransposeSlice()) {
				target = *iterator;
				target->addToken(tok, part, staff, voice);
				break;
			} else if (((*iterator)->getTimestamp() == timestamp) && (*iterator)->isDataSlice()) {
				// found the correct timestamp, but no clef slice at the timestamp
				// so add the clef slice before the data slice (eventually keeping
				// track of the order in which the other non-data slices should be placed).
				gs = new GridSlice(this, timestamp, SliceType::Transpositions, maxstaff);
				gs->addToken(tok, part, staff, voice);
				this->insert(iterator, gs);
				break;
			} else if ((*iterator)->getTimestamp() > timestamp) {
				gs = new GridSlice(this, timestamp, SliceType::Transpositions, maxstaff);
				gs->addToken(tok, part, staff, voice);
				this->insert(iterator, gs);
				break;
			}
			iterator++;
		}

		if (iterator == this->end()) {
			// Couldn't find a place for the key signature, so place at end of measure.
			gs = new GridSlice(this, timestamp, SliceType::Transpositions, maxstaff);
			gs->addToken(tok, part, staff, voice);
			this->insert(iterator, gs);
		}

	}
	return gs;
}