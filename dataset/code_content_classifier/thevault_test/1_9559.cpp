bool GridMeasure::isInvisible(void) {

	for (auto slice : *this) {
		if (!slice->isDataSlice()) {
			continue;
		}
		for (int p=0; p<(int)slice->size(); p++) {
			GridPart* part = slice->at(p);
			for (int s=0; s<(int)part->size(); s++) {
				GridStaff* staff = part->at(s);
				for (int v=0; v<(int)staff->size(); v++) {
					GridVoice* voice = staff->at(v);
					HTp token = voice->getToken();
					if (!token) {
						return false;
					}
					if (token->find("yy") == string::npos) {
						return false;
					}
				}
			}
		}
	}
	return true;

}