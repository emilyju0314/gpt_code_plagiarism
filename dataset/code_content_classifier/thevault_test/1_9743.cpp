void Tool_extract::fillFieldDataByNoRest(vector<int>& field, vector<int>& subfield,
		vector<int>& model, const string& searchstring, HumdrumFile& infile,
		int state) {

	field.clear();
	subfield.clear();
	model.clear();


	// Check every **kern spine for any notes.  If there is a note
	// then the tracks variable for that spine will be marked
	// as non-zero.
	vector<int> tracks(infile.getMaxTrack() + 1, 0);
	int track;
	int partline = 0;
	bool dataQ = false;
	for (int i=0; i<infile.getLineCount(); i++) {
		if ((!partline) && (!dataQ) && infile[i].hasSpines()) {

		}
		if (!infile[i].isData()) {
			continue;
		}
		dataQ = true;
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (!token->isKern()) {
				continue;
			}
			if (token->isNull()) {
				continue;
			}
			if (token->isRest()) {
				continue;
			}
			track = token->getTrack();
			tracks[track] = 1;
		}
	}

	// Go back and mark any empty spines as non-empty if they
   // are in a part that contains multiple staves. I.e., only
	// delete a staff if all staves for the part are empty.
	// There should be a single *part# line at the start of the
	// score.
	if (partline > 0) {
		vector<HTp> kerns;
		for (int i=0; i<infile[partline].getFieldCount(); i++) {
			HTp token = infile.token(partline, i);
			if (!token->isKern()) {
				continue;
			}
			kerns.push_back(token);
		}
		for (int i=0; i<(int)kerns.size(); i++) {
			for (int j=i+1; j<(int)kerns.size(); j++) {
				if (*kerns[i] != *kerns[j]) {
					continue;
				}
				if (kerns[i]->find("*part") == string::npos) {
					continue;
				}
				int track1 = kerns[i]->getTrack();
				int track2 = kerns[j]->getTrack();
				int state1 = tracks[track1];
				int state2 = tracks[track2];
				if ((state1 && !state2) || (state2 && !state1)) {
					// Prevent empty staff from being removed
					// from a multi-staff part:
					tracks[track1] = 1;
					tracks[track2] = 1;
				}
			}
		}
	}


	// deal with co-spines
	vector<HTp> sstarts;
	infile.getSpineStartList(sstarts);
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (!sstarts[i]->isKern()) {
			track = sstarts[i]->getTrack();
			tracks[track] = 1;
		}
	}

	// remove co-spines attached to removed kern spines
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (!sstarts[i]->isKern()) {
			continue;
		}
		if (tracks[sstarts[i]->getTrack()] != 0) {
			continue;
		}
		for (int j=i+1; j<(int)sstarts.size(); j++) {
			if (sstarts[j]->isKern()) {
				break;
			}
			track = sstarts[j]->getTrack();
			tracks[track] = 0;
		}
	}

	int zero = 0;
	for (int i=1; i<(int)tracks.size(); i++) {
		if (state != 0) {
			tracks[i] = !tracks[i];
		}
		if (tracks[i]) {
			field.push_back(i);
			subfield.push_back(zero);
			model.push_back(zero);
		}
	}

}