GridSlice* GridMeasure::addGraceToken(const string& tok, HumNum timestamp,
	int part, int staff, int voice, int maxstaff, int gracenumber) {
	if (gracenumber < 1) {
		cerr << "ERROR: gracenumber " << gracenumber << " has to be larger than 0" << endl;
		return NULL;
	}

	GridSlice* gs = NULL;
	// GridSlice* datatarget = NULL;
	auto iterator = this->begin();
	if (this->empty()) {
		// add a new GridSlice to an empty list or at end of list if timestamp
		// is after last entry in list.
		gs = new GridSlice(this, timestamp, SliceType::GraceNotes, maxstaff);
		gs->addToken(tok, part, staff, voice);
		this->push_back(gs);
	} else if (timestamp > this->back()->getTimestamp()) {

		// Grace note needs to be added at the end of a measure:
		auto it2 = this->end();
		it2--;
		int counter = 0;
		while (it2 != this->end()) {
			if ((*it2)->isGraceSlice()) {
				counter++;
				if (counter == gracenumber) {
					// insert grace note into this slice
					(*it2)->addToken(tok, part, staff, voice);
					return *it2;
				}
			} else if ((*it2)->isLayoutSlice()) {
				// skip over any layout paramter lines.
				it2--;
				continue;
			} else if ((*it2)->isDataSlice()) {
				// insert grace note after this note
				gs = new GridSlice(this, timestamp, SliceType::GraceNotes, maxstaff);
				gs->addToken(tok, part, staff, voice);
				it2++;
				this->insert(it2, gs);
				return gs;
			}
			it2--;
		}
		return NULL;

	} else {
		// search for existing line with same timestamp on a data slice:

		while (iterator != this->end()) {
			if (timestamp < (*iterator)->getTimestamp()) {
				cerr << "STRANGE CASE 2 IN GRIDMEASURE::ADDGRACETOKEN" << endl;
				cerr << "\tGRACE TIMESTAMP: " << timestamp << endl;
				cerr << "\tTEST  TIMESTAMP: " << (*iterator)->getTimestamp() << endl;
				return NULL;
			}
			if ((*iterator)->isDataSlice()) {
				if ((*iterator)->getTimestamp() == timestamp) {
					// found dataslice just before graceslice(s)
					// datatarget = *iterator;
					break;
				}
			}
			iterator++;
		}

		auto it2 = iterator;
		it2--;
		int counter = 0;
		while (it2 != this->end()) {
			if ((*it2)->isGraceSlice()) {
				counter++;
				if (counter == gracenumber) {
					// insert grace note into this slice
					(*it2)->addToken(tok, part, staff, voice);
					return *it2;
				}
			} else if ((*it2)->isLayoutSlice()) {
				// skip over any layout paramter lines.
				it2--;
				continue;
			} else if ((*it2)->isDataSlice()) {
				// insert grace note after this note
				gs = new GridSlice(this, timestamp, SliceType::GraceNotes, maxstaff);
				gs->addToken(tok, part, staff, voice);
				it2++;
				this->insert(it2, gs);
				return gs;
			}
			it2--;
		}

		// grace note should be added at start of measure
		gs = new GridSlice(this, timestamp, SliceType::GraceNotes, maxstaff);
		gs->addToken(tok, part, staff, voice);
		this->insert(this->begin(), gs);

	}

	return NULL;
}