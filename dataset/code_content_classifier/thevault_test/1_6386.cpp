std::string percent_encoded(char c) {
	char encoded[4]; // '%', two hex digits, and NULL character
	std::sprintf(encoded, "%%%02X", c);
	return std::string(encoded, 3);
}