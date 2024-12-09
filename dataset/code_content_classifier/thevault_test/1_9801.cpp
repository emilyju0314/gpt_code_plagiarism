void HumdrumFileContent::createLinkedPhrasings(vector<HTp>& linkstarts, vector<HTp>& linkends) {
	int max = (int)linkstarts.size();
	if ((int)linkends.size() < max) {
		max = (int)linkends.size();
	}
	if (max == 0) {
		// nothing to do
		return;
	}

	for (int i=0; i<max; i++) {
		linkPhraseEndpoints(linkstarts[i], linkends[i]);
	}
}