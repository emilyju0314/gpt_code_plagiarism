bool Tool_esac2hum::placeLyricPhrase(vector<NoteData>& songdata, vector<string>& lyrics, int line) {
	int i = 0;
	int start = 0;
	int found = 0;

	if (lyrics.empty()) {
		return true;
	}

	// find the phrase to which the lyrics belongs
	for (i=0; i<(int)songdata.size(); i++) {
		if (songdata[i].phnum == line) {
			found = 1;
			break;
		}
	}
	start = i;

	if (!found) {
		cerr << "Error: cannot find music for lyrics line " << line << endl;
		cerr << "Error near input data line: " << inputline << endl;
		return false;
	}

	for (i=0; i<(int)lyrics.size() && i+start < (int)songdata.size(); i++) {
		if ((lyrics[i] == " ") || (lyrics[i] == ".") || (lyrics[i] == "")) {
			if (songdata[i+start].pitch < 0) {
				lyrics[i] = "%";
			} else {
				lyrics[i] = "|";
			}
			// lyrics[i] = ".";
		}
		songdata[i+start].text = lyrics[i];
		songdata[i+start].lyricnum = line;
		if (line != songdata[i+start].phnum) {
			songdata[i+start].lyricerr = 1;   // lyric does not line up with music
		}
	}

	return true;
}