std::string filterEncoding (const std::string &encoding) {
		if (!encoding.empty() && encoding.at(0) == 'r') {
			return encoding.substr(1);
		}
		return encoding;
	}