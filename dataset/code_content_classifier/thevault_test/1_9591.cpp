int MuseRecord::getAddItemLevel(int elementIndex) {
	int count = 0;
	int index = 0;
	string number;
	string addString = getAdditionalNotationsField();
	string elementString; // element field

	while (count < elementIndex) {
		getAddElementIndex(index, elementString, addString);
		count++;
	}

	int output = -1;
repeating:
	while (addString[index] != '&' && index >= 0) {
		index--;
	}
	if (addString[index] == '&' && !isalnum(addString[index+1])) {
		index--;
		goto repeating;
	} else if (addString[index] == '&') {
		number = addString[index+1];
		output = (int)strtol(number.c_str(), NULL, 36);
	}

	return output;
}