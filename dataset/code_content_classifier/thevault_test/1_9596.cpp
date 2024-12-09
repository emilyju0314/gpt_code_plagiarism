int MuseRecord::measureFermataQ(void) {
	int output = 0;
	for (int i=17; i<=80 && i<= getLength(); i++) {
		if (getColumn(i) == 'F' || getColumn(i) == 'E') {
			output = 1;
			break;
		}
	}
	return output;
}