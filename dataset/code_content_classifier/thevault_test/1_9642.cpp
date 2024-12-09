int HumTransposer::semitonesToIntervalClass(int keyFifths, int semitones) {
	int sign = semitones < 0 ? -1 : +1;
	semitones = semitones < 0 ? -semitones : semitones;
	int octave = semitones / 12;
	semitones = semitones - octave * 12;
	int sum1, sum2;
	string interval = "P1";
	switch (semitones) {
		case 0: interval = "P1"; break;

		case 1:
			sum1 = keyFifths - 5 * sign;
			sum2 = keyFifths + 7 * sign;
			interval = abs(sum1) < abs(sum2) ? "m2" : "A1";
			break;

		case 2:
			sum1 = keyFifths + 2 * sign;
			sum2 = keyFifths - 10 * sign;
			interval = abs(sum1) < abs(sum2) ? "M2" : "d3";
			break;

		case 3:
			sum1 = keyFifths - 3 * sign;
			sum2 = keyFifths + 9 * sign;
			interval = abs(sum1) < abs(sum2) ? "m3" : "A2";
			break;

		case 4:
			sum1 = keyFifths + 4 * sign;
			sum2 = keyFifths - 8 * sign;
			interval = abs(sum1) < abs(sum2) ? "M3" : "d4";
			break;

		case 5:
			sum1 = keyFifths - 1 * sign;
			sum2 = keyFifths + 11 * sign;
			interval = abs(sum1) < abs(sum2) ? "P4" : "A3";
			break;

		case 6:
			sum1 = keyFifths + 6 * sign;
			sum2 = keyFifths - 6 * sign;
			interval = abs(sum1) < abs(sum2) ? "A4" : "d5";
			break;

		case 7:
			sum1 = keyFifths + 1 * sign;
			sum2 = keyFifths - 11 * sign;
			interval = abs(sum1) < abs(sum2) ? "P5" : "d6";
			break;

		case 8:
			sum1 = keyFifths - 4 * sign;
			sum2 = keyFifths + 8 * sign;
			interval = abs(sum1) < abs(sum2) ? "m6" : "A5";
			break;

		case 9:
			sum1 = keyFifths + 3 * sign;
			sum2 = keyFifths - 9 * sign;
			interval = abs(sum1) < abs(sum2) ? "M6" : "d7";
			break;

		case 10:
			sum1 = keyFifths - 2 * sign;
			sum2 = keyFifths + 10 * sign;
			interval = abs(sum1) < abs(sum2) ? "m7" : "A6";
			break;

		case 11:
			sum1 = keyFifths + 5 * sign;
			sum2 = keyFifths - 7 * sign;
			interval = abs(sum1) < abs(sum2) ? "M7" : "d8";
			break;
	}

	interval = sign < 0 ? "-" + interval : "+" + interval;
	int intint = getInterval(interval);
	intint += sign * octave * m_base;
	return intint;
}