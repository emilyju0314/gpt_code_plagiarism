int hasVisualAccidental(HTp token, int subtoken) {
	int acc = token->hasVisibleAccidental(subtoken);
	if (!acc) {
		return 0;
	}
	string tstring = token->getSubtoken(subtoken);
	if (tstring.find("--") != std::string::npos) {
		return 1;
	}
	if (tstring.find("-") != std::string::npos) {
		return 2;
	}
	if (tstring.find("##") != std::string::npos) {
		return 5;
	}
	if (tstring.find("#") != std::string::npos) {
		return 4;
	}
	return 3;
}