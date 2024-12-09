int MuseRecord::getAttributeField(string& value, const string& key) {
	switch (getType()) {
		case E_muserec_musical_attributes:
			break;
		default:
			cerr << "Error: cannot use getAttributeInt function on line: "
				  << getLine() << endl;
			return 0;
	}

	int returnValue = 0;
	int ending = 0;
	int index = 0;
	int tempcol;
	int column;
	for (column=4; column <= getLength(); column++) {
		if (getColumn(column) == ':') {
			tempcol = column - 1;
			while (tempcol > 0 && getColumn(tempcol) != ' ') {
				tempcol--;
			}
			tempcol++;
			while (tempcol <= column) {
				if (getColumn(tempcol) == key[0]) {
					ending = 2;
				} else if (getColumn(tempcol) == 'D') {
					ending = 1;
				}
				tempcol++;
				index++;
			}
		}
		if (ending) {
			break;
		}
	}

	value.clear();
	if (ending == 0 || ending == 1) {
		return returnValue;
	} else {
		returnValue = 1;
		column++;
		while (getColumn(column) != ' ') {
			value += getColumn(column++);
		}
		return returnValue;
	}
}