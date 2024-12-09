void tokenizeArguments (std::string str, std::vector<std::string> &args) {
		size_t offset = 0;
		size_t len = str.length();
		size_t index = 0;
		while (offset < len) {
			auto pos = str.find(",", offset);
			if (pos == std::string::npos) {
				break;
			}
			auto part = str.substr(index, pos - index);
			if (bracesMatch(part)) {
				// matching braces
				part = trim(part);
				args.push_back(part);
				index = pos + 1;
			}
			offset = pos + 1;
		}
		auto remaining = str.substr(index);
		if (!remaining.empty()) {
			remaining = trim(remaining);
			if (!bracesMatch(remaining) && remaining.at(remaining.length()-1) == (int)')') {
				remaining = remaining.substr(0, remaining.length() - 1);
			}
			args.push_back(remaining);
		}
	}