int MuseRecord::addAdditionalNotation(const string& symbol) {
	int len = (int)symbol.size();
	// search columns 32 to 43 for the specific symbol.
	// if it is found, then don't add.  If it is not found,
	// then do add.
	int i, j;
	int blank = -1;
	int found = 0;
	int nonempty = 0;  // true if a non-space character was found.

	for (i=43-len; i>=32; i--) {
		found = 1;
		for (j=0; j<len; j++) {
			if (getColumn(i+j) != symbol[j]) {
				found = 0;
				break;
			}
		}
		if (found) {
			return i;
		} else if (!nonempty && (getColumn(i) == ' ')) {
// cout << "@COLUMN " << i << " is blank: " << getColumn(i) << endl;
			blank = i;
			// should check that there are enough blank lines to the right
			// as well...
		} else if (getColumn(i) != ' ') {
			nonempty = i;
		}
	}

	if (blank < 0) {
		cerr << "Error in MuseRecord::addAdditionalNotation2: "
			  << "no empty space for notation" << endl;
		return 0;
	}

// cout << "@ GOT HERE symbol = " << symbol << " and blank = " << blank << endl;
	if ((blank <= 32) && (getColumn(33) == ' ')) {
		// avoid putting non-tie items in column 32.
		blank = 33;
		// not worrying about overwriting something to the right
		// of column 33 since the empty spot was checked starting
		// on the right and moving towards the left.
	}
// cout << "@COLUMN 33 = " << getColumn(33) << endl;
// cout << "@ GOT HERE symbol = " << symbol << " and blank = " << blank << endl;

	for (j=0; j<len; j++) {
		getColumn(blank+j) = symbol[j];
	}
	return blank;
}