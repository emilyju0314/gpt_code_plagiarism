void Tool_imitation::doAnalysis(vector<vector<string> >& results,
		NoteGrid& grid, vector<vector<NoteCell*> >& attacks,
		vector<vector<double>>& intervals, HumdrumFile& infile,
		bool debug) {

	results.resize(grid.getVoiceCount());
	for (int i=0; i<(int)results.size(); i++) {
		results.at(i).resize(infile.getLineCount());
	}

	attacks.resize(grid.getVoiceCount());
	for (int i=0; i<(int)attacks.size(); i++) {
		grid.getNoteAndRestAttacks(attacks.at(i), i);
	}

	intervals.resize(grid.getVoiceCount());
	for (int i=0; i<(int)intervals.size(); i++) {
		intervals.at(i).resize(attacks.at(i).size());
		getIntervals(intervals.at(i), attacks.at(i));
	}

	for (int i=0; i<(int)attacks.size(); i++) {
		for (int j=i+1; j<(int)attacks.size(); j++) {
			analyzeImitation(results, attacks, intervals, i, j);
		}
	}
}