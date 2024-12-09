int MuseRecord::findField(const string& key) {
	int len = (int)key.size();
	string notations = getAdditionalNotationsField();
	int output = 0;
	for (int i=0; i<12-len; i++) {
		if (notations[i] == key[0]) {
			output = 1;
			for (int j=0; j<len; j++) {
				if (notations[i] != key[j]) {
					output = 0;
					goto endofloop;
				}
			}
		}

		if (output == 1) {
			break;
		}
endofloop:
	;
	}

	return output;
}