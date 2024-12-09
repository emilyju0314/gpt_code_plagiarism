std::vector<std::string> StringUtils::split(const std::string& s,
		const std::string& delimiters) {
	std::vector<std::string> tokens;
	std::set<char> delim(delimiters.begin(), delimiters.end());
	int last = 0;
	for ( int i = 0; i <= (int)s.size(); ++i ) {
		if ( i == (int)s.size() || delim.find(s[i]) != delim.end() ) {
			if(i-last >= 1)
				tokens.push_back(std::string(s.begin()+last, s.begin()+i));
			last = i+1;
		}
	}
	return tokens;
}