string HumTransposer::diatonicChromaticToIntervalName(int diatonic, int chromatic) {
	if (diatonic == 0) {
		string output;
		if (chromatic == 0) {
			output += "P";
		}
		else if (chromatic > 0) {
			for (int i = 0; i < chromatic; i++) {
				output += "A";
			}
		}
		else {
			for (int i = 0; i < -chromatic; i++) {
				output += "d";
			}
		}
		output += "1";
		return output;
	}

	int octave = 0;
	string direction;
	if (diatonic < 0) {
		direction = "-";
		octave = -diatonic / 7;
		diatonic = (-diatonic - octave * 7);
		chromatic = -chromatic;
	}
	else {
		octave = diatonic / 7;
		diatonic = diatonic - octave * 7;
	}

	int augmented = 0;
	int diminished = 0;
	string quality;

	switch (abs(diatonic)) {
		case 0: // unsion
			if (chromatic == 0) {
				quality = "P";
			}
			else if (chromatic > 0) {
				augmented = chromatic;
			}
			else {
				diminished = chromatic;
			}
			break;
		case 1: // second
			if (chromatic == 2) {
				quality = "M";
			}
			else if (chromatic == 1) {
				quality = "m";
			}
			else if (chromatic > 2) {
				augmented = chromatic - 2;
			}
			else {
				diminished = chromatic - 1;
			}
			break;
		case 2: // third
			if (chromatic == 4) {
				quality = "M";
			}
			else if (chromatic == 3) {
				quality = "m";
			}
			else if (chromatic > 4) {
				augmented = chromatic - 4;
			}
			else {
				diminished = chromatic - 3;
			}
			break;
		case 3: // fourth
			if (chromatic == 5) {
				quality = "P";
			}
			else if (chromatic > 5) {
				augmented = chromatic - 5;
			}
			else {
				diminished = chromatic - 5;
			}
			break;
		case 4: // fifth
			if (chromatic == 7) {
				quality = "P";
			}
			else if (chromatic > 7) {
				augmented = chromatic - 7;
			}
			else {
				diminished = chromatic - 7;
			}
			break;
		case 5: // sixth
			if (chromatic == 9) {
				quality = "M";
			}
			else if (chromatic == 8) {
				quality = "m";
			}
			else if (chromatic > 9) {
				augmented = chromatic - 9;
			}
			else {
				diminished = chromatic - 8;
			}
			break;
		case 6: // seventh
			if (chromatic == 11) {
				quality = "M";
			}
			else if (chromatic == 10) {
				quality = "m";
			}
			else if (chromatic > 11) {
				augmented = chromatic - 11;
			}
			else {
				diminished = chromatic - 10;
			}
			break;
	}

	augmented = abs(augmented);
	diminished = abs(diminished);

	if (quality.empty()) {
		if (augmented) {
			for (int i = 0; i < augmented; i++) {
				quality += "A";
			}
		}
		else if (diminished) {
			for (int i = 0; i < diminished; i++) {
				quality += "d";
			}
		}
	}

	return direction + quality + to_string(octave * 7 + diatonic + 1);
}