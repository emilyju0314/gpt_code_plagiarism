string Convert::durationToRecip(HumNum duration, HumNum scale) {
	duration *= scale;
	if (duration.getNumerator() == 1) {
		// simple rhythm (integer divisions of the whole note)
		return to_string(duration.getDenominator());
	}
	if (duration.getDenominator() == 1) {
		if (duration.getNumerator() == 2) {
			return "0";  // breve
		} else if (duration.getNumerator() == 3) {
			return "0."; // dotted breve
		} else if (duration.getNumerator() == 4) {
			return "00";  // long
		} else if (duration.getNumerator() == 6) {
			return "00."; // dotted long
		} else if (duration.getNumerator() == 8) {
			return "000";  // maxima
		} else if (duration.getNumerator() == 12) {
			return "000."; // dotted maxima
		}
	}
	if (duration.getNumerator() == 0) {
		// grace note
		return "q";
	}

	// now decide if the rhythm can be represented simply with one dot.
	HumNum test1dot = (duration * 2) / 3;
	if (test1dot.getNumerator() == 1) {
		// single dot works
		// string output = to_string(test1dot.getDenominator() * 2);
		string output = to_string(test1dot.getDenominator());
		output += ".";
		return output;
	}

	// now decide if the rhythm can be represented simply with two dots.
	HumNum test2dot = (duration * 4) / 7;
	if (test2dot.getNumerator() == 1) {
		// double dot works
		string output = to_string(test2dot.getDenominator());
		output += "..";
		return output;
	}

	// now decide if the rhythm can be represented simply with three dots.
	HumNum test3dot = (duration * 8) / 15;
	if (test3dot.getNumerator() == 1) {
		// single dot works
		string output = to_string(test3dot.getDenominator());
		output += "...";
		return output;
	}

	// duration required more than three dots or is not simple,
	// so assume that it is not simple:
	string output = to_string(duration.getDenominator());
	output += "%";
	output += to_string(duration.getNumerator());
	return output;
}