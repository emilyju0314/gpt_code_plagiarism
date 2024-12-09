void Tool_esac2hum::getLyrics(vector<string>& lyrics, const string& buffer) {
	lyrics.resize(0);
	int zero1 = 0;
	string current;
	int zero2 = 0;
	zero2 = zero1 + zero2;

	int length = (int)buffer.size();
	int i;

	i = 0;
	while (i<length) {
		current = "";
		if (buffer[i] == ' ') {
			current = ".";
			lyrics.push_back(current);
			i++;
			continue;
		}

		while (i < length && buffer[i] != ' ') {
			current += buffer[i++];
		}
		lyrics.push_back(current);
		i++;
	}

}