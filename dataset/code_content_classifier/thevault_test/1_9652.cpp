bool Tool_autostem::autostem(HumdrumFile& infile) {
	vector<vector<int> > baseline;
	getClefInfo(baseline, infile);

	// get staff-line position of all notes:
	vector<vector<vector<int> > > notepos;
	getNotePositions(notepos, baseline, infile);
	if (noteposQ) {
		printNotePositions(infile, notepos);
		return true;
	}

	// get voice/layer number in track:
	vector<vector<int> > voice;
	getVoiceInfo(voice, infile);
	if (voiceQ) {
		printVoiceInfo(infile, voice);
		return true;
	}

	// get stem directions:
	vector<vector<int> > stemdir;
	bool status = assignStemDirections(stemdir, voice, notepos, infile);
	if (!status) {
		return false;
	}
	insertStems(infile, stemdir);
	return true;
}