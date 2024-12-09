string Tool_kernview::getKernString(HumdrumFile& infile, const string& list) {
	HumRegex hre;
	vector<string> pieces;
	hre.split(pieces, list, "\\s*,\\s*");
	string output;
	vector<HTp> starts = infile.getKernSpineStartList();
	vector<bool> targets(starts.size(), false);
	for (int i=0; i<(int)pieces.size(); i++) {
		if (pieces.empty()) {
			continue;
		}
		for (int j=0; j<(int)starts.size(); j++) {
			if (targets[j]) {
				continue;
			}
			HTp current = starts[j];
			while (current) {
				if (current->isData()) {
					break;
				}
				if (hre.search(current, pieces[i])) {
					targets[j] = true;
					break;
				}
				current = current->getNextToken();
			}
		}
	}

	for (int i=0; i<(int)targets.size(); i++) {
		if (targets[i]) {
			if (output.empty()) {
				output += to_string(i+1);
			} else {
				output += "," + to_string(i+1);
			}
		}
	}

	return output;
}