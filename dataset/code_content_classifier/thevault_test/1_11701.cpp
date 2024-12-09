std::vector<std::string> ClientHandler::splitString(std::string str) {
	std::vector<std::string> vect;
	std::istringstream ss(str);
	std::string token;
	while (std::getline(ss, token, ',')) vect.push_back(token);
	return vect;
}