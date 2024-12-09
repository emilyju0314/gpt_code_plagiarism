int MuseRecord::getTrack(void) {
	int output = 1;
	string recordInfo = getTrackField();
	if (recordInfo[0] == ' ') {
		output = 0;
	} else {
		output = (int)strtol(recordInfo.c_str(), NULL, 36);
	}
	return output;
}