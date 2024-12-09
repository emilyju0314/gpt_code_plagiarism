int HumRegex::getMatchInt(int index) {
	string value = m_matches.str(index);
	int output = 0;
	if (value.size() > 0) {
		if (isdigit(value[0])) {
			output = std::stoi(value);
		} else if (value[0] == '-') {
			output = std::stoi(value);
		} else if (value[0] == '+') {
			output = std::stoi(value);
		}
	}
	return output;
}