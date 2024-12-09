int EEPROMWearLevel::findControlByteIndex(const int startIndex, const int length) {
	const int endIndex = startIndex + length - 1;
	int lowerBound = startIndex;
	int upperBound = endIndex;
	int midPoint = -1;

	byte currentByte = 0xFF;
	while (lowerBound <= upperBound) {
		// compute the mid point
		midPoint = lowerBound + (upperBound - lowerBound) / 2;

		currentByte = readByte(midPoint);
		if (currentByte != 0 && currentByte != 0xFF) {
			// searched control byte found because it is neigher 0 nor 0xFF what means
			// that some of its bits are in use, some not
			return midPoint;
		} else {
			if (currentByte == 0) {
				// searched control byte is in upper half
				lowerBound = midPoint + 1;
			} else {
				// searched control byte is in lower half
				upperBound = midPoint - 1;
			}
		}
	}

	if (currentByte == 0) {
		// searched control byte is above
		int controlByteIndex = midPoint;
		while (currentByte == 0 && controlByteIndex < endIndex) {
			controlByteIndex++;
			currentByte = readByte(controlByteIndex);
		}
		return controlByteIndex;
	} else {
		// currentByte == 0xff so searched control byte is below
		int controlByteIndex = midPoint;
		while (currentByte == 0xFF && controlByteIndex >= startIndex) {
			controlByteIndex--;
			currentByte = readByte(controlByteIndex);
		}
		// we want the byte where all bits are still set
		// except when it is the last one.
		if (controlByteIndex >= endIndex) {
			// do not go to next because it is the last one
			return controlByteIndex;
		} else {
			// go to next as current control byte is 0
			return controlByteIndex + 1;
		}
	}
}