string MuseRecord::getAddItem(int elementIndex) {
	string output;
	int count = 0;
	int index = 0;
	string addString = getAdditionalNotationsField();

	while (count <= elementIndex) {
		getAddElementIndex(index, output, addString);
		count++;
	}

	return output;
}