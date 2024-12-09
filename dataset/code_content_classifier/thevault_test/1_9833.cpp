Json::Value toJSON(const std::vector<std::string>& array) {
		Json::Value result;
		for (auto it = array.begin(); it != array.end(); it++) {
			auto str = *it;
			result.append(cleanString(str));
		}
		return result;
	}