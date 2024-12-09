HumNum Convert::timeSigToDurationInQuarter(HTp token) {
	HumRegex hre;
	if (!token->isTimeSignature()) {
		return 0;
	}
	// Handle extended **recip for denominator later...
	if (!hre.search(token, "^\\*M(\\d+)/(\\d+)")) {
		return 0;
	}
	int top = hre.getMatchInt(1);
	int bot = hre.getMatchInt(2);
	HumNum output = 4;
	output /= bot;
	output *= top;
	return output;
}