string MuseRecord::getNoteField(void) {
	switch (getType()) {
		case E_muserec_note_regular:
			return extract(1, 4);
			break;
		case E_muserec_note_chord:
		case E_muserec_note_cue:
		case E_muserec_note_grace:
			return extract(2, 5);
			break;
		default:
			cerr << "Error: cannot use getNoteField function on line: "
			   << getLine() << endl;
	}
	return "";
}