GridSlice* GridMeasure::addDataToken(const string& tok, HumNum timestamp,
		int part, int staff, int voice, int maxstaff) {
	GridSlice* gs = NULL;
	if (this->empty() || (this->back()->getTimestamp() < timestamp)) {
		// add a new GridSlice to an empty list or at end of list if timestamp
		// is after last entry in list.
		gs = new GridSlice(this, timestamp, SliceType::Notes, maxstaff);
		gs->addToken(tok, part, staff, voice);
		this->push_back(gs);
	} else {
		// search for existing line with same timestamp and the same slice type
		GridSlice* target = NULL;
		auto iterator = this->begin();
		while (iterator != this->end()) {
			if ((timestamp == (*iterator)->getTimestamp()) && ((*iterator)->isGraceSlice())) {
				iterator++;
				continue;
			}
			if ((timestamp == (*iterator)->getTimestamp()) && ((*iterator)->isMeasureSlice())) {
				iterator++;
				continue;
			}
			if ((!(*iterator)->isDataSlice()) && (timestamp >= (*iterator)->getTimestamp())) {
				iterator++;
				continue;
			} else if ((*iterator)->getTimestamp() == timestamp) {
				target = *iterator;
				target->addToken(tok, part, staff, voice);
				gs = target;
				break;
			} else if (timestamp < (*iterator)->getTimestamp()) {
				gs = new GridSlice(this, timestamp, SliceType::Notes, maxstaff);
				gs->addToken(tok, part, staff, voice);
				this->insert(iterator, gs);
				break;
			}
			iterator++;
		}

		if (iterator == this->end()) {
			// Couldn't find a place for the lef, so place at end of measure.
			gs = new GridSlice(this, timestamp, SliceType::Notes, maxstaff);
			gs->addToken(tok, part, staff, voice);
			this->insert(iterator, gs);
		}
	}

	return gs;
}