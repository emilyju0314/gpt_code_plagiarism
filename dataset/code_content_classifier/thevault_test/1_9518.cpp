void Tool_esac2hum::getLineRange(vector<string>& song, const string& field,
		int& start, int& stop) {
	string searchstring = field;;
	searchstring += "[";
	start = stop = -1;
	for (int i=0; i<(int)song.size(); i++) {
		auto loc = song[i].find(']');
		if (song[i].compare(0, searchstring.size(), searchstring) == 0) {
			start = i;
			if (loc != string::npos) {
				stop = i;
				break;
			}
		} else if ((start >= 0) && (loc != string::npos)) {
			stop = i;
			break;
		}
	}
}