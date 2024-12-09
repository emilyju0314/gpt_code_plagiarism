string Convert::kernToScientificPitch(const string& kerndata,
		string flat, string sharp, string separator) {
	vector<string> subtokens = Convert::splitString(kerndata);
	string output;

	for (int i=0; i<(int)subtokens.size(); i++) {
		char diatonic   = Convert::kernToDiatonicUC(subtokens[i]);
		int accidental = Convert::kernToAccidentalCount(subtokens[i]);
		int octave     = Convert::kernToOctaveNumber(subtokens[i]);
		if ((i > 0) && (i < (int)subtokens.size()-1)) {
			output += " ";
		}
		output += diatonic;
		for (int j=0; j<abs(accidental); j++) {
			output += (accidental < 0 ? flat : sharp);
		}
		output += separator;
		output += to_string(octave);
	}

	return output;
}