std::vector<std::string> ClientHandler::findDeps(std::string str) {
	std::vector<std::string> vect;
	bool ver = false;
	std::istringstream ss(str);
	std::string token;
	while (std::getline(ss, token, ','))
	{
		size_t posVer = token.find_last_of("."); // check if user has specified the version number
		if (posVer < token.length() - 4) // if not, the file depends on the first version
			if (token.substr(posVer + 1, 3) == "ver") ver = true;
		if(!ver) vect.push_back(token + ".ver1");
		else vect.push_back(token);
	}
	return vect;
}