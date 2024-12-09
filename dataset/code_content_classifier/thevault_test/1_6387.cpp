std::string percent_encoded(const std::string& s) {
	std::vector<char> encoded(s.length() * 3 + 1, 0);
	char* pos = &encoded[0];
	for (size_t i = 0; i < s.length(); ++i) {
		std::sprintf(pos, "%%%02X", s[i]);
		pos += 3;
	}
	return std::string(encoded.begin(), encoded.end() - 1);
}