string format_cell(double val, int spaceLeft) {
	char padDec = ' ';
	if (PAD_ZERO) padDec = '0';
	string result = ""; //this our final result
	string data = to_string_ex(val); //let's get a string representation of the double first.

	int dPos = data.find_first_of('.'); //this gives us the position of the decimal point, as well as the amount of whole numbers
	int dCount = data.length() - (dPos + 1); //number of decimal points

	//we check if there is too much data to the left of the string representation
	if (dPos > spaceLeft) {
		//if it is, we simply clip it
		result = "~" + data.substr(dPos - spaceLeft + 1, data.length() - (dPos - spaceLeft + 1));
	}
	else {
		//if it is not, we pad it to match the allotted space
		for (int i = 0; i < spaceLeft - dPos; ++i) result += " ";
		result = result + data;
	}

	//we check if the number of decimals are lesser than the max
	if (dCount < MAX_DECIMALS) {
		//if it does, we pad the right side of the string to meet the desired cell length
		for (int i = 0; i < MAX_DECIMALS - dCount; ++i) result += padDec;
	}

	//return our final result
	return result;
}