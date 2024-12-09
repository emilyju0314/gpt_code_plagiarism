void printSlurData(HumdrumFile& infile) {
	// cout << "\nSLURS:\n";

	if (LegendQ) {
		cout << "\n";
		cout << "########################################################\n";
		cout << "## LIST OF SLURS                                      ##\n";
		cout << "##                                                    ##\n";
		cout << "## Meaning of columns:                                ##\n";
		cout << "## 1  SLUR:  Slur enumeration number.                 ##\n";
		cout << "## 2  BAR:   The measure that the slur is in.         ##\n";
		cout << "## 3  ABSQ:  The starting time in quarter notes from  ##\n";
		cout << "##           start of music.                          ##\n";
		cout << "## 4  SDUR:  the ending time in quarter notes from    ##\n";
		cout << "##           start of music.                          ##\n";
		cout << "## 5  MFRAC: Fractional position of the slur in bar.  ##\n";
		cout << "########################################################\n";
	}

	// Data column meanings:
	cout << "#SLUR";
	cout << "\tBAR";
	cout << "\tABSQ";
	cout << "\tSDUR";
	cout << "\tMFRAC";
	cout << "\n";

	vector<HTp> slurlist;
	getSlurList(slurlist, infile);

	for (int i=0; i<(int)slurlist.size(); i++) {
		HTp token = slurlist[i];

		// @@SLUR-#: The enumeration of the slur
		cout << "SLUR-" << (i+1);

		// @@BAR: The measure/bar number in which the pedal is locaed.
		cout << "\t" << Barnum[token->getLineIndex()];

		// @@ABSQ: the position in the score since the first barline
		HumNum start = getAbsBeat(token);
		cout << "\t" << start.getFloat();

		// @@SDUR: the duration to the slur end.  
		cout << "\t" << getSlurDuration(token, 0).getFloat();

		// @@MFRAC: the position in the score since the first barline
		cout << "\t" << getMeasureFraction(token).getFloat();

		cout << endl;
	}
}