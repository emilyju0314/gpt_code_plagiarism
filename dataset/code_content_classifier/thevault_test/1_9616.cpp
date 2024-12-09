int Tool_msearch::checkHarmonicPitchMatch(SonorityNoteData& query,
		SonorityDatabase& sonorities, bool suppressQ) {
	bool isChromatic = query.hasAccidental();
	bool isLowest = query.hasUpperCase();

	if (isLowest) {
		if (isChromatic) {
			int cpc = query.getBase40Pc();
			if (cpc != sonorities.getLowest().getBase40Pc()) {
				return 0;
			}
		} else {
			int dpc = query.getBase7Pc();
			if (dpc != sonorities.getLowest().getBase7Pc()) {
				return 0;
			}
		}
	}

	pair<HTp, int> tomark;

	// this algorithm highlights all vertical sonorities of given pitch class.
	int output = 0;
	if (isChromatic) {
		int cpitch = query.getBase40Pc();
		int cpc = cpitch % 40;
		for (int i=0; i<sonorities.getCount(); i++) {
			if (cpc == sonorities[i].getBase40Pc()) {
				if (!suppressQ) {
					tomark.first = sonorities[i].getToken();
					tomark.second = sonorities[i].getIndex();
					m_tomark.push_back(tomark);
				}
				output += 1;
			}
		}
	} else {
		int dpitch = query.getBase7Pc();
		int dpc = dpitch % 7;
		for (int i=0; i<sonorities.getCount(); i++) {
			if (dpc == sonorities[i].getBase7Pc()) {
				if (!suppressQ) {
					tomark.first = sonorities[i].getToken();
					tomark.second = sonorities[i].getIndex();
					m_tomark.push_back(tomark);
				}
				output += 1;
			}
		}
	}

	return output;
}