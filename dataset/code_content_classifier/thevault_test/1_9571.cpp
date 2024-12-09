string MuseRecord::getTickDurationString(void) {
	string output = getTickDurationField();
	int length = (int)output.size();
	int i = length - 1;
	while (i>0 && (output[i] == '-' || output[i] == ' ')) {
		output.resize(i);
		i--;
		length--;
	}

	int start = 0;
	while (output[start] == ' ') {
		start++;
	}

	if (start != 0) {
		for (i=0; i<length-start; i++) {
			output[i] = output[start+i];
		}
	}
	output.resize(length-start);

	return output;
}