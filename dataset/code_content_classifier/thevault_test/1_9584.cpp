int MuseRecord::getGraphicNoteTypeSize(void) {
	int output = 1;
	string recordInfo = getGraphicNoteTypeField();
	if (recordInfo[0] == ' ') {
		cerr << "Error: not graphic note specified in column 17: "
			  << getLine() << endl;
		return 0;
	}

	switch (recordInfo[0]) {
		case 'L': case 'b': case 'w': case 'h': case 'q': case 'e':
		case 's': case 't': case 'x': case 'y': case 'z':
			output = 1;
			break;
		case 'B': case 'A': case '9': case '8': case '7': case '6':
		case '5': case '4': case '3': case '2': case '1':
			output = 0;
			break;
		default:
			cerr << "Error: unknown graphical note type in column 17: "
				  << getLine() << endl;
			return 0;
	}

	return output;
}