string Convert::base40ToKern(int b40) {
	int octave     = b40 / 40;
	int accidental = Convert::base40ToAccidental(b40);
	int diatonic   = Convert::base40ToDiatonic(b40) % 7;
	char base = 'a';
	switch (diatonic) {
		case 0: base = 'c'; break;
		case 1: base = 'd'; break;
		case 2: base = 'e'; break;
		case 3: base = 'f'; break;
		case 4: base = 'g'; break;
		case 5: base = 'a'; break;
		case 6: base = 'b'; break;
	}
	if (octave < 4) {
		base = toupper(base);
	}
	int repeat = 0;
	if (octave > 4) {
		repeat = octave - 4;
	} else if (octave < 3) {
		repeat = 3 - octave;
	}
	if (repeat > 12) {
		cerr << "Error: unreasonable octave value: " << octave << " for " << b40 << endl;
		exit(1);
	}
	string output;
	output += base;
	for (int i=0; i<repeat; i++) {
		output += base;
	}
	if (accidental == 0) {
		return output;
	}
	if (accidental > 0) {
		for (int i=0; i<accidental; i++) {
			output += '#';
		}
	} else if (accidental < 0) {
		for (int i=0; i<-accidental; i++) {
			output += '-';
		}
	}

	return output;
}