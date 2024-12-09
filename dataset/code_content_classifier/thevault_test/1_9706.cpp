void MuseRecordBasic::insertStringRight(int column, const string& strang) {
	int len = (int)strang.size();
	int index = column - 1;
	// make sure that record has text data up to the end of sring in
	// final location by preallocating the end location of string:
	(*this)[index] = ' ';
	int i;
	int ii;
	for (i=0; i<len; i++) {
		ii = index - i;
		if (ii < 0) {
			break;
		}
		(*this)[ii] = strang[len-i-1];
	}
}