Json::Value toJSON(const std::map<std::string, std::string>& map) {
		Json::Value result;
		for (auto obj : map) {
			result[obj.first] = cleanString(obj.second);
		}
		return result;
	}