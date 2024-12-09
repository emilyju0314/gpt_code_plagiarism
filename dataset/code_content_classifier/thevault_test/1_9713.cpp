string Convert::mensToRecip(char rhythm, bool altera, bool perfecta, bool imperfecta,
		int maximodus, int modus, int tempus, int prolatio) {

	double minim_units;


	double maxima_def = 16;
	double longa_def = 8;
	double brevis_def = 4;
	double semibrevis_def = 2;
	double minima_def = 1;
	double semiminima_def = 0.5;
	double fusa_def = 0.25;
	double semifusa_def = 0.125;

	prolatio  = prolatio  == 2 ? 2 : 3;
	tempus    = tempus    == 2 ? 2 : 3;
	modus     = modus     == 2 ? 2 : 3;
	maximodus = maximodus == 2 ? 2 : 3;

	semibrevis_def = prolatio;
	brevis_def     = semibrevis_def * tempus;
	longa_def      = brevis_def     * modus;
	maxima_def     = longa_def      * maximodus;

	if (rhythm == 'X') {
		if (perfecta) { minim_units = longa_def * 3; }
		else if (imperfecta) { minim_units = longa_def * 2; }
		else { minim_units = maxima_def; }
	}
	else if (rhythm == 'L') {
		if (perfecta) { minim_units = brevis_def * 3; }
		else if (imperfecta) { minim_units = brevis_def * 2; }
		else if (altera) { minim_units = longa_def * 2; }
		else { minim_units = longa_def; }
	}
	else if (rhythm == 'S') {
		if (perfecta) { minim_units = semibrevis_def * 3; }
		else if (imperfecta) { minim_units = semibrevis_def * 2; }
		else if (altera) { minim_units = brevis_def * 2; }
		else { minim_units = brevis_def; }
	}
	else if (rhythm == 's') {
		if (perfecta) { minim_units = minima_def * 3; }
		else if (imperfecta) { minim_units = minima_def * 2; }
		else if (altera) { minim_units = semibrevis_def * 2; }
		else { minim_units = semibrevis_def; }
	}
	else if (rhythm == 'M') {
		if (perfecta) { minim_units = minima_def * 3 / 2; }
		else if (altera) { minim_units = minima_def * 2; }
		else { minim_units = minima_def; }
	}
	else if (rhythm == 'm') {
		if (perfecta) { minim_units = semiminima_def * 3 / 2; }
		else { minim_units = semiminima_def; }
	}
	else if (rhythm == 'U') {
		if (perfecta) { minim_units = fusa_def * 3 / 2; }
		else { minim_units = fusa_def; }
	}
	else if (rhythm == 'u') {
		if (perfecta) { minim_units = semifusa_def * 3 / 2; }
		else { minim_units = semifusa_def; }
	}
	else { cerr << "UNKNOWN RHYTHM: " << rhythm << endl; return ""; }

	switch ((int)(minim_units * 10000)) {
		case 1250:     return "16";   break;   // sixteenth note
		case 1875:     return "16.";  break;   // dotted sixteenth note
		case 2500:     return "8";    break;   // eighth note
		case 3750:     return "8.";   break;   // dotted eighth note
		case 5000:     return "4";    break;   // quarter note
		case 7500:     return "4.";   break;   // dotted quarter note
		case 10000:    return "2";    break;   // half note
		case 15000:    return "2.";   break;   // dotted half note
		case 20000:    return "1";    break;   // whole note
		case 30000:    return "1.";   break;   // dotted whole note
		case 40000:    return "0";    break;   // breve note
		case 60000:    return "0.";   break;   // dotted breve note
		case 90000:    return "2%9";  break;   // or ["0.", "1."]; 
		case 80000:    return "00";   break;   // long note
		case 120000:   return "00.";  break;   // dotted long note 
		case 180000:   return "1%9";  break;   // or ["00.", "0."];
		case 270000:   return "2%27"; break;   // or ["0.", "1.", "0.", "1.", "0.", "1."];
		case 160000:   return "000";  break;   // maxima note
		case 240000:   return "000."; break;   // dotted maxima note
		case 360000:   return "1%18"; break;   // or ["000.", "00."];
		case 540000:   return "1%27"; break;   // or ["00.", "0.", "00.", "0.", "00.", "0."];
		case 810000:   return "2%81"; break;   // or ["00.", "0.", "00.", "0.", "00.", "0.", "0.", "1.", "0.", "1.", "0.", "1."];
		default:
			cerr << "Error: unknown minim_units: " << minim_units << endl;
	}

	return "";
}