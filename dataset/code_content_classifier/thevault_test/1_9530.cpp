int Convert::base7ToBase40(int base7) {
	int octave = base7 / 7;
	int b7pc = base7 % 7;
	int b40pc = 0;
	switch (b7pc) {
		case 0: b40pc =  0; break; // C
		case 1: b40pc =  6; break; // D
		case 2: b40pc = 12; break; // E
		case 3: b40pc = 17; break; // F
		case 4: b40pc = 23; break; // G
		case 5: b40pc = 29; break; // A
		case 6: b40pc = 35; break; // B
	}
	return octave * 40 + 2 + b40pc;
}