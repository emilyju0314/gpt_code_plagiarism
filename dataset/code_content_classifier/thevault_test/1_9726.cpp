vector<HTp> Tool_satb2gs::getClefs(HumdrumFile& infile, int line) {
	vector<HTp> output;
	for (int i=0; i<infile[line].getFieldCount(); i++) {
		HTp token = infile[line].token(i);
		if (!token->isKern()) {
			continue;
		}
		if (token->isClef()) {
			output.push_back(token);
		}
	}
	return output;
}