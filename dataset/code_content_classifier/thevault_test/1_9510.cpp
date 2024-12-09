vector<string> Options::tokenizeCommandLine(const string& arguments) {
	char ch;
	int doublequote = 0;
	int singlequote = 0;

	vector<string> tokens;
	vector<string> tempargv;
	string tempvalue;

	tokens.reserve(100);
	tempargv.reserve(100);
	tempvalue.reserve(1000);

	for (int i=0; i<(int)arguments.size(); i++) {
		if (!singlequote && (arguments[i] == '"')) {
			if ((i>0) && (arguments[i-1] != '\\')) {
				doublequote = !doublequote;
				if (doublequote == 0) {
					// finished a doublequoted section of data, so store
					// even if it is the empty string
					ch = '\0';
					tempvalue += (ch);
					tokens.push_back(tempvalue);
					tempvalue.clear();
					continue;
				} else {
					// don't store the leading ":
					continue;
				}
			}
		} else if (!doublequote && (arguments[i] == '\'')) {
			if ((i>0) && (arguments[i-1] != '\\')) {
				singlequote = !singlequote;
				if (singlequote == 0) {
					// finished a singlequote section of data, so store
					// even if it is the empty string
					ch = '\0';
					tempvalue += ch;
					tokens.push_back(tempvalue);
					tempvalue.clear();
					continue;
				} else {
					// don't store the leading ":
					continue;
				}
			}
		}

		if ((!doublequote && !singlequote) && std::isspace(arguments[i])) {
			if (tempvalue.size() > 0) {
				// tempvalue += ch;
				tokens.push_back(tempvalue);
				tempvalue.clear();
			}
		} else {
			ch = arguments[i];
			tempvalue += ch;
		}
	}
	if (tempvalue.size() > 0) {
		tokens.push_back(tempvalue);
		tempvalue.clear();
	}

	return tokens;
}