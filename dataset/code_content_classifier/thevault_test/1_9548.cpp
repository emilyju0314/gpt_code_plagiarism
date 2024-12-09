GridSlice* GridMeasure::addLabelToken(const string& tok, HumNum timestamp,
		int part, int staff, int voice, int maxpart, int maxstaff) {
	GridSlice* gs = NULL;
	if (this->empty() || (this->back()->getTimestamp() < timestamp)) {
		// add a new GridSlice to an empty list or at end of list if timestamp
		// is after last entry in list.
		gs = new GridSlice(this, timestamp, SliceType::Labels, maxpart);
		gs->addToken(tok, part, maxstaff-1, voice);
		this->push_back(gs);
	} else {
		// search for existing line with same timestamp and the same slice type
		GridSlice* target = NULL;
		auto iterator = this->begin();
		while (iterator != this->end()) {
			if (((*iterator)->getTimestamp() == timestamp) && (*iterator)->isLabelSlice()) {
				target = *iterator;
				target->addToken(tok, part, maxstaff-1, voice);
				break;
			}
			iterator++;
		}
		if (iterator == this->end()) {
			// Couldn't find a place for the label abbreviation line, so place at end of measure.
			gs = new GridSlice(this, timestamp, SliceType::Labels, maxpart);
			gs->addToken(tok, part, maxstaff-1, voice);
			this->insert(this->begin(), gs);
		}
	}
	return gs;
}