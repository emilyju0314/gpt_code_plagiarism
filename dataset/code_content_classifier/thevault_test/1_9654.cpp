void Tool_autostem::setStemDirection(HumdrumFile& infile, int row, int col,
			int direction) {
	int& i = row;
	int& j = col;

	if (infile.token(i, j)->isNull()) {
		return;
	}
	if (infile.token(i, j)->isRest()) {
		return;
	}

	if (notlongQ) {
		// Don't print stems on whole notes and breves.
		// Duration units are in quarter notes.
		HumNum value = Convert::recipToDuration(*infile.token(row,col));
		double duration = value.getFloat();
		if ((duration >= 4.0) && (duration < 16.0)) {
			return;
		}
	}

	string buffer;
	string output;
	int tokencount = infile.token(i, j)->getSubtokenCount();
	for (int k=0; k<tokencount; k++) {
		buffer = infile.token(i, j, k);
		if ((!Convert::contains(buffer, '/')) &&
		    (!Convert::contains(buffer, '\\'))) {
			if (direction > 0) {
				addStem(buffer, "/");
			} else if (direction < 0) {
				addStem(buffer, "\\");
			}
		}
		output += buffer;
		output += ' ';
	}
	if (output.back() == ' ') {
		output.pop_back();
	}
	infile.token(i, j)->setText(output);
}