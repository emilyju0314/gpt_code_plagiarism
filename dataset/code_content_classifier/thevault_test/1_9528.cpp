int Convert::pitchToWbh(int dpc, int acc, int octave, int maxacc) {
	if (dpc > 6) {
		// allow for pitch-classes expressed as ASCII characters:
		dpc = tolower(dpc) - 'a' + 5;
		dpc = dpc % 7;
	}
	int output = -1000;
	switch (dpc) {
		case 0: output = maxacc;            break;
		case 1: output =  3  * maxacc + 2;  break;
		case 2: output =  5  * maxacc + 4;  break;
		case 3: output =  7  * maxacc + 5;  break;
		case 4: output =  9  * maxacc + 7;  break;
		case 5: output =  11 * maxacc + 9;  break;
		case 6: output =  13 * maxacc + 11; break;
	}
	if (output < 0) {
		return output;
	}
	return (output + acc) + (7 * (maxacc * 2 + 1) + 5) * octave;
}