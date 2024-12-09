int MuseRecord::getOctave(void) {
	string recordInfo = getNoteField();
	int index = 0;
	while ((index < (int)recordInfo.size()) && !std::isdigit(recordInfo[index])) {
		index++;
	}
	if (index >= (int)recordInfo.size()) {
		cerr << "Error: no octave specification in note field: " << recordInfo
			  << endl;
		return 0;
	}
	return recordInfo[index] - '0';
}