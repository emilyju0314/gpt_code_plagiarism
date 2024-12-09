string HumRegex::getMatch(int index) {
	if (index < 0) {
		return "";
	} if (index >= (int)m_matches.size()) {
		return "";
	}
	string output = m_matches.str(index);
	return output;
}