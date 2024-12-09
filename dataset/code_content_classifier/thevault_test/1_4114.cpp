string to_string_ex(double val) {
	// Create our initial string representation.
	string temp = to_string(val);

	// Find the position of the decimal point.
	int dec = temp.find_first_of('.');

	// If it does not exist, it means we have a whole number.
	if (dec == string::npos)
	{
		//We add ".0" to the end for style and formatting consistency.
		temp = temp + ".0";
	}
	else {
		// If the number is a fraction.
		// Get the number of decimal points via the difference of the position of the point and the length.
		dec = temp.length() - dec - 1;

		// Check if the number of points is greater than the allowed max.
		if (dec > MAX_DECIMALS) {
			// If so, delete the excess points.
			temp.erase(temp.length() - (dec - MAX_DECIMALS));
		}

		// Remove trailing zeros.
		temp.erase(temp.find_last_not_of('0') + 1, string::npos);
	}

	// Last check for orphaned decimal points, add zero if needed.
	if (temp[temp.length() - 1] == '.') temp = temp + '0';
	return temp;
}