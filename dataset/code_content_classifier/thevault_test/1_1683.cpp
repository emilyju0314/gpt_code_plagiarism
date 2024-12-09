void EEPROMWearLevel::programZeroBitsToZero(int index, byte byteWithZeros) {
	byte mask = 1;
	int bitPosInByte = 7;
	// do while bit still in mask
	while (mask != 0) {
		if ((byteWithZeros & mask) == 0) {
			fakeEeprom[index] &= ~(1 << (7 - bitPosInByte));
		}
		mask <<= 1;
		bitPosInByte--;
	}
}