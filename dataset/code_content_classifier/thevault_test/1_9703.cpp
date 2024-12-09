string MuseRecordBasic::extract(int start, int end) {
	string output;
	int count = end - start + 1;
	for (int i=0; i<count; i++) {
		if (i+start <= getLength()) {
			output += getColumn(i+start);
		} else {
			output += ' ';
		}
	}
	return output;
}