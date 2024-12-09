inline std::string rtrim_ws(const std::string s, const char* t = whitespace) {
		std::string _s = s;
		_s.erase(_s.find_last_not_of(t) + 1);
		return _s;
	}