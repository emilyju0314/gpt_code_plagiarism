int MuseRecord::getLineTickDuration(void) {
	if (getType() == E_muserec_note_chord) {
		return 0;
	}

	string recordInfo = getTickDurationString();
	if (recordInfo.empty()) {
		return 0;
	}
	int value = std::stoi(recordInfo);
	if (getType() == E_muserec_backspace) {
		return -value;
	}

	return value;
}