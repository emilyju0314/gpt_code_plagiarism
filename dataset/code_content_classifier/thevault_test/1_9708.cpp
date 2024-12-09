int MuseRecordBasic::isTied(void) {
	int output = 0;
	if (getLastTiedNoteLineIndex() >= 0) {
		output += 1;
	}

	if (getNextTiedNoteLineIndex() >= 0) {
		output += 2;
	}

	return output;
}