vector<string>* Split(string text) {
	vector<string>* ret = new vector<string>();
	stringstream stringBuilder;
	for (int c = 0; c < text.length(); ++c) {
		if (stringBuilder.str() != "" && text[c] == ' ') {
			//new 
			ret->push_back(stringBuilder.str());
			stringBuilder.str(string()); //clear
		}
		else {
			stringBuilder << text[c];
		}
	}
	if (stringBuilder.str() != "") {
		//new word
		ret->push_back(stringBuilder.str());
		stringBuilder.str(string()); //clear
	}
	return ret;
}