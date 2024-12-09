int MuseRecord::getTicks(void) {
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