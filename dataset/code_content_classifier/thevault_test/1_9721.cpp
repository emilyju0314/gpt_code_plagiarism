double HumRegex::getMatchDouble(int index) {
	string value = m_matches.str(index);
	if (value.size() > 0) {
		return stod(value);
	} else {
		return 0.0;
	}
}