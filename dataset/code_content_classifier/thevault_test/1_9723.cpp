string HumRegex::replaceCopy(const string& input, const string& exp,
		const string& replacement, const string& options) {
	m_regex = regex(exp, getTemporaryRegexFlags(options));
	string output;
	regex_replace(std::back_inserter(output), input.begin(),
			input.end(), m_regex, replacement, getTemporarySearchFlags(options));
	return output;
}