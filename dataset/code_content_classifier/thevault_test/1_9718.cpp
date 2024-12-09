int HumRegex::search(const string& input, const string& exp,
		const string& options) {
	m_regex = regex(exp, getTemporaryRegexFlags(options));
	bool result = regex_search(input, m_matches, m_regex, getTemporarySearchFlags(options));
	if (!result) {
		return 0;
	} else if (m_matches.size() < 1) {
		return 0;
	} else {
		return (int)m_matches.position(0) + 1;
	}
}