string HumRegex::replaceCopy(const string& input, const string& replacement,
		const string& exp) {
	m_regex = regex(exp, m_regexflags);
	string output;
	regex_replace(std::back_inserter(output), input.begin(),
			input.end(), m_regex, replacement);
	return output;
}