void MuseRecord::setPitch(int base40, int chordnote, int gracenote) {
	string diatonic;
	switch (Convert::base40ToDiatonic(base40) % 7) {
		case 0:  diatonic = 'C'; break;
		case 1:  diatonic = 'D'; break;
		case 2:  diatonic = 'E'; break;
		case 3:  diatonic = 'F'; break;
		case 4:  diatonic = 'G'; break;
		case 5:  diatonic = 'A'; break;
		case 6:  diatonic = 'B'; break;
		default: diatonic = 'X';
	}

	string octave;
	octave  += char('0' + base40 / 40);

	string accidental;
	int acc = Convert::base40ToAccidental(base40);
	switch (acc) {
		case -2:   accidental = "ff"; break;
		case -1:   accidental = "f";  break;
		case +1:   accidental = "#";  break;
		case +2:   accidental = "##"; break;
	}
	string pitchname = diatonic + accidental + octave;

	if (chordnote) {
		if (gracenote) {
			setGraceChordPitch(pitchname);
		} else {
			setChordPitch(pitchname);
		}
	} else {
		setPitch(pitchname);
	}
}