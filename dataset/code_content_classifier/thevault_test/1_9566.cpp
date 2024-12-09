int Convert::romanNumeralToInteger(const string& roman) {
	int rdigit;
	int sum = 0;
	char previous='_';
	for (int i=(int)roman.length()-1; i>=0; i--) {
		switch (roman[i]) {
			case 'I': case 'i': rdigit =    1; break;
			case 'V': case 'v': rdigit =    5; break;
			case 'X': case 'x': rdigit =   10; break;
			case 'L': case 'l': rdigit =   50; break;
			case 'C': case 'c': rdigit =  100; break;
			case 'D': case 'd': rdigit =  500; break;
			case 'M': case 'm': rdigit = 1000; break;
			default:  rdigit =   -1;
		}
		if (rdigit < 0) {
			continue;
		} else if (rdigit < sum && (roman[i] != previous)) {
			sum -= rdigit;
		} else {
			sum += rdigit;
		}
		previous = roman[i];
	}

	return sum;
}