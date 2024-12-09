string MuseRecord::getNotatedAccidentalField(void) {
	allowNotesOnly("getNotatedAccidentalField");
	if (getLength() < 19) {
		return " ";
	} else {
		string temp;
		temp += getColumn(19);
		return temp;
	}
}