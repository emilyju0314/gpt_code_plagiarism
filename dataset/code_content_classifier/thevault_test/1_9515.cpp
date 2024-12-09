bool Tool_esac2hum::placeLyrics(vector<string>& song, vector<NoteData>& songdata) {
	int start = -1;
	int stop = -1;
	getLineRange(song, "TXT", start, stop);
	if (start < 0) {
		// no TXT[] field, so don't do anything
		return true;
	}
	int line = 0;
	vector<string> lyrics;
	string buffer;
	for (line=0; line<=stop-start; line++) {
		if (song[line+start].size() <= 4) {
			cerr << "Error: lyric line is too short!: "
				  << song[line+start] << endl;
			return false;
		}
		buffer = song[line+start].substr(4);
		if (line == stop - start) {
			auto loc = buffer.rfind(']');
			if (loc != string::npos) {
				buffer.resize(loc);
			}
		}
		if (buffer == "") {
			continue;
		}
		getLyrics(lyrics, buffer);
		cleanupLyrics(lyrics);
		placeLyricPhrase(songdata, lyrics, line);
	}

	return true;
}