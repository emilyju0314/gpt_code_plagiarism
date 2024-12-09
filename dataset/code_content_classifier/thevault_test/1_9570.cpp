string MuseRecord::getTickDurationField(void) {
	switch (getType()) {
		case E_muserec_figured_harmony:
		case E_muserec_note_regular:
		case E_muserec_note_chord:
		case E_muserec_rest:
		case E_muserec_backward:
		case E_muserec_forward:
			return extract(6, 9);
			break;
		// these record types do not have duration, per se:
		case E_muserec_note_cue:
		case E_muserec_note_grace:
		default:
			return "    ";
			// cerr << "Error: cannot use getTickDurationField function on line: "
			//      << getLine() << endl;
			// return "";
	}
	return "";
}