inline std::string ltrim_ws(const std::string s, const char* t = whitespace) {
		std::string _s = s;
		_s.erase(0, _s.find_first_not_of(t));
		return _s;
	}