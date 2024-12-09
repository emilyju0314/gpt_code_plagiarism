int MuseRecord::addAdditionalNotation(char symbol) {
	// search columns 32 to 43 for the specific symbol.
	// if it is found, then don't add.  If it is not found,
	// then do add.
	int i;
	int blank = -1;
	int nonempty = 0;  // true if a non-space character was found.

	for (i=43; i>=32; i--) {
		if (getColumn(i) == symbol) {
			return i;
		} else if (!nonempty && (getColumn(i) == ' ')) {
			blank = i;
		} else {
			nonempty = i;
		}
	}

	if (symbol == '-') {
	  // give preferential treatment to placing only ties in
	  // column 32
	  if (getColumn(32) == ' ') {
		  getColumn(32) = '-';
		  return 32;
	  }
	}

	if (blank < 0) {
		cerr << "Error in MuseRecord::addAdditionalNotation: "
			  << "no empty space for notation" << endl;
		return 0;
	}

	if ((blank <= 32) && (getColumn(33) == ' ')) {
		// avoid putting non-tie items in column 32.
		blank = 33;
	}

	getColumn(blank) = symbol;
	return blank;
}