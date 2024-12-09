int Convert::base40ToDiatonic(int b40) {
	int chroma = b40 % 40;
	int octaveoffset = (b40 / 40) * 7;
	if (b40 < 0) {
		return -1;   // rest;
	}
	switch (chroma) {
		case 0: case 1: case 2: case 3: case 4:      // C-- to C##
			return 0 + octaveoffset;
		case 6: case 7: case 8: case 9: case 10:     // D-- to D##
			return 1 + octaveoffset;
		case 12: case 13: case 14: case 15: case 16: // E-- to E##
			return 2 + octaveoffset;
		case 17: case 18: case 19: case 20: case 21: // F-- to F##
			return 3 + octaveoffset;
		case 23: case 24: case 25: case 26: case 27: // G-- to G##
			return 4 + octaveoffset;
		case 29: case 30: case 31: case 32: case 33: // A-- to A##
			return 5 + octaveoffset;
		case 35: case 36: case 37: case 38: case 39: // B-- to B##
			return 6 + octaveoffset;
	}

	// found an empty slot, so return rest:
	return -1;
}