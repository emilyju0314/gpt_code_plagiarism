bool MuseRecord::isTextDirection(void) {
	string typefield = getDirectionTypeField();
	if (typefield.find('B') != string::npos) {
		return true;
	}
	if (typefield.find('C') != string::npos) {
		return true;
	}
	if (typefield.find('D') != string::npos) {
		return true;
	}
	return false;
}