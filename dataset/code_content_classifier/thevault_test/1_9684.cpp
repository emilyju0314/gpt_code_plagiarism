void GridSlice::initializeByStaffCount(int staffcount) {
	if (this->size() > 0) {
		// strange that this should happen, but presume the data
		// needs to be deleted.
		for (int i=0; i<(int)this->size(); i++) {
			if (this->at(i)) {
				delete this->at(i);
				this->at(i) = NULL;
			}
		}
	}
	this->clear();
	this->resize(staffcount);

	for (int i=0; i<staffcount; i++) {
		this->at(i) = new GridPart;
		this->at(i)->resize(1);
		this->at(i)->at(0) = new GridStaff;
		this->at(i)->at(0)->resize(1);
		this->at(i)->at(0)->at(0) = new GridVoice;
	}
}