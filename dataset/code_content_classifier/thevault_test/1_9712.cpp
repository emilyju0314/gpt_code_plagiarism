HumNum Convert::mensToDurationNoDots(const string& mensdata, HumNum scale,
		const string& separator) {
	HumNum output(0);

	for (int i=0; i<(int)mensdata.size(); i++) {
		switch (mensdata[i]) {
			case 'X': output = 8; break;              // octuple whole note
			case 'L': output = 4; break;              // quadruple whole note
			case 'S': output = 2; break;              // double whole note
			case 's': output = 1; break;              // whole note
			case 'M': output.setValue(1, 2);  break;  // half note
			case 'm': output.setValue(1, 4);  break;  // quarter note
			case 'U': output.setValue(1, 8);  break;  // eighth note
			case 'u': output.setValue(1, 16); break;  // sixteenth note
		}
		if (mensdata.compare(i, separator.size(), separator) == 0) {
			// only get duration of first note in chord
			break;
		}
	}
	output *= scale;

	return output;
}