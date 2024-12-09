int MuseRecord::tieQ(void) {
	int output = 0;
	switch (getType()) {
		case E_muserec_note_regular:
		case E_muserec_note_chord:
		case E_muserec_note_cue:
		case E_muserec_note_grace:
			if (getColumn(9) == '-') {
				output = 1;
			} else if (getColumn(9) == ' ') {
				output = 0;
			} else {
				output = -1;
			}
			break;
		default:
			return 0;
	}

	return output;
}