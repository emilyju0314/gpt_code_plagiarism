int HumRegex::search(const string& input, const string& exp) {
	m_regex = regex(exp, m_regexflags);
	bool result = regex_search(input, m_matches, m_regex, m_searchflags);
	if (!result) {
		return 0;
	} else if (m_matches.size() < 1) {
		return 0;
	} else {
		// return the char+1 position of the first match
		return (int)m_matches.position(0) + 1;
	}
}