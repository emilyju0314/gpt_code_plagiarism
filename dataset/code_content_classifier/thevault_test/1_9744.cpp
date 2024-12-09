void Tool_extract::reverseSpines(vector<int>& field, vector<int>& subfield,
		vector<int>& model, HumdrumFile& infile, const string& exinterp) {

	vector<int> target;
	target.resize(infile.getMaxTrack()+1);
	fill(target.begin(), target.end(), 0);

	vector<HTp> trackstarts;
	infile.getSpineStartList(trackstarts);

	for (int t=0; t<(int)trackstarts.size(); t++) {
		if (trackstarts[t]->isDataType(exinterp)) {
			target.at(t + 1) = 1;
		}
	}

	field.reserve(infile.getMaxTrack()*2);
	field.resize(0);

	int lasti = (int)target.size();
	for (int i=(int)target.size()-1; i>0; i--) {
		if (target[i]) {
			lasti = i;
			field.push_back(i);
			for (int j=i+1; j<(int)target.size(); j++) {
				if (!target.at(j)) {
					field.push_back(j);
				} else {
					break;
				}
			}
		}
	}

	// if the grouping spine is not first, then preserve the
	// locations of the pre-spines.
	int extras = 0;
	if (lasti != 1) {
		extras = lasti - 1;
		field.resize(field.size()+extras);
		for (int i=0; i<(int)field.size()-extras; i++) {
			field[(int)field.size()-1-i] = field[(int)field.size()-1-extras-i];
		}
		for (int i=0; i<extras; i++) {
			field[i] = i+1;
		}
	}

	if (debugQ) {
		m_humdrum_text << "!!reverse: ";
		for (int i=0; i<(int)field.size(); i++) {
			m_humdrum_text << field[i] << " ";
		}
		m_humdrum_text << endl;
	}

	subfield.resize(field.size());
	fill(subfield.begin(), subfield.end(), 0);

	model.resize(field.size());
	fill(model.begin(), model.end(), 0);
}