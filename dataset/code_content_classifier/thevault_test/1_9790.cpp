void HumdrumFileBase::addUniqueTokens(vector<HTp>& target,
		vector<HTp>& source) {
	int i, j;
	bool found;
	for (i=0; i<(int)source.size(); i++) {
		found = false;
		for (j=0; j<(int)target.size(); j++) {
			if (source[i] == target[i]) {
				found = true;
			}
		}
		if (!found) {
			target.push_back(source[i]);
		}
	}
}