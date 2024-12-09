void printNoteData(HumdrumFile& infile) {
	// cout << "NOTES:\n";

	vector<int> track2staff = getTrack2StaffMapping(infile);

	if (LegendQ) {
		cout << "\n";
		cout << "########################################################\n";
		cout << "## LIST OF NOTES                                      ##\n";
		cout << "##                                                    ##\n";
		cout << "## Meaning of columns:                                ##\n";
		cout << "## 1  NOTE : note enumeration number.                 ##\n";
		cout << "## 2  MIDI:  MIDI number number (60=middle C).        ##\n";
		cout << "## 3  STAFF: staff on which the note belongs.         ##\n";
		cout << "## 4  VOICE: voice number on staff:                   ##\n";
		cout << "##      0 = layer 1, but no other layers              ##\n";
		cout << "##      1 = layer 1 (highest layer on staff)          ##\n";
		cout << "##      2 = layer 2 (lowest layer on staff)           ##\n";
		cout << "##      3 = layer 3, etc.                             ##\n";
		cout << "## 5  START: the starting time in quarter notes from  ##\n";
		cout << "##         start of music.                            ##\n";
		cout << "## 6  END:   the ending time in quarter notes from    ##\n";
		cout << "##         start of music.                            ##\n";
		cout << "## 7  DUR:   The duration of the note in quarters.    ##\n";
		cout << "## 8  BAR:   The measure that the note is in.         ##\n";
		cout << "## 9  STAC:  Boolean for staccato on note.            ##\n";
		cout << "## 10 STAC:  Boolean for staccato on note.            ##\n";
		cout << "## 11 FERM:  Boolean for fermata on note.             ##\n";
		cout << "## 12 ACNT:  Boolean for accent on note.              ##\n";
		cout << "## 13 ACCID: Visual accidental:                       ##\n";
		cout << "##          0 = no accidental                         ##\n";
		cout << "##          1 = double flat                           ##\n";
		cout << "##          2 = double flat                           ##\n";
		cout << "##          3 = natural sign                          ##\n";
		cout << "##          4 = sharp                                 ##\n";
		cout << "##          5 = double sharp                          ##\n";
		cout << "########################################################\n";
	}

	cout << "#NOTE\t"    // Note number key number of note
	     << "MIDI\t"     // MIDI key number of note
	     << "STAFF\t"    // staff number of note
	     << "VOICE\t"    // voice/layer number of note (0 = layer 1 when no layer 2)
	     << "START\t"    // start time in quarter notes from start of music
	     << "END\t"      // end time in quarter notes from start of music
	     << "DUR\t"      // duration of note in quarter notes
	     << "BAR\t"     // measure number that the note is in
	     << "METER\t"    // duration from start of metric cycle in quarter notes
	     << "STAC\t"     // 1 = staccato, 0 = not staccato
	     << "FERM\t"     // 1 = fermata, 0 = no fermata
	     << "ACNT\t"     // 1 = accent/marcato, 0 = no accent
	     << "ACCID\t"    // Visual accidental 0=no accent, 1=double flat, 2=flat, 3=natural, 4=sharp, 5=double sharp
	     << endl;

	int notecounter = 0;
	int barnum = 0;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isBarline()) {
			HumRegex hre;
			HTp token = infile.token(i, 0);
			if (hre.search(token, "^=(\\d+)")) {
				barnum = hre.getMatchInt(1);
			}
		}
		if (!infile[i].isData()) {
			continue;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (!token->isKern()) {
				// ignore non-music
				continue;
			}
			if (token->isNull()) {
				// ignore empty placeholders
				continue;
			}
			if (token->isRest()) {
				// ignore rests
				continue;
			}
			int notecount = token->getSubtokenCount();
			for (int k=0; k<notecount; k++) {
				string subtoken = token->getSubtoken(k);
				if (subtoken.find("_") != string::npos) {
					// sustained note so skip
					continue;
				}
				if (subtoken.find("]") != string::npos) {
					// sustained note so skip
					continue;
				}
				int midi  = Convert::kernToMidiNoteNumber(subtoken);
				int track = token->getTrack();
				int staff = track2staff[track];
				int voice = token->getSubtrack();
				HumNum nstart = token->getDurationFromStart();
				HumNum dur    = token->getTiedDuration();
				HumNum nend   = nstart + dur;
				HumNum nmeter = token->getDurationFromBarline();
				int staccato = 0;
				if (hasStaccato(token)) {
					staccato = 1;
				}
				int accent = 0;
				if (hasAccent(token)) {
					accent = 1;
				}
				int fermata = 0;
				if (hasFermata(token)) {
					fermata = 1;
				}
				int accidental = hasVisualAccidental(token, k);
				notecounter++;

				cout << "NOTE-" << notecounter << "\t"     // NOTE
				     << midi << "\t"                       // MIDI
				     << staff << "\t"                      // STAFF
				     << voice << "\t"                      // VOICE
				     << nstart.getFloat() << "\t"          // START
				     << nend.getFloat() << "\t"            // END
				     << dur.getFloat() << "\t"             // DUR
				     << barnum << "\t"                     // BAR
				     << nmeter.getFloat() << "\t"          // METER
				     << staccato << "\t"                   // STAC
				     << fermata << "\t"                    // FERM
				     << accent << "\t"                     // ACNT
				     << accidental << "\t"                 // ACCID
				     << endl;
			}
		}
	}
}