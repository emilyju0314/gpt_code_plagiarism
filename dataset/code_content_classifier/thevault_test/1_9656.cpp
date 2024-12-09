void Tool_autostem::getBeamSegments(vector<vector<Coord> >& beamednotes,
		vector<vector<string > >& beamstates, HumdrumFile& infile,
		vector<int> maxlayer) {
	beamednotes.clear();
	beamednotes.reserve(10000);
	vector<vector<vector<Coord> > > beambuffer;
	beambuffer.resize(infile.getMaxTrack() + 1);
	int i, j;
	for (i=0; i<(int)beambuffer.size(); i++) {
		beambuffer[i].resize(10); // layer  max 10, all more later if needed
		for (j=0; j<(int)beambuffer[i].size(); j++) {
			beambuffer[i][j].reserve(1000);
		}
	}

	Coord tcoord;
	char beamchar;
	int track, oldtrack, layer;
	for (i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		oldtrack = 0;
		layer = 0;
		for (j=0; j<infile[i].getFieldCount(); j++) {
			if (!infile.token(i, j)->isKern()) {
				continue;
			}
			track = infile.token(i, j)->getTrack();
			if (track == oldtrack) {
				layer++;
			} else {
				layer = 0;
			}
			oldtrack = track;
			if (infile.token(i, j)->isNull()) {
				continue;
			}
			if (infile.token(i, j)->isRest()) {
				continue;
			}

			if (beamstates[i][j].empty()) {
				beambuffer[track][layer].resize(0);  // possible unter. beam
				continue;
			}
			beamchar = beamstates[i][j][0];

			if ((beamchar == '[') || (beamchar == '=')) {
				// add a beam to the buffer and wait for more
				tcoord.i = i;
				tcoord.j = j;
				beambuffer[track][layer].push_back(tcoord);
				continue;
			}
			if (beamchar == ']') {
				// ending of a beam so store in permanent storage
				tcoord.i = i;
				tcoord.j = j;
				beambuffer[track][layer].push_back(tcoord);
				beamednotes.push_back(beambuffer[track][layer]);
				beambuffer[track][layer].resize(0);
			}
		}
	}
}