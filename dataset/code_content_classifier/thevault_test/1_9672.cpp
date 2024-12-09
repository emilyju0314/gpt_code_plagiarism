GridSlice::GridSlice(GridMeasure* measure, HumNum timestamp, SliceType type,
		const GridSlice& slice) {
	m_timestamp = timestamp;
	m_type = type;
	m_owner = measure->getOwner();
	m_measure = measure;
	int partcount = (int)slice.size();
	int staffcount;
	int voicecount;
	if (partcount > 0) {
		this->resize(partcount);
		for (int p=0; p<partcount; p++) {
			this->at(p) = new GridPart;
			GridPart* part = this->at(p);
			staffcount = (int)slice.at(p)->size();
			part->resize(staffcount);
			for (int s=0; s<staffcount; s++) {
				part->at(s) = new GridStaff;
				// voicecount = (int)slice.at(p)->at(s)->size();
				voicecount = 0;
				GridStaff* staff = part->at(s);
				staff->resize(voicecount);
				for (int v=0; v<voicecount; v++) {
					staff->at(v) = new GridVoice;
				}
			}
		}
	}
}