int MuseRecord::getNoteTickDuration(void) {
	string recordInfo = getTickDurationString();
	int value = 0;
	if (recordInfo.empty()) {
		return value;
	}
	value = std::stoi(recordInfo);
	if (getType() == E_muserec_backspace) {
		return -value;
	}
	return value;
}