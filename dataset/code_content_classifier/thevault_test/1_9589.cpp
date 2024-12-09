int MuseRecord::getAddCount(void) {
	string addString = getAdditionalNotationsField();
	string addElement;    // element from the notation field

	int count = 0;
	int index = 0;
	while (getAddElementIndex(index, addElement, addString)) {
		count++;
	}

	return count;
}