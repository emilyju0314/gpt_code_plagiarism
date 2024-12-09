vector<string> split(string str, char delimiter) {
	vector<string> inputHashValue;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		inputHashValue.push_back(tok);
	}

	return inputHashValue;
}