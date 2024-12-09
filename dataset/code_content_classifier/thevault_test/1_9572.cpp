int MuseRecord::getTickDuration(void) {
	string recordInfo = getTickDurationString();
	if (recordInfo.empty()) {
		return 0;
	}
	return std::stoi(recordInfo);
}