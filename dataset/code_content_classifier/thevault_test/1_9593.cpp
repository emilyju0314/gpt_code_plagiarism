int MuseRecord::addEditorialLevelQ(void) {
	string addString = getAdditionalNotationsField();
	int output = 0;
	for (int i=0; i<12-1; i++) {   // minus one for width 2 (&0)
		if (addString[i] == '&' && isalnum(addString[i+1])) {
			output = 1;
		}
	}
	return output;
}