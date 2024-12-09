void Tool_extract::fillFieldDataByEmpty(vector<int>& field, vector<int>& subfield,
		vector<int>& model, HumdrumFile& infile, int negate) {

	field.reserve(infile.getMaxTrack()+1);
	subfield.reserve(infile.getMaxTrack()+1);
	model.reserve(infile.getMaxTrack()+1);
	field.resize(0);
	subfield.resize(0);
	model.resize(0);
	vector<int> nullTrack = getNullDataTracks(infile);

	int zero = 0;
	for (int i=1; i<(int)nullTrack.size(); i++) {
		if (negate) {
			if (!nullTrack[i]) {
				field.push_back(i);
				subfield.push_back(zero);
				model.push_back(zero);
			}
		} else {
			if (nullTrack[i]) {
				field.push_back(i);
				subfield.push_back(zero);
				model.push_back(zero);
			}
		}
	}

}