void GridSlice::initializeBySlice(GridSlice* slice) {
	int partcount = (int)slice->size();
	this->resize(partcount);
	for (int p = 0; p < partcount; p++) {
		this->at(p) = new GridPart;
		int staffcount = (int)slice->at(p)->size();
		this->at(p)->resize(staffcount);
		for (int s = 0; s < staffcount; s++) {
			this->at(p)->at(s) = new GridStaff;
			int voicecount = (int)slice->at(p)->at(s)->size();
			this->at(p)->at(s)->resize(voicecount);
			for (int v=0; v < voicecount; v++) {
				this->at(p)->at(s)->at(v) = new GridVoice;
			}
		}
	}
}