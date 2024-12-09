int MuseRecord::measureFlagQ(const string& key) {
	int output = 0;
	int len = (int)key.size();
	for (int i=17; i<=80-len && i<getLength(); i++) {
		if (getColumn(i) == key[0]) {
			output = 1;
			for (int j=0; j<len; j++) {
				if (getColumn(i+j) != key[j]) {
					output = 0;
					break;
				}
			}
			if (output == 1) {
				break;
			}
		}
	}
	return output;
}