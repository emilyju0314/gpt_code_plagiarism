void Tool_extract::processFieldEntry(vector<int>& field,
		vector<int>& subfield, vector<int>& model, const string& astring,
		HumdrumFile& infile) {

	int finitsize = (int)field.size();
	int maxtrack = infile.getMaxTrack();

	vector<HTp> ktracks;
	infile.getKernSpineStartList(ktracks);
	int maxkerntrack = (int)ktracks.size();

	int modletter;
	int subletter;

	HumRegex hre;
	string buffer = astring;

	// remove any comma left at end of input astring (or anywhere else)
	hre.replaceDestructive(buffer, "", ",", "g");

	// first remove $ symbols and replace with the correct values
	if (kernQ) {
		removeDollarsFromString(buffer, maxkerntrack);
	} else {
		removeDollarsFromString(buffer, maxtrack);
	}

	int zero = 0;
	if (hre.search(buffer, "^(\\d+)-(\\d+)$")) {
		int firstone = hre.getMatchInt(1);
		int lastone  = hre.getMatchInt(2);

		if ((firstone < 1) && (firstone != 0)) {
			m_error_text << "Error: range token: \"" << astring << "\""
				  << " contains too small a number at start: " << firstone << endl;
			m_error_text << "Minimum number allowed is " << 1 << endl;
			return;
		}
		if ((lastone < 1) && (lastone != 0)) {
			m_error_text << "Error: range token: \"" << astring << "\""
				  << " contains too small a number at end: " << lastone << endl;
			m_error_text << "Minimum number allowed is " << 1 << endl;
			return;
		}
		if (firstone > maxtrack) {
			m_error_text << "Error: range token: \"" << astring << "\""
				  << " contains number too large at start: " << firstone << endl;
			m_error_text << "Maximum number allowed is " << maxtrack << endl;
			return;
		}
		if (lastone > maxtrack) {
			m_error_text << "Error: range token: \"" << astring << "\""
				  << " contains number too large at end: " << lastone << endl;
			m_error_text << "Maximum number allowed is " << maxtrack << endl;
			return;
		}

		if (firstone > lastone) {
			for (int i=firstone; i>=lastone; i--) {
				field.push_back(i);
				subfield.push_back(zero);
				model.push_back(zero);
			}
		} else {
			for (int i=firstone; i<=lastone; i++) {
				field.push_back(i);
				subfield.push_back(zero);
				model.push_back(zero);
			}
		}
	} else if (hre.search(buffer, "^(\\d+)([a-z]*)")) {
		int value = hre.getMatchInt(1);
		modletter = 0;
		subletter = 0;
		if (hre.getMatch(2) ==  "a") {
			subletter = 'a';
		}
		if (hre.getMatch(2) ==  "b") {
			subletter = 'b';
		}
		if (hre.getMatch(2) ==  "c") {
			subletter = 'c';
		}
		if (hre.getMatch(2) ==  "d") {
			modletter = 'd';
		}
		if (hre.getMatch(2) ==  "n") {
			modletter = 'n';
		}
		if (hre.getMatch(2) ==  "r") {
			modletter = 'r';
		}

		if ((value < 1) && (value != 0)) {
			m_error_text << "Error: range token: \"" << astring << "\""
				  << " contains too small a number at end: " << value << endl;
			m_error_text << "Minimum number allowed is " << 1 << endl;
			return;
		}
		if (value > maxtrack) {
			m_error_text << "Error: range token: \"" << astring << "\""
				  << " contains number too large at start: " << value << endl;
			m_error_text << "Maximum number allowed is " << maxtrack << endl;
			return;
		}
		field.push_back(value);
		if (value == 0) {
			subfield.push_back(zero);
			model.push_back(zero);
		} else {
			subfield.push_back(subletter);
			model.push_back(modletter);
		}
	}

	if (!kernQ) {
		return;
	}

	// Insert fields to next **kern spine.
	vector<int> newfield;
	vector<int> newsubfield;
	vector<int> newmodel;

	vector<HTp> trackstarts;
	infile.getTrackStartList(trackstarts);
	int i, j;
	int spine;

	// convert kern tracks into spine tracks:
	for (i=finitsize; i<(int)field.size(); i++) {
		if (field[i] > 0) {
			spine = ktracks[field[i]-1]->getTrack();
		   field[i] = spine;
		}
	}

	int startspineindex, stopspineindex;
	for (i=0; i<(int)field.size(); i++) {
		newfield.push_back(field[i]); // copy **kern spine index into new list
		newsubfield.push_back(subfield[i]);
		newmodel.push_back(model[i]);

		// search for non **kern spines after specified **kern spine:
		startspineindex = field[i] + 1 - 1;
		stopspineindex = maxtrack;
		for (j=startspineindex; j<stopspineindex; j++) {
			if (trackstarts[j]->isKern()) {
				break;
			}
			newfield.push_back(j+1);
			newsubfield.push_back(zero);
			newmodel.push_back(zero);
		}
	}

	field    = newfield;
	subfield = newsubfield;
	model    = newmodel;
}