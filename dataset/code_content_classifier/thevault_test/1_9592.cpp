string MuseRecord::getEditorialLevels(void) {
	string output;
	string addString = getAdditionalNotationsField();
	for (int index = 0; index < 12-1; index++) {
		if (addString[index] == '&' && isalnum(addString[index+1])) {
			output += addString[index+1];
		}
	}
	return output;
}