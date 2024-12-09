size_t ClientHandler::find(std::vector<std::string> vec, std::string str) {
	for (size_t i = 0; i < vec.size(); ++i)
		if (vec[i].substr(0, vec[i].find_last_of(".")) == str) return i;
	return vec.size();
}