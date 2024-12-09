bool Tool_esac2hum::getSong(vector<string>& song, istream& infile, int init) {
	static char holdbuffer[10000] = {0};

	song.resize(0);
	if (init) {
		// do nothing holdbuffer has the CUT[] information
	} else {
		strcpy(holdbuffer, "");
		while (!infile.eof() && strncmp(holdbuffer, "CUT[", 4) != 0) {
			infile.getline(holdbuffer, 256, '\n');
			if (verboseQ) {
				cerr << "Contents: " << holdbuffer << endl;
			}
			if (strncmp(holdbuffer, "!!", 2) == 0) {
				song.push_back(holdbuffer);
			}
		}
		if (infile.eof()) {
			return false;
		}
	}

	if (!infile.eof()) {
		song.push_back(holdbuffer);
	} else {
		return false;
	}

	infile.getline(holdbuffer, 256, '\n');
	chopExtraInfo(holdbuffer);
	inputline++;
	if (verboseQ) {
		cerr << "READ LINE: " << holdbuffer << endl;
	}
	while (!infile.eof() && strncmp(holdbuffer, "CUT[", 4) != 0) {
		song.push_back(holdbuffer);
		infile.getline(holdbuffer, 256, '\n');
		chopExtraInfo(holdbuffer);
		inputline++;
		if (verboseQ) {
			cerr << "READ ANOTHER LINE: " << holdbuffer << endl;
		}
	}

	return true;
}